#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <vector>

struct Date {
    unsigned char day;
    unsigned char month;
    unsigned int year;

    Date(unsigned int y = 0, unsigned char m = 0, unsigned char d = 0) : day(d), month(m), year(y) {}
};

struct Event{
    Date date;
    std::string event_title;
    std::string description;

    Event(Date d, std::string t, std::string desc = "") : date(d), event_title(t), description(desc) {}
};

Date stringToDate();
void createEvent(std::vector<Event>& events);
void saveEvents(const std::vector<Event>& events);

#endif // EVENT_H