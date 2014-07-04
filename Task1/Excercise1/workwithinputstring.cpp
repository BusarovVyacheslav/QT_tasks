#include "workwithinputstring.h"
#include "mystack.h"
#include "stackwithlist.h"
#include "workingstack.h"
#include <string>
#include <stdlib.h>
using namespace std;

bool WorkWithInputString::isItNumber (char ch) {
    return (ch >= '0') && (ch <= '9');
}

int WorkWithInputString::stringParse(string inputStr, bool &isItCorrect, bool stackType) {

        isItCorrect = true;

//         WorkingStack *stack = stackType ? new MyStack() : new StackWithList();

        WorkingStack *stack = nullptr;
        if (stackType) {
            stack = new MyStack();
        } else {
            stack = new StackWithList();
        }

        int i = 0;
        bool isPopCorrect = false;
        int firstArg = 0;
        int secondArg = 0;
        std::string argInStr;
        while (i < inputStr.length()) {
           while ((inputStr[i] == ' ') && (i < inputStr.length())) {
               i++;
           }
           if (isItNumber(inputStr[i])) {
               argInStr = "";
               while (isItNumber(inputStr[i])) {
                    argInStr = argInStr + inputStr[i];
                    i++;
               }
               stack->push(atoi(argInStr.c_str())); //взять char*

           } else {
               firstArg = stack->pop(isPopCorrect);
               if (!isPopCorrect){
                   isItCorrect = false;
                   return 0;
               }
               secondArg = stack->pop(isPopCorrect);
               if (!isPopCorrect){
                   isItCorrect = false;
                   return 0;
               }
               switch (inputStr[i]) {
                   case '+': {
                       stack->push(firstArg + secondArg);
                       break;
                   }
                   case '*': {
                       stack->push(firstArg * secondArg);
                       break;
                   }
                   case '/': {
                       stack->push(secondArg / firstArg);
                       break;
                   }
                   case ':': {
                       stack->push(secondArg / firstArg);
                       break;
                    }
               }
               i++;
           }
        }

        if (stack->sizeOfStack() != 1)  {
            return stack->pop(isPopCorrect);
        }
        isItCorrect = false;
}
