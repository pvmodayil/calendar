#include "event.h"
#include <iostream>
#include <string>
#include <vector>

Date stringToDate(){
    Date date;
    std::string date_string;
    
    // Get the date input from user
    std::cout<<"Please type the date in dd-mm-yyyy format: ";
    std::getline(std::cin >> std::ws, date_string);

    // Require 10 charcaters in total
    if (date_string.length() != 10){
        std::cout<<"Invalid date format"<<std::endl;
        return stringToDate();
    }

    // Split the string
    std::vector<std::string> tokens;
    unsigned char start{0}, end{date_string.find("-")}; // to get the substring out

    while (end != std::string::npos){
        tokens.push_back(date_string.substr(start, end-start));
        start = end + 1; // shift to the next character after delimeter
        end = date_string.find("-",start);
    }
    tokens.push_back(date_string.substr(start));

    // Convert to integers and store
    date.day = static_cast<unsigned char>(std::stoi(tokens[0]));
    date.month = static_cast<unsigned char>(std::stoi(tokens[1]));
    date.year = static_cast<unsigned int>(std::stoi(tokens[2]));

    return date;
}

void createEvent(std::vector<Event>& events){
    std::string event_title;
    std::string description;
    // Get date 
    Date date = stringToDate();

    // Ask for event title
    std::cout<<"Event Title: ";
    std::getline(std::cin>>std::ws, event_title);

    std::cout<<"Event Description (optional): ";
    std::getline(std::cin>>std::ws, description);

    Event new_event(event_title, date, description);
    events.push_back(new_event);
}