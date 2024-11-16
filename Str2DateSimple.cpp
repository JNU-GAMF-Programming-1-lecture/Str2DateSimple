#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include <iostream>
#include <cstring>

bool str2date(const string& dateStr, int& day, int& month, int& year) 
{
  // Check if the input string is in the expected format.
  if (dateStr.length() != 10 || dateStr[2] != '-' || dateStr[5] != '-') 
  {
    return false; // Invalid format
  }

  // Extract day, month, and year using substr.
  string dayStr = dateStr.substr(0, 2);
  string monthStr = dateStr.substr(3, 2);
  string yearStr = dateStr.substr(6, 4);

  // Convert strings to integers using atoi.
  day = atoi(dayStr.c_str());
  month = atoi(monthStr.c_str());
  year = atoi(yearStr.c_str());

  // Check if the conversion resulted in valid values.
  if (day <= 0 || month <= 0 || year <= 0 || month > 12 || day > 31) 
  {
    return false; // Invalid date values.
  }

  return true; // Successfully parsed.
}

int main() 
{
  string s;
  int day, month, year;

  cout << "Enter a date (dd-mm-yyyy): ";
  getline(std::cin, s);

  if (str2date(s, day, month, year)) 
  {
    cout << "Date: " << day << "-" << month << "-" << year << endl;
  }
  else 
  {
    cout << "Invalid date!" << endl;
  }

  return 0;
}