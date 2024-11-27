#include "date.hpp"

int main() {

  std::cout << "Date object with default constructor (format 1):\n";
  Date date1 = Date();
  date1.printFormat1();
  
  std::cout << "\nDate object with constructor (format 2):\n";
  Date date2 = Date(27, 11, 2024);
  date2.printFormat2();

  std::cout << "\nDate set to 2/1/2025 (format 3):\n";
  date2.setDate(1, 2, 2025);
  date2.printFormat3();

  std::cout << "\nAttempt to set date to 13/45/2018:\n";
  date2.setDate(45, 13, 2018);
  date2.printFormat1();

  std::cout << "\nAttempt to set date to 4/31/2000:\n";
  date2.setDate(31, 4, 2000);
  date2.printFormat1();

  std::cout << "\nAttempt to set date to 2/29/2009:\n";
  date2.setDate(29, 2, 2009);
  date2.printFormat1();

  std::cout << "\nDifference between 4/10/2014 and 4/18/2003:\n";
  date1.setDate(18, 4, 2014);
  date2.setDate(10, 4, 2014);
  std::cout << (date1 - date2) << " day(s)\n";

  std::cout << "\nDifference between 2/2/2006 and 11/10/2003:\n";
  date1.setDate(2, 2, 2006);
  date2.setDate(10, 11, 2003);
  std::cout << (date1 - date2) << " day(s)\n";

  std::cout << "\nDate pre-decremented from 2/29/2008 (error in test plan answer?):\n";
  date2.setDate(29, 2, 2008);
  --date2;
  date2.printFormat1();

  std::cout << "\nDate pre-incremented from 2/28/2008:\n";
  ++date2;
  date2.printFormat1();

  std::cout << "\nDate post-decremented from 2/29/2008:\n";
  date2--;
  date2.printFormat1();

  std::cout << "\nDate post-incremented from 2/28/2008:\n";
  date2++;
  date2.printFormat1();

  std::cout << "\nDate post-incremented from 12/31/2024:\n";
  date2.setDate(31, 12, 2024);
  date2++;
  date2.printFormat1();

  std::cout << "\nDate post-decremented from 1/1/2025:\n";
  date2--;
  date2.printFormat1();

  std::cout << "\nDate pre-incremented from 12/31/2024:\n";
  ++date2;
  date2.printFormat1();

  std::cout << "\nDate pre-decremented from 1/1/2025:\n";
  --date2;
  date2.printFormat1();

  std::cout << "\nUse cin (>>) to read a date from keyboard:\n";
  std::cin >> date2;

  std::cout << "\nUse cout (<<) to display the date:\n";
  std::cout << date2 << std::endl;

  return 0;
}