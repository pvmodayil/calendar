#include "display.h" // if any of the definitions below is already present in this header file, then it wont be redefined(including imports)
#include <iostream>
#include <iomanip>
#include <string>
#include <utility> // For std::pair

/**
 * @brief Calculates the weekday of the first day of the given year
 * @param day Day
 * @param month month
 * @param year Calendar year
 * @return Returns a value from 1 to 7 Where 1 is Sunday 7 is Saturday
 */
unsigned int getWeekDay(unsigned int year, unsigned int month , unsigned int day){
    // Following Zeller's Congruence Algorithm
 
    // If the month is Jan or Feb
    if (month < 3){
       month += 12;
       year --;
    }
 
    unsigned int century = year/100;
    unsigned int year_in_century = year%100;
 
    unsigned int weekday = (day + (13 * (month + 1)) / 5 + year_in_century + (year_in_century / 4) + (century / 4) - (2 * century)) % 7;
 
    // Adjusting the value to be from 1 to 7
    return ((weekday + 6) % 7) + 1;
}
 
 /**
 * @brief Checks if the given year is a leap year
 * @param year Calendar year
 * @return Returns a boolean
 */
 bool isLeapYear(unsigned int year){
    // if divisible by 4  and not by 100 (if by 100 it should also be divisible by 400)
    return (year%4 == 0) && (year%100 != 0 || year%400 == 0);
}
 
 /**
 * @brief Outputs month name and number of days in the month
 * @param month month
 * @param leap_year whether leap year
 * @return Returns a pair with month name, number of days
 */
 std::pair<std::string, unsigned int> getMonthInfo(unsigned int month, bool leap_year) {
 
    switch (month) {
        case 1:
          return{"January",31};
        case 2:
          if (leap_year){
             return {"February",29};
          }
          return{"February",28};;
        case 3:
          return{"March",31};;
        case 4:
          return{"April",30};;
        case 5:
          return{"May",31};;
        case 6:
          return{"June",30};;
        case 7:
          return{"July",31};;
        case 8:
          return{"August",31};;
        case 9:
          return{"September",30};;
        case 10:
          return{"October",31};;
        case 11:
          return{"November",30}; 
       case 12: 
          return{"December",31}; 
       default: 
          return{"Invalid Month",0}; // Handle invalid input
    }
 
}

/**
 * @brief Display the calendar
 * @param year Calendar year
 * @return Nothing
 */
 void displayCalendar(unsigned int year){
    // default values for month and day are being used: 01 Jan
    unsigned int starting_weekday = getWeekDay(year);
    bool leap_year = isLeapYear(year);
    unsigned int day_counter;
    
    std::string month_name;
    unsigned int number_of_days;
 
    // display constants
    const unsigned int date_width{6};
 
    // print the calendar
    std::cout<<std::setw(date_width)<<"***********************************"<<std::endl;
    std::cout<<std::setw(date_width)<<"\tCALENDAR "<<year<<std::endl;
    std::cout<<std::setw(date_width)<<"***********************************"<<std::endl;
    for (unsigned int month : {1,2,3,4,5,6,7,8,9,10,11,12}){
       std::pair<std::string, unsigned int> result = getMonthInfo(month, leap_year); // Get the result as a pair
       
       // Use std::tie to unpack without dot indexing
       std::tie(month_name, number_of_days) = result;
 
       std::cout<<"\t"<<month_name<<std::endl;
       std::cout<<std::setw(date_width)<<"===================================="<<std::endl;
       //Print day header. Make sure each date takes up date_width characters
       std::cout<< std::setw(date_width) << "Sun"
       << std::setw(date_width) << "Mon"
       << std::setw(date_width) << "Tue"
       << std::setw(date_width) << "Wed"
       << std::setw(date_width) << "Thu"
       << std::setw(date_width) << "Fri"
       << std::setw(date_width) << "Sat" << std::endl;
 
       //Print empty day slots in calendar
       for(unsigned int j{1};j < starting_weekday; j++){
          std::cout << std::setw(date_width) <<  ""; 
       }
 
       //Print actual days
       day_counter = starting_weekday;
       for(unsigned int day{1}; day <= number_of_days; day++ ){
          std::cout << std::setw(date_width) << static_cast<unsigned int>(day);
          day_counter++;
 
          if (day_counter > 7){
             std::cout<<std::endl;
             day_counter = 1;
          }
 
       }
       // set up the start day for the next month
       starting_weekday = day_counter; //day counter was incremented before loop ended so this is right
 
       // new line
       std::cout<<"\n\n";
 
    }
}
 