#pragma once
#include <string>
using namespace std;

class WorkWithInputString
{

public:
    static int stringParse(string inputStr, bool &IsItCoreect, bool stackType);

private:
    static bool isItNumber(char ch);
};

