#include <iostream>
#include <vector>

using namespace std;

// 统计一个数字在排序数组中出现的次数。
class Solution {
public:
    int GetNumberOfK(const vector<int> &data ,int k) {
        int len=data.size();
        int left=0;
        int right=len-1;
        int mid;
        int count=0;
        while(left<=right){
            mid=(left+right)/2;
            if(data[mid]==k){
                for (int i = mid+1; i <= right; ++i) {
                    if (data[i] == k) {
                        ++count;
                    } else {
                        break;
                    }
                }
                for (int j = mid; j >= left ; --j) {
                    if (data[j] == k) {
                        ++count;
                    } else{
                        break;
                    }
                }
                break;
            } else if(data[mid]<k){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return count;
    }
};

int main(){
    Solution so;
    vector<int> vec={1,2,3,4,4,5,6};
    int res=so.GetNumberOfK(vec,4);
    cout << res << endl;
}
