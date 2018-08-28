#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    cin.get();
    string str;
    int count;
    for (int i = 0; i < t; ++i) {
        str.clear();
        getline(cin, str);
        count=0;
        for (auto elem:str) {
            if (elem == '(') {
                ++count;
            } else{
                --count;
            }
            if (count < -1) {
                cout << "No" << endl;
                break;
            }
        }
        if (count == 0) {
            cout << "Yes" << endl;
        } else if (count >= -1) {
            cout << "No" << endl;
        }
    }
}
