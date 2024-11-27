#include "date.hpp"

//helper funcs/arrays
int Date::monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
std::string Date::monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int Date::dateToDays(int d, int m, int y) {
  int total = 0;
  //days from years
  total += y * 365;
  //days from leap days
  total += (y / 4) - (y / 100) + (y / 400);
  if (((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) && m > 2) //for leap day in current year
    total++;
  //days from months
  for (int i = 1; i < m; i++) {
    total += Date::monthDays[i - 1];
  }
  //days from days
  total += (d - 1);

  return total;
}

Date::Date() {
  day = 1;
  month = 1;
  year = 1930;
}
Date::Date(int d, int m, int y) {
  if (d > 0 && d <= getDaysInMonth(m, y))
    day = d;
  else {
    std::cout << "Invalid day. Setting day to 1." << std::endl;
    day = 1;
  }
  if (m > 0 && m <= 12)
    month = m;
  else {
    std::cout << "Invalid month. Setting month to 1." << std::endl;
    month = 1;
  }
  if (y >= 0)
    year = y;
  else {
    std::cout << "Invalid year. Setting year to 1930." << std::endl;
    year = 1930;
  }
}
void Date::setDate(int d, int m, int y) {
  if (d > 0 && d <= getDaysInMonth(m, y))
    day = d;
  else
    std::cout << "Invalid day. Day not changed. " << std::endl;
  if (m > 0 && m <= 12)
    month = m;
  else
    std::cout << "Invalid month. Month not changed. " << std::endl;
  if (y >= 0)
    year = y;
  else
    std::cout << "Invalid year. Year not changed. " << std::endl;
}
int Date::getDay() {return day;}
int Date::getMonth() {return month;}
int Date::getYear() {return year;}
//leap year is divisible by 4 and not divisible by 100, or divisible by 400
bool Date::isLeapYear(int y) {
  return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}
int Date::getDaysInMonth(int m, int y) {
  if (m == 2 && isLeapYear(y))
    return 29;
  return monthDays[m - 1];
}
void Date::printFormat1() {
  std::cout << month << "/" << day << "/" << year << std::endl;
}
void Date::printFormat2() {
  std::cout << monthNames[month - 1] << " " << day << ", " << year << std::endl;
}
void Date::printFormat3() {
  std::cout << day << " " << monthNames[month - 1] << " " << year << std::endl;
}
//date++ and date--, return copy of date before (in/dec)rement
Date Date::operator++(int) {
  Date temp = *this;
  if (day == getDaysInMonth(month, year)) {
    if (month == 12) {
      year++;
      month = 1;
      day = 1;
    }
    else {
      month++;
      day = 1;
    }
  }
  else
    day++;
  
  return temp;
}
Date Date::operator--(int) {
  Date temp = *this;
  if (day == 1) {
    if (month == 1) {
      year--;
      month = 12;
      day = 31;
    }
    else {
      month--;
      day = getDaysInMonth(month, year);
    }
  }
  else
    day--;

  return temp;
}
//++date and --date, return updated version after (in/dec)rement
Date& Date::operator++() {
    if (day == getDaysInMonth(month, year)) {
        if (month == 12) {
            year++;
            month = 1;
            day = 1;
        } else {
            month++;
            day = 1;
        }
    } else {
        day++;
    }
    return *this;
}
Date& Date::operator--() {
    if (day == 1) {
        if (month == 1) {
            year--;
            month = 12;
            day = 31;
        } else {
            month--;
            day = getDaysInMonth(month, year);
        }
    } else {
        day--;
    }
    return *this;
}
int Date::operator-(const Date& d) {
  return dateToDays(day, month, year) - dateToDays(d.day, d.month, d.year);
}
std::ostream& operator<<(std::ostream& out, const Date& d) {
  out << d.monthNames[d.month - 1] << " " << d.day << ", " << d.year;
  return out;
}
void operator>>(std::istream& in, Date& date) {
  int d, m, y;
  std::cout << "Enter the day.\n";
  in >> d;
  std::cout << "Enter the month.\n";
  in >> m;
  std::cout << "Enter the year.\n";
  in >> y;
  date.setDate(d, m, y);
}