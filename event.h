#ifndef EVENT_H
#define EVENT_H

#include "uuid.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>

struct Date {
    unsigned char day;
    unsigned char month;
    unsigned int year;

    Date(unsigned int y = 0, unsigned char m = 0, unsigned char d = 0) : day(d), month(m), year(y) {}
};

struct Event{
    std::string uuid;
    Date date;
    std::string event_title;
    std::string description;

    Event(std::string id, Date d, std::string t, std::string desc = "") : uuid(id), date(d), event_title(t), description(desc) {}
};

std::vector<std::string> splitString(std::string line, std::string delimeter);
Date stringToDate();
void createEvent(std::vector<Event>& events);
void saveEvents(const std::vector<Event>& events);
bool eventExists(const Event& new_event, const std::vector<Event>& loaded_events);
std::pair<std::vector<Event>,bool> loadEvents();

#endif // EVENT_H