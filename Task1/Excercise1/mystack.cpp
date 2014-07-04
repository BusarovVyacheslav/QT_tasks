#include "mystack.h"
#include "workingstack.h"
#include <iostream>
#include <stdio.h>
using namespace std;


MyStack::MyStack() {
     //this только для методов!
    mSize = 0;
}

bool MyStack::push(int element) {
    if (mSize >= maxSizeConst) {
        return false;
    }

    this->mSize++;
    this->mElements[mSize] = element;
    return true;
}

int MyStack::pop(bool &isItCorrect)
{
    if (this->mSize == 0) {
        isItCorrect = false;
        return -1;
    }
    isItCorrect = true;
    return this->mElements[this->mSize--];

}



