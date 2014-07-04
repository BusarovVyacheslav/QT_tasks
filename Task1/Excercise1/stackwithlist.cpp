#include "stackwithlist.h"
#include "workingstack.h"
#include <iostream>
#include <stdio.h>
using namespace std;

StackWithList::StackWithList() {
    mList->first = nullptr;
    mSize = 0;
}

bool StackWithList::push(int element) {
    mSize++;
    ElementOfList *newElement = new ElementOfList(element);
    if (this->mSize == 1) {
        this->mList->first = newElement;
    } else {
        ElementOfList *i = this->mList->first;
        while (i->next != nullptr) {
            i = i->next;
        }
        i->next = newElement;
    }
    return true;
}

int StackWithList::pop(bool &isItCorrect)
{
    if (mSize == 0) {
        isItCorrect = false;
        return -1;
    }
    isItCorrect = true;
    ElementOfList *i = this->mList->first;
    double answer = 0;
    if (mSize == 1) {
        answer = i->value;
        delete i;
        this->mList->first = nullptr;
    } else {
        while (i->next->next != nullptr) {
            i = i->next;
        }
        answer = i->next->value;
        delete i->next;
        i->next = nullptr;
    }
    this->mSize--;
    return answer;

}




