#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define ISNUMBER 1
#define ISOPRATE 2



int getclass(char chr){
    switch (chr) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            if (chr >= '0' && chr <= '9') {
                return 0;
            } else{
                return -1;
            }
    }
}

int priority(char chr){
}


int main(){
    string var;
    string res;
    stack<char> sta;
    getline(cin, var);
    for (char chr:var) {
        if()
    }
}
