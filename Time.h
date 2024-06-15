#ifndef TIME_H
#define TIME_H

#include<iostream>
#include<chrono>
#include<iomanip>



class Time {
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;

    bool ValidDate(int y, int m, int d);
    bool ValidTime(int h, int min);
    bool ValidFuture(int y, int m, int d,int h, int min);

public:
    Time();
    Time(Time &time) = default;
    Time(Time &&time) noexcept;
    ~Time() = default;

    bool operator ==(Time &rhs) const;
    friend std::ostream &operator <<(std::ostream &os, Time &time);
    friend std::istream &operator >>(std::istream &is, Time &time);

    void SetCurrentTime();
    void SetTime();
    void PrintTime() const;
};



#endif //TIME_H
