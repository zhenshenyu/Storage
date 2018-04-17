//输入若干0-9的数，求这些数所不能组成的最小的数
//例如 
//输入>>123 输出>>4 
//输入>>123456789 输出>>10
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    string str1;
    map<char,int > mp;
    getline(cin, str1);
    map<char, int>::iterator itr;
    for (auto elem:str1) {
        itr = mp.find(elem);
        if (itr == mp.end()) {
            mp[elem]=1;
        } else {
            ++(itr->second);
        }
    }
    string res;
    char bit='1';
    bool loop= true;
    char flag='1';
    while(loop){
        for (char i = bit; i <='9' ; ++i) {
            itr = mp.find(i);
            if (itr==mp.end()) {
                res.push_back(i);
                loop=false;
                break;
            }
        }
        if (loop) {
            char rec=flag;
            int num = mp[flag];
            for (char i = flag+1; i <='9' ; ++i) {
                if (mp[i] < num) {
                    num = mp[i];
                    rec=i;
                }
            }
            res.push_back(rec);
            flag=0;
            if (num == 1) {
                mp.erase(rec);
            } else{
                --mp[rec];
            }
            bit = '0';
        }
    }
    cout<<res<<endl;
}
