/**********************************************************
 * Name: Dhruv Bipinbhai Patel
 * Student ID: 142572197
 * Workshop: Workshop 1 part 2
 * Seneca email: dbpatel31@myseneca.ca
 * Section: NEE
 **********************************************************/

/*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "event.h"
using namespace std;
unsigned long g_sysClock = 0;
namespace sdds {

Event::Event() {
    description = nullptr;
    time = 0;
}


Event::Event(const Event& x)
{
    if (x.description != nullptr && x.description[0] != '\0')
    {
        description = new char[strlen(x.description) + 1];
        strcpy(description, x.description);
        time = x.time;
    }
    else
    {
        description = nullptr;
        time = 0;
    }
}

Event::~Event() {
    delete[] description;
    description = nullptr;
}

void Event::display() {
    static int count = 1;
    long hh = 0, mm = 0, ss = 0;
    
    hh = time / 3600;
    mm = time / 60 % 60;
    ss = time % 60;
    
    if (description == nullptr) {
        cout << setw(2) << setfill(' ') << count << ". " << "| No Event |\n";
    }
    else {
        cout << setw(2) << setfill(' ') << count << ". " << setw(2) << setfill('0') << hh << ":" << setw(2)
        << setfill('0') << mm << ":" << setw(2) << setfill('0') << ss << " => " << description << "\n";
    }
    count++;
}

void Event::set(char* arr) {
    delete[] description;
    description = nullptr;
    if (arr != nullptr && arr[0] != '\0') {
        description = new char[strlen(arr) + 1];
        strcpy(description, arr);
        time = g_sysClock;
    }
    else {
        description = nullptr;
        time = 0;
    }
}


Event& Event::operator=(const Event& y)
{
    if (this != &y)
    {
        if (y.description != nullptr && y.description[0] != '\0')
        {
            description = new char[strlen(y.description) + 1];
            strcpy(description, y.description);
            time = y.time;
        }
        else
        {
            description = nullptr;
            time = 0;
        }
        
    }
    return *this;
}
}

