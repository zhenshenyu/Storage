#include <iostream>
#include <vector>


using namespace std;

static int max_value=0;
int F, V;

void get_max(const vector<vector<int>> &value, int x, int y,int tmp){
    if (x == F) {
        if (max_value < tmp) {
            max_value = tmp;
        }
        return;
    }
    for (int i = 0; i < V-F-y+x+1; ++i) {
        get_max(value, x+1, y+i+1, tmp+value[x][y+i]);
    };
}

int main(){

    cin >> F;
    cin >> V;
    vector<vector<int>> input;
    int buf;
    max_value=0;
    for (int i = 0; i < F; ++i) {
        vector<int> clomn;
        for (int j = 0; j < V; ++j) {
            scanf("%d",&buf);
            clomn.push_back(buf);
        }
        input.push_back(clomn);
    }
    for (int i = 0; i < F;++i) {
        max_value += input[i][i];
    }
    get_max(input,0,0,0);
    cout<<max_value;
    return 0;
}
