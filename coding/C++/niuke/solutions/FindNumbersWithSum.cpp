#include <iostream>
#include <vector>

using namespace std;


/*
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，
 * 如果有多对数字的和等于S，输出两个数的乘积最小的。
 *
 * 对应每个测试案例，输出两个数，小的先输出
 */

class Solution {
public:
    vector<int> FindNumbersWithSum(const vector<int> &array,int sum) {
        vector<int> res;
        int len = array.size();
        int left = 0;
        int right = len - 1;
        while (left < right) {
            if (array[left]+array[right]==sum) {
                res.push_back(array[left]);
                res.push_back(array[right]);
                break;
            } else if (array[left]+array[right]<sum) {
                ++left;
            } else{
                --right;
            }
        }
        return res;
    }
};

