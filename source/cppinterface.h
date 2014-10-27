//
//
//                                                                    Test.h
//

#ifndef TEST_H
#define TEST_H

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


#endif
