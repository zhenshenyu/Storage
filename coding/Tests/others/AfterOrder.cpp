#include <iostream>
#include <string>

using namespace std;

int main(){
    string steps;
    int q;
    getline(cin, steps);
    scanf("%d", &q);
    int n, m, x, y;
    int res;
    for (int i = 0; i < q; ++i) {
        res=0;
        scanf("%d", &n);
        scanf("%d", &m);
        scanf("%d", &x);
        scanf("%d", &y);
        for (char elem:steps) {
            if (x < 1 || x > n || y < 1 || y > m) {
                break;
            }
            ++res;
            switch (elem) {
                case 'u':
                    y += 1;
                    break;
                case 'd':
                    y -= 1;
                    break;
                case 'l':
                    x -= 1;
                    break;
                case 'r':
                    x += 1;
                    break;
            }
        }
        cout << res << endl;
    }
}
