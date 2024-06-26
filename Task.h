#ifndef TASK_H
#define TASK_H
#include<memory>
#include<iostream>
#include<fstream>
#include<iomanip>
#include "Time.h"
#include"Type.h"

class Task{
private:
    std::unique_ptr<int> priority;
    std::string name;
    std::string description;
    std::string status;
    Type type;
    Time time_start;
    Time time_end;
public:
    //Default constructor
    Task();
    //Default destructor
    ~Task() = default;
    //Copy constructor
    Task(Task &task);
    //Move constructor
    Task(Task &&task) noexcept;
//Set value
    void SetPriority();
    void SetName();
    void SetDescription();
    void SetStatus();
    void SetType(Type &type);
    void SetTime_start();
    void SetTime_end();
//Get value
    int GetPriority();
    std::string GetName();
    std::string GetDescription();
    std::string GetStatus();
    Type GetType();
    Time GetTime_start();
    Time GetTime_end();

//Overridden methods from Interface
    void WriteToFile() ;
    void ReadFromFile() ;
   // void Edit() override;
    void Create() ;


//Overloaded operators
    friend  std::ostream &operator <<(std::ostream &os, Task &task);
    friend std::istream &operator >>(std::istream &is, Task &task);
};



#endif
