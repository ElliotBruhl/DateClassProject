#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>
#include <string>

class Date {
private:
  int day;
  int month;
  int year;
  static int monthDays[12];
  static std::string monthNames[12];
  static int dateToDays(int d, int m, int y);

public:
  Date(); //pre: none. post: object created with default values (1/1/1930)
  Date(int, int, int); //pre date given is valid. post: object created with given values
  void setDate(int, int, int); //pre: date given is valid. post: date set to given values
  int getDay(); //pre: none. post: day returned
  int getMonth(); //pre: none. post: month returned
  int getYear(); //pre: none. post: year returned
  bool isLeapYear(int); //pre: none. post: returns true if leap year and false otherwise
  int getDaysInMonth(int, int); //pre: none. post: returns number of days in month (including leap year days)
  void printFormat1(); //pre: none. post: prints date in MM/DD/YYYY format
  void printFormat2(); //pre: none. post: prints date in Month DD, YYYY format
  void printFormat3(); //pre: none. post: prints date in DD Month YYYY format
  Date operator++(int); //for date++. pre: none. post: date advanced by one day (with overflows) and copy before increment returned
  Date& operator++(); //for ++date. pre: none. post: date advanced by one day (with overflows) and object after increment returned
  Date operator--(int); //for date--. pre: none. post: date advanced by one day (with underflows) and copy before decrement returned
  Date& operator--(); //for --date. pre: none. post: date advanced by one day (with underflows) and object after decrement returned
  int operator-(const Date&); //pre: none. post: returns number of days between two dates
  friend std::ostream& operator<<(std::ostream&, const Date&); //pre: none. post: prints date in Month DD, YYYY format
  friend void operator>>(std::istream&, Date&); //pre: date given is valid. post: sets day, month, and year to given values
};

#endif