
#include<cppinterface.h>
#include "QCDate.h"


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