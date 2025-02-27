#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <utility> // For std::pair

unsigned int getWeekDay(unsigned int year, unsigned int month = 1, unsigned int day = 1);
bool isLeapYear(unsigned int year);
std::pair<std::string, unsigned int> getMonthInfo(unsigned int month, bool leap_year);
void displayCalendar(unsigned int year);

#endif