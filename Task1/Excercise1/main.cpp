#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include "mystack.h"
#include <qstring.h>
#include <string>
#include <stdlib.h>
#include "workwithinputstring.h"
using namespace std;

int main()
{
    printf("Started!\n");

    string inputStr;
    printf("Select stack type:\n\t 1 - with array \n\t 2 - with list\n\n");
    bool stackTypeIsArray = true;
    int type;
    scanf("%d\n", &type);
    if (type == 2) {
        stackTypeIsArray = false;
    }
    getline(cin, inputStr);
    bool isParceCorrect = false;
    int answer = WorkWithInputString::stringParse(inputStr, isParceCorrect, stackTypeIsArray);
    if (isParceCorrect) {
        printf("%d", answer);
    } else {
        printf("Incorrect input string\n");
    }
    return 0;
}
