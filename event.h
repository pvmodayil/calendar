#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <vector>

struct Date {
    unsigned int year;
    unsigned char month;
    unsigned char day;
    Date(unsigned int y = 0, unsigned char m = 0, unsigned char d = 0) : year(y), month(m), day(d) {}
};

struct Event{
    std::string event_title;
    Date date;
    std::string description;

    Event(std::string t, Date d, std::string desc = "") : event_title(t), date(d), description(desc) {}
};

Date stringToDate();
void createEvent(std::vector<Event>& events);

#endif // EVENT_H