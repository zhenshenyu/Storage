
#include <iostream>
#include <vector>


using namespace std;


int main(){
    int m,n;
    int t1,t2;
    scanf("%d",&m);
    scanf("%d",&n);
    vector<int> x,y,z,w;
    for (int i = 0; i < m; ++i) {
        scanf("%d",&t1);
        scanf("%d",&t2);
        x.push_back(t1);
        y.push_back(t2);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&t1);
        scanf("%d",&t2);
        z.push_back(t1);
        w.push_back(t2);
    }
    int vec[m][n];
    for (int i = 0; i < m; ++i) {
        vec[i][0] = 0;
    }
    for (int i = 1; i < n; ++i) {
        vec[0][i] = 0;
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; i < n; ++j) {

        }
    }
}
