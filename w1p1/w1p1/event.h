/**********************************************************
 * Name: Dhruv Bipinbhai Patel
 * Student ID: 142572197
 * Workshop: Workshop 1 part 2
 * Seneca email: dbpatel31@myseneca.ca
 * Section: NEE
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/

#ifndef Event_h
#define Event_h
#include <stdio.h>

extern unsigned long g_sysClock;
namespace sdds
{
class Event
{
    char* description;
    unsigned long time;
    
public:
    Event(); 
    Event(const Event& x);
    ~Event();
    void display();
    void set(char *src);
    Event& operator=(const Event& y);
};
}
#endif
