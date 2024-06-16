#include "Date.h"

Date::Date():year(0),month(0),day(0) {}



bool Date::IsValidDate(int y, int m, int d) {
    if (y < 1900 || m < 1 || m > 12 || d < 1 || d > 31) {
        return false;
    }
    // Check for months with 30 days
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
        return false;
    }
    // Check for February
    if (m == 2) {
        bool isLeapYear = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if ((isLeapYear && d > 29) || (!isLeapYear && d > 28)) {
            return false;
        }
    }
    return true;
}

void Date::SetCurrentDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    tm localTime = *std::localtime(&t);

    year = localTime.tm_year + 1900;
    month = localTime.tm_mon + 1;
    day = localTime.tm_mday;
}

void Date::SetDate() {
    std::cout << "Enter date (YYYY-MM-DD): ";
    std::string input;
    std::getline(std::cin >> std::ws, input);  // Use getline to read the entire line

    std::stringstream ss(input);
    char dateDelimiter;

    ss >> year >> dateDelimiter >> month >> dateDelimiter >> day;

    if (!IsValidDate(year, month, day)) {
        std::cerr << "Invalid date or time entered." << std::endl;
        year = month = day =  0;
    } else {
        std::cout << "Date and time entered successfully." << std::endl;
    }
}

std::string Date::GetDate() const {
    std::string g_year = std::to_string(year);
    std::string g_month = (month < 10)? ( '0' + std::to_string(month)):std::to_string(month);
    std::string g_day = (day < 10)? ( '0' + std::to_string(day)):std::to_string(day);
    std::string date = g_year + '-' + g_month + '-' + g_day;
    return date;
}



bool Date::operator==(const Date &rhs) const {
    if (year == rhs.year)
        return true;

    if (month == rhs.month)
        return true;

    if (day == rhs.day)
        return true;

    return false;

}


bool Date::operator<(const Date &rhs) const{
    if (year < rhs.year)
        return true;
    if(year > rhs.year)
        return false;

    if (month < rhs.month)
        return true;
    if(month > rhs.month)
        return false;

    if (day < rhs.day)
        return true;
    if(year > rhs.day)
        return false;

    return false;
}

bool IsFuture(const Date &lhs,const Date &rhs) {
    return lhs < rhs;
}

bool IsNow(const Date &lhs,const Date &rhs) {
    return lhs == rhs;
}



