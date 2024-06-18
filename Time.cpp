#include "Time.h"

Time::Time():hour(0),minute(0) {}


Time::Time(Time &&time) noexcept:
hour(time.hour),minute(time.minute){}


bool Time::ValidTime(int h, int min) {
    if (h < 0 || h > 23 || min < 0 || min > 59) {
        return false;
    }
    return true;
}


void Time::SetCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    tm localTime = *std::localtime(&t);

    hour = localTime.tm_hour;
    minute = localTime.tm_min;
}

void Time::SetTime() {
    std::cout << "(HH:MM): ";
    std::string input;
    std::getline(std::cin >> std::ws, input);  // Use getline to read the entire line

    std::stringstream ss(input);
    char timeDelimiter;

    ss >>  hour >> timeDelimiter >> minute;

    if ( !ValidTime(hour, minute)) {
        std::cerr << "Invalid time entered." << std::endl;
        hour = minute = 0;
    } else {
        std::cout << "Time entered successfully." << std::endl;
    }
}

void Time::PrintTime() const {
    std::cout << "Time: "
                  << std::setw(2) << std::setfill('0') << hour << ":"
                  << std::setw(2) << std::setfill('0') << minute
                  << std::endl;
}

bool Time::operator==(Time &rhs) const {
    return  hour == rhs.hour &&
               minute == rhs.minute;
}

std::ostream &operator <<(std::ostream &os, Time &time) {
    os << time.hour << "\n";
    os << time.minute << "\n";
    return os;
};
std::istream &operator >>(std::istream &is, Time &time) {
    is >> time.hour;
    is >> time.minute;
    return is;
};

std::string Time::GetTime() {
    std::string hour_str = std::to_string(hour);
    std::string minute_str = std::to_string(minute);
    if (hour < 10) {
        hour_str = '0' + hour_str;
    }
    if (minute < 10) {
        minute_str = '0' + minute_str;
    }

    return (hour_str + ':' + minute_str);

}

