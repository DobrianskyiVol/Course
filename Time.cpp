#include "Time.h"

Time::Time():year(0),month(0),day(0),hour(0),minute(0) {}


Time::Time(Time &&time) noexcept:
year(time.year),month(time.month),day(time.day),hour(time.hour),minute(time.minute){}

bool Time::ValidDate(int y, int m, int d) {
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

bool Time::ValidTime(int h, int min) {
    if (h < 0 || h > 23 || min < 0 || min > 59) {
        return false;
    }
    return true;
}

bool Time::ValidFuture(int y, int m, int d, int h, int min) {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    tm currentTime = *std::localtime(&t);

    // Compare year
    if (y < (currentTime.tm_year + 1900)) return false;
    if (y > (currentTime.tm_year + 1900)) return true;

    // Compare month
    if (m < (currentTime.tm_mon + 1)) return false;
    if (m > (currentTime.tm_mon + 1)) return true;

    // Compare day
    if (d < currentTime.tm_mday) return false;
    if (d > currentTime.tm_mday) return true;

    // Compare hour
    if (h < currentTime.tm_hour) return false;
    if (h > currentTime.tm_hour) return true;

    // Compare minute
    if (min <= currentTime.tm_min) return false;

    return true;
}

void Time::SetCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    tm localTime = *std::localtime(&t);

    year = localTime.tm_year + 1900;
    month = localTime.tm_mon + 1;
    day = localTime.tm_mday;
    hour = localTime.tm_hour;
    minute = localTime.tm_min;
}

void Time::SetTime() {
    std::cout << "Enter date and time (YYYY-MM-DD HH:MM): ";
    std::string input;
    std::getline(std::cin >> std::ws, input);  // Use getline to read the entire line

    std::stringstream ss(input);
    char dateDelimiter, timeDelimiter, space;

    ss >> year >> dateDelimiter >> month >> dateDelimiter >> day  >> hour >> timeDelimiter >> minute;

    if (!ValidDate(year, month, day) || !ValidTime(hour, minute)) {
        std::cerr << "Invalid date or time entered." << std::endl;
        year = month = day = hour = minute = 0;
    } else if (!ValidFuture(year, month, day, hour, minute)) {
        std::cerr << "Entered date and time has already passed." << std::endl;
        year = month = day = hour = minute = 0;
    } else {
        std::cout << "Date and time entered successfully." << std::endl;
    }
}

void Time::PrintTime() const {
    std::cout << "Date and Time: "
                  << std::setw(4) << std::setfill('0') << year << "-"
                  << std::setw(2) << std::setfill('0') << month << "-"
                  << std::setw(2) << std::setfill('0') << day << " "
                  << std::setw(2) << std::setfill('0') << hour << ":"
                  << std::setw(2) << std::setfill('0') << minute
                  << std::endl;
}

bool Time::operator==(Time &rhs) const {
    return year == rhs.year && month == rhs.month &&
               day == rhs.day && hour == rhs.hour &&
               minute == rhs.minute;
}

std::ostream &operator <<(std::ostream &os, Time &time) {
    os << time.year << "\n";
    os << time.month << "\n";
    os << time.day << "\n";
    os << time.hour << "\n";
    os << time.minute << "\n";
    return os;
};
std::istream &operator >>(std::istream &is, Time &time) {
    is >> time.year;
    is >> time.month;
    is >> time.day;
    is >> time.hour;
    is >> time.minute;
    return is;
};
