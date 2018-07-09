// Days Between Dates Program by Leon Arndt
#include <iostream>
#include <string>

//determine whether given string only contains numbers
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool yearHasLeapDay(int year)
{
    return (year % 4 == 0);
}

int main()
{
  std::string startDate;
  std::string endDate;
  
  int startDay;
  int startMonth;
  int startYear;
  
  int endDay;
  int endMonth;
  int endYear;
  
  int daysBetweenDates;
  
  label:
  
  //get the start date
  std::cout << "Enter the Start Date (MM/DD/YYYY)";
  getline (std::cin, startDate);
  
  //check bad input start month
  if (!is_number(startDate.substr (0, 2).c_str()) || atoi(startDate.substr (0, 2).c_str()) > 12) 
  {
      std::cout << "Bad Start Month \n";
      goto label;
  }
  
  //check bad input start day
  if (!is_number(startDate.substr (3, 2).c_str()) || atoi(startDate.substr (3, 2).c_str()) > 31) 
  {
      std::cout << "Bad Start Day \n";
      goto label;
  }
  
    //check bad input start year
  if (!is_number(startDate.substr (6, 4).c_str())) 
  {
      std::cout << "Bad Start Year \n";
      goto label;
  }
  
  
  //get the end date
  std::cout << "Enter the End Date (MM/DD/YYYY)";
  getline (std::cin, endDate);
  
  //check bad input end month
  if (!is_number(endDate.substr (0, 2).c_str()) || atoi(endDate.substr (0, 2).c_str()) > 12) 
  {
      std::cout << "Bad End Month \n";
      goto label;
  }
  
  //check bad input end day
  if (!is_number(endDate.substr (3, 2).c_str()) || atoi(endDate.substr (3, 2).c_str()) > 31) 
  {
      std::cout << "Bad End Day \n";
      goto label;
  }
  
    //check bad input end year
  if (!is_number(endDate.substr (6, 4).c_str())) 
  {
      std::cout << "Bad End Year \n";
      goto label;
  }
  
  
  
  //determine start date values
  startMonth = atoi(startDate.substr (0, 2).c_str());
  startDay = atoi(startDate.substr (3, 2).c_str());
  startYear = atoi(startDate.substr (6, 4).c_str());
  
  //determine end date values
  endMonth = atoi(endDate.substr (0, 2).c_str());
  endDay = atoi(endDate.substr (3, 2).c_str());
  endYear = atoi(endDate.substr (6, 4).c_str());
  
  //calculate daysBetweenDates
  int monthsPassed = endMonth - startMonth;
  int daysPassed = endDay - startDay;
  int yearsPassed = endYear - startYear;
  
  daysBetweenDates = 365 * yearsPassed + 30 * monthsPassed + daysPassed;
  
  //extra day in a leap day
  for (int i = startYear; i < endYear; i++) {
      if (yearHasLeapDay(i))
      {
          daysBetweenDates++;
      }
  }
  
  
  //test output
  std::cout << "Start Month: " << startMonth << "\n";
  std::cout << "Start Day: " << startDay << "\n";
  std::cout << "Start Year: " << startYear << "\n";
  
  std::cout << "End Month: " << endMonth << "\n";
  std::cout << "End Day: " << endDay << "\n";
  std::cout << "End Year: " << endYear << "\n";
  
  std::cout << "Days Betwen Dates: " << daysBetweenDates << "\n";
}


