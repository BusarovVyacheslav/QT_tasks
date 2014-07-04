#pragma once
#include "workingstack.h"


class MyStack : public WorkingStack
{
    public:
        MyStack();
        bool push(int element) override;
        int pop(bool &checker) override; //ссылка // разумная область памяти

    private:
        static const int maxSizeConst = 10000;
        double mElements[maxSizeConst];

};


