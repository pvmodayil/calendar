/*
This file depends on the calendar.h -> calendar.cpp
*/
#include "calendar.h"
#include "event.h"
#include <iostream>



int main(int argc, char **argv){
   
   // initialize and receive the year
   std::vector<Event> events;
   unsigned int year;
   unsigned int choice;

   std::cout << "Enter the calendar year you wish to work with: " ; 
   std::cin >> year;
   displayCalendar(year);
   // Load existing events from file
   // code here events = loadEvents();

   // Menu
   bool wish_to_exit{false};
   while(!wish_to_exit){
      std::cout<<"Menu:\n";
      std::cout<<"1. Display Calendar\n";
      std::cout<<"2. Add Event\n";
      std::cout<<"3. Exit\n";

      std::cout<<"Enter your choice: ";
      std::cin >> choice;

      switch (choice){
         case 1:
            displayCalendar(year);
            break;
         case 2:
            createEvent(events);
            saveEvents(events);
            std::cout<<"Event was saved..."<<std::endl;
            break;
         case 3:
            wish_to_exit = true;
            break;
         default:
            char wisht_to_continue;
            std::cout<<"Invalid choice\nDo you wish to continue (y/n): ";
            std::cin>>wisht_to_continue;
            
            //"y" is seen as const char and there will be type mismatch
            if ((wisht_to_continue == 'y')||(wisht_to_continue == 'Y')) {
               break;
            }
            else{
               wish_to_exit = true;
            }
      }
   }
   
   return 0; 
}