//time_span.cpp
/*
Implementation of TimeSpan.h
By Tyler Ingram 
Date 1/15/2024
*/
#include "time_span.h"
#include <iostream>
#include <cmath>
using namespace std;

//constructors
TimeSpan::TimeSpan()
{
    hours_ = 0;
    minutes_ = 0;
    seconds_ = 0;
    total_seconds_ = 0;
}

TimeSpan::TimeSpan(double seconds)
{
    //convert seconds into hours, minutes,seconds
    ConvertTotalSeconds(seconds);
}

TimeSpan::TimeSpan(double minutes, double seconds)
{
    //converts all into seconds and then back into their fields
    double minutes_as_seconds = minutes * TimeSpan::kSeconds_Per_Minute;
    ConvertTotalSeconds(seconds + minutes_as_seconds);
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
    //convert hours and minutes into seconds and then pass to ConverTotalSeconds
    double hours_as_seconds = hours * TimeSpan::kSeconds_Per_Hour;
    double minutes_as_seconds = minutes * TimeSpan::kSeconds_Per_Minute;
    ConvertTotalSeconds(hours_as_seconds + minutes_as_seconds + seconds);
}

//getters and setters
int TimeSpan::hours()const
{
    return hours_;
}

int TimeSpan::minutes()const
{
    return minutes_;
}

int TimeSpan::seconds()const
{
    return seconds_;
}

int TimeSpan::total_seconds() const
{
    return total_seconds_;
}

void TimeSpan::set_time(int hours, int minutes, int seconds)
{
    hours_ = hours;
    minutes_ = minutes;
    seconds_ = seconds;
}

//overloaded operators
TimeSpan TimeSpan::operator+ (const TimeSpan& duration2) const
{
    TimeSpan result = *this;
    return result += duration2;
}

TimeSpan TimeSpan::operator- (const TimeSpan& duration2) const
{
    TimeSpan result = *this;
    return result-= duration2;
}

TimeSpan& TimeSpan::operator+= (const TimeSpan& duration2)
{
    //add the seconds then convert them and return the timespan
    ConvertTotalSeconds(total_seconds() + duration2.total_seconds());
    return *this;
}

TimeSpan& TimeSpan::operator-= (const TimeSpan& duration2)
{
    //subtract the seconds from one another then convert them
    ConvertTotalSeconds(total_seconds() - duration2.total_seconds());
    return *this;
}

//unary negation
TimeSpan TimeSpan::operator- ()
{
    ConvertTotalSeconds(total_seconds() * - 1);
    return *this;
}

//comparison operators
//all based on total seconds
bool TimeSpan::operator== (const TimeSpan& duration2) const
{
    return (total_seconds() == duration2.total_seconds());
}
bool TimeSpan::operator!= (const TimeSpan& duration2) const
{
    return !(*this == duration2);
}

bool TimeSpan::operator<= (const TimeSpan& duration2) const
{
    return (total_seconds() == duration2.total_seconds()) || 
    (total_seconds() < duration2.total_seconds());
}

bool TimeSpan::operator< (const TimeSpan& time2) const
{
   return (total_seconds() < time2.total_seconds());
}

bool TimeSpan::operator>= (const TimeSpan& duration2) const
{
    return (total_seconds() == duration2.total_seconds()) || 
    (total_seconds() > duration2.total_seconds());
}

bool TimeSpan::operator> (const TimeSpan& duration2) const
{
       return (total_seconds() > duration2.total_seconds());
}

//io operators
istream& operator>>(istream& stream,TimeSpan& duration)
{
    //take the first three value and then make a timespan object with them
    stream >> duration.hours_ >> duration.minutes_ >> duration.seconds_;
    return stream;
}

ostream& operator<<(ostream& stream,const TimeSpan& duration)
{
    //output format of 'Hours: <val>, "Minutes: <val>, Seconds: <val>'
    stream << "Hours: " << duration.hours() << ", Minutes: " << duration.minutes() << ", Seconds: " << duration.seconds();
    return stream;
}

//converts total seconds and assigns them to the hours,minutes, and seconds data members
void TimeSpan::ConvertTotalSeconds(double total_seconds) 
{
    int remaining_seconds = round(total_seconds);
    total_seconds_ = remaining_seconds;
    //gives hours as an int
    hours_ = remaining_seconds / TimeSpan::kSeconds_Per_Hour;
    //take remaining seconds after we take out the hours
    remaining_seconds %= TimeSpan::kSeconds_Per_Hour;
    minutes_ = remaining_seconds / TimeSpan::kSeconds_Per_Minute;
    //seconds left over after taking out minutes
    seconds_ = (remaining_seconds % TimeSpan::kSeconds_Per_Minute);
}
