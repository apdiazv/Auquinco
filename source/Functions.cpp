
#include "Functions.h"

bool IsBasis(std::string basis)
{
	if(basis == "act/360" || (basis == "act/365") || (basis == "30/360") || (basis == "act/act"))
	{
		return true;		
	}
	return false;
}

qcBasis stringToEnumDayCountConvention(std::string sBasis)
{
	if(sBasis == "act/360")
	{
		return act360;
	}
	else if(sBasis == "act/act")
	{
		return actAct;
	}
	else if(sBasis == "30/360")
	{
		return e30360;
	}
	else//(sBasis == "act/365")
	{
		return act365;
	}
}

double yearFraction(QCDate startDate, QCDate endDate, qcBasis basis)
{
	double result = 0;
	switch(basis)
	{
		case act365:
			result = (endDate - startDate) / (3.65 * 100);
			break;
		case act360:
			result = (endDate - startDate) / (3.6 * 100);
			break;
		case e30360:
			{
				int d1 = startDate.day();
				int d2 = endDate.day();
				int m1 = startDate.month();
				int m2 = endDate.month();
				int y1 = startDate.year();
				int y2 = endDate.year();

				if(d1 == 31) d1 = 30;
				if(d2 == 31 && d1 == 30) d2 = 30;
				result = ((d2 - d1) + 30 * (m2 - m1) + 360 * (y2 - y1)) / (3.6 * 100);
			}
			break;
		//case actAct:
		default:
			result = (endDate - startDate) / (3.65 * 100);
	}

	return result;
}

int yearFracActualActual(QCDate startDate, QCDate endDate)
{
	int result = 0;
	int d1 = startDate.day();
	int d2 = endDate.day();
	int m1 = startDate.month();
	int m2 = endDate.month();
	int y1 = startDate.year();
	int y2 = endDate.year();
	QCDate auxDate1;
	QCDate auxDate2;
	int auxYear1;
	int auxYear2;

	if(m2 > m1) 
	{
		auxDate1 = startDate.addMonths( (y2 - y1 ) * 12 );
	}
	else if(m2 < m1)
	{
		auxDate1 = startDate.addMonths( (y2 - y1 - 1 ) * 12 );
	}
	else if(d1 <= d2) 
	{
		auxDate1 = startDate.addMonths( (y2 - y1 ) * 12 );
	}
	else 
	{
		auxDate1 = startDate.addMonths( (y2 - y1 - 1 ) * 12 );
	}
	
	auxYear1 = auxDate1.year() - startDate.year();
	auxDate2 = auxDate1.addMonths(12);
	auxYear2 = (endDate.year() - auxDate1.year()) / (auxDate2.year() - auxDate1.year());
	result = auxYear1 + auxYear2;

	return result;
}

double roundingValue(double number)
{
	double result = 0;
	int integer;
	double mantisa;

	integer = (int) number;
	mantisa = number - integer;

	//if(mantisa >= 0 && mantisa < 0.25) result = 0
	if(mantisa >= 0.25 && mantisa < 0.75)
	{
		result = 0.5;
	}
	else if(mantisa >= 0.75)
	{
		result = 1;
	}
	result += integer;

	return result;
}

