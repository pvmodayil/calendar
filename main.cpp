/*
This file depends on the calendar.h -> calendar.cpp
*/
#include "calendar.h"
#include <iostream>



int main(int argc, char **argv){
   
   // initialize and receive the year
   unsigned int year;
   std::cout << "Enter the calendar year: " ; 
   std::cin >> year;
   
   displayCalendar(year);
   return 0; 
}