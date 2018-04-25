#include <iostream>

using namespace std;


long long numPosb(const int &m,  int n){
    if (m == 0) {
        return n;
    }
    long long res=1;
    for (int i = 1; i <= m; ++i) {
        res*=n--;
        res /=i;
    }
    return res;
}


int main(){
    int k;
    cin>>k;
    int a,x,b,y;
    scanf("%d",&a);
    scanf("%d",&x);
    scanf("%d",&b);
    scanf("%d",&y);
    long count=0;
    int left = k;
    for(int i=0;i<x;++i){
        if (left %b==0&&left<=b*y) {
            count+=(numPosb(i,x)*(numPosb(left/b,y)));
        }
        left-=a;
        if (left <= 0) {
            break;
        }
    }
    cout<<count%1000000007;
    return 0;
}

