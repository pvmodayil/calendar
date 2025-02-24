#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <iomanip>
#include <string>
#include <utility> // For std::pair

unsigned char getWeekDay(unsigned int year, unsigned char month = 1, unsigned char day = 1);
bool isLeapYear(unsigned int year);
std::pair<std::string, unsigned char> getMonthInfo(unsigned char month, bool leap_year);
void displayCalendar(unsigned int year);

#endif