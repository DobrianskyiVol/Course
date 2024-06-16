#include "Task.h"

#include <set>

Task::Task():priority(std::make_unique<int>(0)),status("Active") {}

Task::Task(Task& task)
        : name(task.name),
          description(task.description),
          status(task.status),
          time_end(task.time_end),
          time_start(task.time_start),
          priority(std::make_unique<int>(*task.priority)),
        type(task.type){}

Task::Task(Task &&task) noexcept:name(std::move(task.name)),
          description(std::move(task.description)),
          status(std::move(task.status)),
          time_end(std::move(task.time_end)),
          time_start(std::move(task.time_start)),
          priority(std::move(task.priority)),
            type(std::move(task.type)) {

    task.name.clear();
    task.description.clear();
    task.status.clear();

}


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
    return std::move(type);
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
    os << task.name <<"\n";
    os << task.description<<"\n";
    os << *task.priority<<"\n";
    os << task.status<<"\n";
    os << task.type;
    os << task.time_start;
    os << task.time_end;
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
    std::cout << "Enter descritpion: ";
    std:getline(std::cin,description);
    std::cout << "Enter priority in range from 1 to 5:";
    SetPriority();
    //std::cin.ignore();
    std::cout << "Start at: ";
     SetTime_start();
    //std::cin.ignore();
    std::cout << "End at:";
     SetTime_end();
    std::cout << std::endl;
}




