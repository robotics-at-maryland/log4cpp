/*
 * LoggingEvent.cpp
 *
 * Copyright 2000, LifeLine Networks BV (www.lifeline.nl). All rights reserved.
 * Copyright 2000, Bastiaan Bakker. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */

#include "PortabilityImpl.hh"
#include <log4cpp/LoggingEvent.hh>
#include <log4cpp/threading/Threading.hh>

void setString(std::string* a, const std::string* b)
{
    *a = *b;
}

namespace log4cpp {
    
    LoggingEvent::LoggingEvent(const std::string& categoryName, 
                               const std::string& message,
                               const std::string& ndc, 
                               Priority::Value priority) :
        categoryName(categoryName),
        message(message),
        ndc(ndc),
        priority(priority),
        threadName(threading::getThreadId()) {
    }


    LoggingEvent::LoggingEvent(const LoggingEvent& other) :
        categoryName(other.categoryName),
        message(other.message),
        ndc(other.ndc),
        priority(other.priority),
        threadName(other.threadName),
        timeStamp(other.timeStamp)
    {
    }

    LoggingEvent& LoggingEvent::operator=(const LoggingEvent& other)
    {
        setString(const_cast<std::string*>(&categoryName),
                  &(other.categoryName));
        setString(const_cast<std::string*>(&message),
                  &(other.message));
        setString(const_cast<std::string*>(&ndc),
                  &(other.ndc));
        priority = other.priority;
        setString(const_cast<std::string*>(&threadName),
                  &(other.threadName));
        timeStamp = other.timeStamp;
    }
}
