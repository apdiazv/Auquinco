//
// DESCRIPTION QCDate:  Define a object date for compatibility with Excel
// QC-COMPLEMENTOS++
//
//  Created by Solange Becerra on 15-10-14.
//  
//

#ifndef _QC_BUSINESSDATE_
#define _QC_BUSINESSDATE_

class QCDate
{
private:
	int _day;
	int _month;
	int _year;
	int _serialDate;
	int _dayOfWeek; 

public:
	// Constructors
	QCDate(const QCDate& otherDate);
	QCDate(int excelSerialDate);
	QCDate(int day, int month, int year);
	QCDate(void);
	
	// Destructor
	~QCDate(void);

	//Methods
	int excelSerialDate() const; // returns a excel serial date
	int day() const; // return the day of a date
	int month() const; // return the month of a date
	int year() const; // return the year of a date
	int dayOfWeek(void) const; // return the day of the week (0...6)
	QCDate addDays(int days) const;  // add days to or subtract days from a date
	QCDate addMonths(int months) const; //add months to or subtract months from a date
	//QCDate addYears(int years);

	// operators
	QCDate& operator=(const QCDate& otherDate);// assignment
	QCDate operator+(const QCDate& date1) const;// binary +
	int operator-(const QCDate& date1) const;// binary -
	bool operator<(const QCDate& date1) const;// binary <
	bool operator>(const QCDate& date1) const;// binary >
	QCDate operator++(int);// post-increment operator ++

	friend QCDate getBussDay(const QCDate& date1);
	friend QCDate getPrevDay(const QCDate& date1);
	friend QCDate getShift(const QCDate& date1, int nStep);
	friend QCDate getLag(const QCDate& date1, int nStep);
	friend QCDate addMonthsUFCalendar(const QCDate& date1, int months);                                                  //addmonths to specific day
};

//Prototype signature of friends functions
QCDate getBussDay(const QCDate& date1); // adapt a date to a business date
QCDate getPrevDay(const QCDate& date1); // adapt a date to a previous business date
QCDate getShift(const QCDate& date1, int nStep); // add nStep to a date
QCDate getLag(const QCDate& date1, int nStep); // subtract nStep to a date
QCDate addMonthsUFCalendar(const QCDate& date1, int months); // add months to specific end day (9)
#endif
//QCDate operator-(const QCDate& date1) const;