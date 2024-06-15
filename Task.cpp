#include "Task.h"

#include <set>

Task::Task():priority(std::make_unique<int>(0)),status("Active") {}

std::string Task::GetDescription() {
    return description;
}
std::string Task::GetName() {
    return name;
}
int Task::GetPriority() {
    return *priority;
}
std::string Task::GetStatus() {
    return status;
}

Type Task::GetType() {
    return type;
}

Time Task::GetTime_start() {
    return time_start;
}

Time Task::GetTime_end() {
    return time_end;
}

void Task::SetDescription() {
    std::getline(std::cin, description);
}

void Task::SetName() {
    std::getline(std::cin, name);
}

void Task::SetPriority() {
    std::cin >> *priority;
}

void Task::SetStatus() {
    std::getline(std::cin, status);
}

void Task::SetType(Type &type) {
    this->type = type;
}

void Task::SetTime_start() {
    time_start.SetTime();
}


void Task::SetTime_end() {
    time_end.SetTime();
}

void Task::WriteToFile() {
    std::ofstream of("Tasks.txt",std::ios::app);
    of << name << std::endl;
    of << description << std::endl;
    of << *priority << std::endl;
    of << status << std::endl;
    of << type << std::endl;
    of << time_start << std::endl;
    of << time_end << std::endl;
}


void Task::ReadFromFile() {
    std::ifstream is("Tasks,txt");
    is >> name;
    is >> description;
    is >> *priority;
    is >> status;
    is >> type;
    is >> time_start;
    is >> time_end;
};


std::ostream &operator <<(std::ostream &os, Task &task) {
    os << task.name << std::endl;
    os << task.description << std::endl;
    os << *task.priority << std::endl;
    os << task.status << std::endl;
    os << task.type << std::endl;
    os << task.time_start << std::endl;
    os << task.time_end << std::endl;
    return os;
}

std::istream &operator >>(std::istream &is, Task &task) {
    is >> task.name;
    is >> task.description;
    is >> *task.priority;
    is >> task.status;
    is >> task.type;
    is >> task.time_start;
    is >> task.time_end;
    return is;
};



void Task::Create() {
    std::cout << "Enter name of the task:";
     SetName();
    std::cout << "Enter priority in range from 1 to 5:";
     SetPriority();
    // std::cout << "Enter descritpion: ";
    //  SetDescription();
    // std::cin.ignore();
    std::cout << "Enter start of the task:";
     SetTime_start();
    //std::cin.ignore();
    std::cout << "Enter end of the task:";
     SetTime_end();
    std::cout << std::endl;
}

void Task::DisplayTask() {
    std::cout << "Name:" << std::setw(5) <<"Description"<<std::endl;
    std::cout << name;
}


