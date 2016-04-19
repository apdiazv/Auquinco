//
//
//                                                                    COMPLEMENTOS++.h
//

#ifndef QC_COMPLEMENTOS_H
#define QC_COMPLEMENTOS_H

#include "xlw/MyContainers.h"
#include <xlw/CellMatrix.h>
#include <xlw/DoubleOrNothing.h>
#include <xlw/ArgList.h>

using namespace xlw;

//<xlw:libraryname=MyComplementosLibrary


short // echoes a short
EchoShort(short x // number to be echoed
       );

int // echoes a int
EchoInt(int x // number to be echoed
           );

unsigned long // echoes a unsigned long
EchoUnsLong(unsigned long x // number to be echoed
			);

int // echoes a string
EchoStringInt(std::wstring data // data to be echoed
			);

int // Ajusta a habil siguiente. Si se cambia mes entonces ajusta al habil anterior. (si la fecha ingresada es habil entonces devuelve tal fecha)
QCBussDay(int date // Fecha inical
		);

int //Si la fecha ingresada no es habil, la ajusta a habil anterior
QCPrevDay(int  date // Fecha inicial
		);

int // Agrega n dias habiles a una fecha dada. La opcion 0 agrega un dia habil si fecha ingresada es inhabil.
QCShift(int  date // Fecha inicial
	  , int nStep // Numero de dias habiles
		);

int // Quita n dias habiles a una fecha dada. La opcion 0 quita un dia habil si fecha ingresada es inhabil
QCLag(int  date // Fecha
	, int nStep // Numero de dias habiles
	);

double // Calcula tiempo en años entre dos fechas utilizando base especificada
QCYearFraction(int startDate // Fecha inicio
			 , int endDate // Fecha fin
			 , std::string basis // base: Act/365, act/360 o 30/360 (por defecto act/365)
			 );

int // Calcula tiempo en años entre dos fechas utilizando base act/act
QCYearFracActualActual(int startDate // Fecha inicio
					 , int endDate // Fecha fin
					 );

double // Si parte decimal de n es menor que 0.25 devuelve n, si es mayor o igual a 0.25 y menor que 0.75 devuelve (n + 0.5) y si es mayor que 0.75 devuelve (n+1) 
QCRedondeoParcial(double number // numero
                 );

int // Agrega o quita meses a una fecha dada
QCAddMonths(int startDate // Fecha inicial
		  , int months // Numero de meses a agregar o quitar
		  );

int // Agrega o quita meses a una fecha dada. Fecha final es dia 9 del mes
QCAddMonthsC(int startDate // Fecha inicial
		  , int months // Numero de meses a agregar o quitar
		  );


#endif
