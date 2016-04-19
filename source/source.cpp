
#include <cppinterface.h>

#include "QCDate.h"
#include "Functions.h"


#pragma warning (disable : 4996)


short // echoes a short
EchoShort(short x // number to be echoed
           )
{
    return x;
}


int // echoes a int
EchoInt(int x // number to be echoed
           )
{
    return x;
}

unsigned long // echoes a unsigned long
EchoUnsLong(unsigned long x // number to be echoed
			)
{
    return x;
}

int // echoes a string
EchoStringInt(std::wstring data // data to be echoed
			)
{
    return data.size();
}

int // Ajusta a habil siguiente. Si se cambia mes entonces ajusta al habil anterior. (si la fecha ingresada es habil entonces devuelve tal fecha)
QCBussDay(int date // Fecha
		)
{
	if(date > 0)
	{
		QCDate newDate(date);
		return getBussDay(newDate).excelSerialDate();
	}

	return date;
}

int //Si la fecha ingresada no es habil, la ajusta a habil anterior
QCPrevDay(int  date // Fecha
		)
{
	if(date > 0)
	{
		QCDate newDate(date);
		return getPrevDay(newDate).excelSerialDate();
	}

	return date;
}

int // Agrega n dias habiles a una fecha dada. La opcion 0 agrega un dia habil si fecha ingresada es inhabil.
QCShift(int  date // Fecha
	  , int nStep // Numero de dias habiles
		)

{
	if(date > 0 && nStep >=0 )
	{
		QCDate newDate(date);
		return getShift(newDate, nStep).excelSerialDate();
	}

	return date;
}

int // Quita n dias habiles a una fecha dada. La opcion 0 quita un dia habil si fecha ingresada es inhabil
QCLag(int  date // Fecha
	, int nStep // Numero de dias habiles
	)
{
	if(date > 0 && nStep >=0 )
	{
		QCDate newDate(date);
		return getLag(newDate, nStep).excelSerialDate();
	}

	return date;
}

double // Calcula tiempo en años entre dos fechas utilizando base especificada
QCYearFraction(int startDate // Fecha inicio
			 , int endDate // Fecha fin
			 , std::string basis // base: Act/365, act/360 o 30/360 (por defecto act/365)
			 )
{
	if(startDate > 0 && endDate > 0 )
	{
		std::transform(basis.begin(), basis.end(), basis.begin(), ::tolower);
		qcBasis _basis = IsBasis(basis)? stringToEnumDayCountConvention(basis):act365;
		
		QCDate date1(startDate); 
		QCDate date2(endDate);

		return yearFraction(date1, date2, _basis);
	}

		return 0.0;
}

int // Calcula tiempo en años entre dos fechas utilizando base act/act
QCYearFracActualActual(int startDate // Fecha inicio
						 , int endDate // Fecha fin
						 )
{
	if(startDate > 0 && endDate > 0 )
	{
		QCDate date1(startDate); 
		QCDate date2(endDate);

		return yearFracActualActual(date1, date2);
	}
	return 0;
}

double // Si parte decimal de n es menor que 0.25 devuelve n, si es mayor o igual a 0.25 y menor que 0.75 devuelve (n + 0.5) y si es mayor que 0.75 devuelve (n+1) 
QCRedondeoParcial(double number // numero
                 )
{
	return roundingValue(number);
}


int // Agrega o quita meses a una fecha dada
QCAddMonths(int startDate // Fecha inicial
		  , int months // Numero de meses a agregar o quitar
		  )
{
	if(startDate > 0)
	{
		QCDate date(startDate);
		return date.addMonths(months).excelSerialDate();
	}

	return startDate;
}

int // Agrega o quita meses a una fecha dada. Fecha final es dia 9 del mes
QCAddMonthsC(int startDate // Fecha inicial
		  , int months // Numero de meses a agregar o quitar
		  )
{
	if(startDate > 0)
	{
		QCDate date(startDate);
		return addMonthsUFCalendar(date, months).excelSerialDate();
	}

	return startDate;
}