#include <iostream>
#include <vector>

using namespace std;

/*
 * 背包问题
 * 动态规划求解
 *
 *
 * 考虑第 i 个物品，无外乎两种可能：选，或者不选
 *
 * 不选的话，背包的容量不变，改变为问题 max_value[i - 1][j]
 * 选的话，背包的容量变小，改变为问题max_value[i - 1][j - weight[i]] + value[i]
 */

class KnapsackSolution{
public:
    int Knapsack(int storage, const vector<int> &weight, const vector<int> &value){
        if (weight.size() != value.size() || weight.empty()) {
            return 0;
        }
        auto len = int(weight.size());
        vector<vector<int>> max_value(len,vector<int>(storage+1));
        for (int j = 0; j < storage+1; ++j) {
            if(weight[0] > j){
                max_value[0][j]=0;
            } else{
                max_value[0][j] = value[0];
            }
        }
        for (int i = 0; i < len; ++i) {
            max_value[i][0] = 0;
        }
        for (int i = 1; i < len; ++i) {
            for (int j = 1; j < storage + 1; ++j) {
                if (weight[i] > j) {
                    max_value[i][j] = max_value[i - 1][j];
                } else {
                    max_value[i][j] = max(max_value[i - 1][j - weight[i]] + value[i], max_value[i - 1][j]);
                }
            }
        }
        return max_value[len - 1][storage];
    }
};


int main(){
    vector<int> weight = {2, 3, 4 , 5};
    vector<int> value = {3, 2, 4 , 5};
    cout << (new KnapsackSolution)->Knapsack(6, weight, value) << endl;
}
