#include <iostream>
#include <vector>

using namespace std;


/*
 * 快排算法的一种实现，基于交换数组元素
 * TODO 去掉flag变量
 */

class QuickSortSolution{
    void NextSort(vector<int> &arr,int start,int end){
        if (end-start<1) {
            return;
        }
        int low=start;
        int high=end;
        bool flag=true;
        while (low != high) {
            if(flag){
                if(arr[low]<arr[high]){
                    --high;
                } else{
                    swap(arr[low], arr[high]);
                    ++low;
                    flag=false;
                }
            } else{
                if(arr[low]<arr[high]){
                    ++low;
                } else{
                    swap(arr[low], arr[high]);
                    --high;
                    flag=true;
                }
            }
        }
        NextSort(arr, start, low - 1);
        NextSort(arr, low + 1, end);
    }

public:
    vector<int> QuickSort(vector<int> array){
        auto len = array.size();
        if (len < 2) {
            return array;
        }
        NextSort(array,0,int(len)-1);
        return array;
    }
};


int main(){
    vector<int> test={3,5,7,9,1,3,0,6,8,4,9};
    QuickSortSolution so;
    auto res = so.QuickSort(test);
    for (auto elem:res) {
        printf("%d\n",elem);
    }
    return 0;
}
