#pragma once
#include "workingstack.h"


class StackWithList : public WorkingStack
{        
    public:
        StackWithList();
        bool push(int element) override;
        int pop(bool &checker) override; //ссылка

    private:
        struct ElementOfList {
            double value;
            struct ElementOfList* next;

            ElementOfList(int element) {//public по умолчанию?
                value = element;
                next = nullptr;
            }
        };
        struct ListHeader {
            struct ElementOfList* first;
        };
        ListHeader *mList = new ListHeader();


};

