#ifndef TASKINTERFACE_H
#define TASKINTERFACE_H
#include"Task.h"
#include<list>

class TaskInterface {
public:
    virtual ~TaskInterface() = default;

    virtual void WriteToFile(Date &date,std::list<Task> &tasks) = 0;
    virtual std::list<Task> ReadFromFile(std::string &nameoffile) = 0;
    virtual void Create() = 0;

};



#endif
