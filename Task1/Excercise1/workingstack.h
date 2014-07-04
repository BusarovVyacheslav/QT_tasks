#pragma once

class WorkingStack
{

public:
    virtual bool push(int element) = 0;
    virtual int pop(bool &checker) = 0;
    virtual void clean() {
        this->mSize = 0;
    }
    virtual int sizeOfStack() {
        return this->mSize;
    }
    //у всех потомков этого класса вызовится деструктор при его наличии
    virtual ~WorkingStack() {}

protected:
    int mSize;
};



