#include <iostream>
#include <string>

using namespace std;


/*
 * 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
 * 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
 * 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
 * 是不是很简单？OK，搞定它！
 */

class Solution {
public:
    string LeftRotateString(const string &str, int n) {
        int len = str.size();
        if (len == 0) {
            return str;
        }
        n = n % len;
        if (n == 0) {
            return str;
        }
        string res;
        for (int i = n; i < len; ++i) {
            res.push_back(str[i]);
        }
        for (int i= 0; i < n; ++i) {
            res.push_back(str[i]);
        }
        return res;
    }
};

