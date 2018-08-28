#include <iostream>
#include <string>

using namespace std;

/*
 *两个大数使用string表示，请实现一个函数，将他们相加。
 * 注意：
 * 1. 大数可能包含小数，比如：123.07 + 8796
 * 2. 输入可能有误，请检查是否合法，不合法返回值为false。
 * 3. 大数不包含科学计数法 
 */

bool ConvToNum(const string &str, double &num){
    // flag表示是否已有小数点，小数点只能有一个
    bool flag=false;
    // 是否为负数
    bool positive=true;
    double tmp=0;
    auto itr = str.begin();
    // 判断有无符号位
    if(*itr=='-'){
        positive = false;
        ++itr;
    } else if (*itr == '+') {
        ++itr;
    }
    while (itr != str.end()) {
        if (*itr >= '0' && *itr <= '9') {
            tmp = tmp * 10 + (*itr - '0');
            ++itr;
        } else if (*itr == '.') {
            flag = true;
            ++itr;
            break;
        } else {
            return false;
        }
    }
    // 小数部分存在
    if(flag){
        double c = 0.1;
        while (itr != str.end()) {
            if (*itr >= '0' && *itr <= '9') {
                tmp += (*itr - '0') * c;
                ++itr;
                c /= 10;
            } else{
                return false;
            }
        }
    }
    if (!positive) {
        tmp = -tmp;
    }
    num = tmp;
    return true;
}


int main(){
    string str1;
    string str2;
    double num1;
    double num2;
    getline(cin, str1);
    getline(cin, str2);
    bool res1 = ConvToNum(str1, num1);
    bool res2 = ConvToNum(str2, num2);
    // 两个数有一个不合法
    if (!res1 || !res2) {
        cout << "false";
        return 0;
    }
    cout << num1 + num2;
    return 0;
}



