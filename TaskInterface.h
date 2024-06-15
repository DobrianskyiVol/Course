#ifndef TASKINTERFACE_H
#define TASKINTERFACE_H



class TaskInterface {
public:
    virtual ~TaskInterface() = default;

    virtual void WriteToFile() = 0;
    virtual void ReadFromFile() = 0;
    //virtual void Edit() = 0;
    virtual void Create() = 0;

};



#endif
