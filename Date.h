#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<chrono>
#include<sstream>

class Date {
private:
    int year;
    int month;
    int day;

    static bool IsValidDate(int y, int m, int d);
public:
    Date();
    ~Date() = default;

    Date(Date &date) = default;
    Date(Date &&date) = default;

    void SetCurrentDate();
    void SetDate();

    [[nodiscard]] std::string GetDate() const;

    bool operator <(const Date &rhs) const;
    bool operator ==(const Date &rhs) const;

    friend bool IsFuture(const Date &lhs,const Date &rhs);
    friend bool IsNow(const Date &lhs, Date &rhs);

};



#endif //DATE_H
