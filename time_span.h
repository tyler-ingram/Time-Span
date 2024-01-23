//time_span.h
/*
This class represents a duration of time in hours, minutes and seconds. Time is rounded to the 
nearest second. There are also add, and subtract, as well as comparison and io operators.
By Tyler Ingram
*/
#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <string>
#include <iostream>
using namespace std;

class TimeSpan
{
    public:
        const int kSeconds_Per_Hour = 3600;
        const int kSeconds_Per_Minute = 60;
        TimeSpan();
        TimeSpan(double seconds);
        TimeSpan(double minutes, double seconds);
        TimeSpan(double hours, double minutes, double seconds);
        //getters and setters
        int hours()const;
        int minutes()const;
        int seconds()const;
        int total_seconds() const;
        void set_time(int hours, int minutes, int seconds);
        //overloaded operators
        TimeSpan operator+ (const TimeSpan& duration2) const;
        TimeSpan operator- (const TimeSpan& duration2) const;
        TimeSpan& operator+= (const TimeSpan& duration2);
        TimeSpan& operator-= (const TimeSpan& duration2);
        //unary negation
        TimeSpan operator- ();
        //comparison operators
        bool operator== (const TimeSpan& rhs) const;
        bool operator!= (const TimeSpan& rhs) const;
        bool operator<= (const TimeSpan& rhs) const;
        bool operator< (const TimeSpan& rhs) const;
        bool operator>= (const TimeSpan& rhs) const;
        bool operator> (const TimeSpan& rhs) const;
        //io operators
        friend ostream& operator<<(ostream& stream, const TimeSpan& duration);
        friend istream& operator>>(istream& stream,TimeSpan& time);

    private:
        double total_seconds_;
        double hours_;
        double minutes_;
        double seconds_;
        void ConvertTotalSeconds(double total_seconds); 
};
#endif