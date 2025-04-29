#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class error {
    string str;
public:
    error(string s) : str(s) {}
    void what() {
        cout << str << endl;
    }
};

#endif
