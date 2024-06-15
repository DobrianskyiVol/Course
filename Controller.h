#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <iomanip>
#include"Time.h"
#include<thread>
#include"Type.h"
#include<map>

#include "Task.h"
class Controller {
public:
    std::map<int,Type> types{
       {Type::id,Type{"Home"}},
        {Type::id,Type("Work")},
         {Type::id,Type("Meeting")},
        {Type::id,Type("Other")}
    };

    void index() {
        // Task task;
        // task.SetType(types.at(1));
        // //task.Create();
        // task.SetName();
        // task.DisplayTask();
        Time time;
        time.PrintTime();
    }
};


#endif
