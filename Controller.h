#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <iomanip>
#include"Time.h"
#include<thread>
#include"Type.h"
#include<map>
#include "tabulate\single_include\tabulate\tabulate.hpp"
#include "Task.h"
#include<list>
#include <cstdlib>
#include "Date.h"
#include "TaskInterface.h"
#include<fstream>

using namespace tabulate;



class Controller:TaskInterface {
public:
    ~Controller() override = default;

    std::map<const int,Type> types{
       {Type::id,Type{"Home"}},
        {Type::id,Type("Work")},
         {Type::id,Type("Meeting")},
        {Type::id,Type("Other")}
    };

    void WriteToFile(Date &date, std::list<Task> &tasks) override {
        std::string nameoffile = ("day" + '/' +  date.GetDate() + ".txt");
        std::ofstream of(nameoffile);
        if (!of) {
            std::cerr << "Error opening file: " << nameoffile << std::endl;
            return;
        }
        std::for_each(tasks.begin(),tasks.end(),[&of](Task &task) {
            of << task;
        });
        of.close();
    };

     std::list<Task> ReadFromFile(std::string &nameoffile) override {
     std::list<Task> tasks;
     std::ifstream of(nameoffile);
     if (!of) {
         std::cerr << "Error opening file: " << nameoffile << std::endl;
         return tasks;
     }
     std::for_each(tasks.begin(),tasks.end(),[&of](Task &task) {
         of >> task;
     });
     return tasks;
 };

    void chooseType(Task &task) {
        Table table;
        //task.Create();

        table.add_row({"Id: ","Type: "});
        for (int i = 0; i < 2; i++) {
            table[0][i].format().font_color(Color::yellow).font_style({FontStyle::bold});
        }
        for (auto type:types) {
            table.add_row({std::to_string(type.first), type.second.getType()});
        }
        std::cout << table << std::endl;;
        std::cout << "Choose type id to set the Type of the task\n";
        int n;
        while (true) {

            std::cin >> n;
            if (n > 4 or n < 0) {
                std::cerr << "Out of range ";
                std::cout << "Be more careful;)\n";
                continue;
            }

            break;
        }
        task.SetType(types.at(n));
    }

    void Create() override {

    };

    void Edit(std::list<Task> &tasks) {
        std::string NameToFind;
        std::getline(std::cin,NameToFind);


        auto TaskToChange =
            std::find_if(tasks.begin(), tasks.end(), [&](Task& task) {
            return task.GetName() == NameToFind;
        });

        if (TaskToChange != tasks.end()) {
            int n;
            std::cout << "Current name: " << TaskToChange->GetName();
            std::cout << "Press 1 if you want to change it. Otherwise press any other number ";
            std::cin >> n;
            if (n == 1) {
                std::cout << "Set new name: ";
                TaskToChange->SetName();
                n = 0;
            }

            std::cout << "Current description: " << TaskToChange->GetDescription();
            std::cout << "Press 1 if you want to change it. Otherwise press any other number ";
            std::cin >> n;
            if (n == 1) {
                std::cout << "Set new description: ";
                TaskToChange->SetDescription();
                n = 0;
            }

            std::cout << "Current priority: " << TaskToChange->GetPriority();
            std::cout << "Press 1 if you want to change it. Otherwise press any other number ";
            std::cin >> n;
            if (n == 1) {
                std::cout << "Set new description: ";
                TaskToChange->SetPriority();
                n = 0;
            }

            std::cout << "Current Start time: " << TaskToChange->GetType().getType();
            std::cout << "Press 1 if you want to change it. Otherwise press any other number ";
            std::cin >> n;
            if (n == 1) {
                std::cout << "Set new Start time: ";
                TaskToChange->SetTime_start();
                n = 0;
            }
            std::cout << "Current End time: " << TaskToChange->GetType().getType();
            std::cout << "Press 1 if you want to change it. Otherwise press any other number ";
            std::cin >> n;
            if (n == 1) {
                std::cout << "Set new End time: ";
                TaskToChange->SetTime_end();
                n = 0;
            }
        }
        else {
            std::cout << "Task not found.\n";
        }

    }

    void Delete(std::list<Task> &tasks) {
        std::string NameToFind;
        std::getline(std::cin,NameToFind);


        auto TaskToDelete =
            std::find_if(tasks.begin(), tasks.end(), [&](Task& task) {
            return task.GetName() == NameToFind;
        });

        if (TaskToDelete != tasks.end()) {
            tasks.erase(TaskToDelete);
            std::cout << "Task deleted successfully.\n";
        } else {
            std::cout << "Task not found.\n";
        }

    }

    void clearConsole() {
        for (int i = 0; i < 100; ++i) {
            std::cout << std::endl;
        }
    }

    void PrintTimeTable(std::list<Task> &tasks) const {
        Table table;
        table.add_row({"Name","Description","Priority","Type","Start at","End at"});
        for (int i = 0; i < 6; i++) {
            table[0][i].format().font_color(Color::blue);
        }
        //std::cout << date.GetDate() << std::endl;
        std::for_each(tasks.begin(),tasks.end(),[&table](Task task) {
            table.add_row({task.GetName(),
            task.GetDescription(),
            std::to_string(task.GetPriority()),
            task.GetType().getType(),
            task.GetTime_start().GetTime(),
            task.GetTime_end().GetTime()});
        });

            std::cout << table << std::endl;
    }

    void Proggram() {
        Date date;
        date.SetCurrentDate();
       std::list<Task> tasks;
        Task task;
        task.Create();
        chooseType(task);
        tasks.emplace_back(task);
        PrintTimeTable(tasks);
        WriteToFile(date,tasks);
        /*std::string nameoffile = "day\\" +  date.GetDate() + ".txt";
        std::cout << nameoffile;*/
    }

};


#endif
