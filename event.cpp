#include "event.h"
#include "uuid.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

std::vector<std::string> splitString(std::string line, std::string delimeter){
    // Split the string
    std::vector<std::string> tokens;
    size_t start{0}, end{line.find(delimeter)}; // to get the substring out .find() returns size_t
    // always good practice to declare position variables of iterables as size_t

    while (end != std::string::npos){
        tokens.push_back(line.substr(start, end-start));
        start = end + 1; // shift to the next character after delimeter
        end = line.find(delimeter,start);
    }
    tokens.push_back(line.substr(start));

    return tokens;
}

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

    // split the string
    std::vector<std::string> tokens = splitString(date_string,"-");
    
    // Convert to integers and store
    date.day = static_cast<unsigned int>(std::stoi(tokens[0]));
    date.month = static_cast<unsigned int>(std::stoi(tokens[1]));
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

    // generate unique identifier for the created event
    std::string uuid = uuid::generate_uuid();

    // create event struct
    Event new_event(uuid,date,event_title,description);
    events.push_back(new_event);
}

bool eventExists(const Event& new_event, const std::vector<Event>& loaded_events) {
    for (const auto& old_event : loaded_events) {
        std::cout << "Comparing with existing Event: Title=" 
                  << old_event.event_title 
                  << ", Day=" 
                  << old_event.date.day
                  << ", Month=" 
                  << old_event.date.month
                  << ", Year=" 
                  << old_event.date.year 
                  << "\n";

        if (old_event.event_title == new_event.event_title && 
            old_event.date.day == new_event.date.day && 
            old_event.date.month == new_event.date.month &&
            old_event.date.year == new_event.date.year) {
            return true; // Duplicate found
        }
    }
    return false; // No duplicate found
}

void saveEvents(const std::vector<Event>& events){
    // Check existence of the output file and load events
    std::vector<Event> loaded_events;
    bool file_exist;
    std::pair<std::vector<Event>,bool> result = loadEvents();
    std::tie(loaded_events, file_exist) = result;
    

    // Create or open file in append mode
    std::ofstream out_file("events.csv",std::ios_base::app);
    

    // If current write position is zero i.e, nothing written
    if (!file_exist){
        // Write the header
        out_file << "UUID,Day,Month,Year,Title,Description\n";
    }

    // Write the events into the file
    
    auto last_added_event = events.back();
    if (!eventExists(last_added_event,loaded_events)){
            out_file << last_added_event.uuid << ","
                << last_added_event.date.day << ","
                << last_added_event.date.month << ","
                << last_added_event.date.year << ","
                << last_added_event.event_title << ","
                << last_added_event.description << "\n";
            
            std::cout<<"Event was saved..."<<std::endl;
    }
    else{
        std::cout<<"This event already exists!"<<std::endl;
    }
        
    

    // Close the file
    out_file.close();
}

std::pair<std::vector<Event>,bool> loadEvents(){
    std::vector<Event> loaded_events;
    // read from file
    std::ifstream saved_file("events.csv");
    bool file_exist = saved_file.good(); // Sets false if some error flags are set

    if (saved_file.is_open()){
        std::string line_in_file;
        getline(saved_file,line_in_file); // Doing it once to get header so that next step onwards header is not considered

        while (getline(saved_file,line_in_file)){
            // Split the line
            std::vector<std::string> tokens = splitString(line_in_file,",");
            // Directly pushes the object to the container
            loaded_events.emplace_back(tokens[0], // uuid
                                    Date{
                                        static_cast<unsigned int>(std::strtol(tokens[3].c_str(), nullptr, 10)), // year
                                        static_cast<unsigned int>(std::strtol(tokens[2].c_str(), nullptr, 10)), // month
                                        static_cast<unsigned int>(std::strtol(tokens[1].c_str(), nullptr, 10)) // day
                                    },
                                    tokens[4], // title
                                    tokens[5] // description
                                );

            
        }
        saved_file.close();
    }
    return {loaded_events, file_exist};
}