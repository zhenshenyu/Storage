#include <iostream>
#include <string>
using namespace std;

/*
 * 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
 *
 */

class Solution {
public:
    int StrToInt(const string & str) {
        if(str.length()==0){
            return 0;
        }
        bool flag = false;
        int value=0;
        auto pos=str.begin();
        if(*pos=='-'){
            flag=true;
            ++pos;
        } else if(*pos=='+'){
            ++pos;
        }
        while (pos != str.end()) {
            if(*pos>='0'&&*pos<='9'){
                value=value*10+*pos-'0';
            } else{
                return 0;
            }
            ++pos;
        }
        if (flag) {
            value = -value;
        }
        return value;
    }
};

