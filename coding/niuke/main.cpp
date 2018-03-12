#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(!head||!head->next)return head;
        ListNode *result = new ListNode(0);
        ListNode *j,*now,*next;
        int i=0;
        while(head){
            i++;
            now=head;
            head=head->next;
            cout<<"judging"<<i<<" "<<now->val<<endl;
            for(j=result;j->next;j=j->next){class Solution {
                public:
                    bool Find(int target, vector<vector<int> > array) {

                    }
                };
                if(now->val<(j->next)->val){
                    next=new ListNode(now->val);
                    next->next=j->next;
                    j->next=next;
                    break;
                }
            }
            if(j->next==NULL){
                j->next=new ListNode(now->val);
            }

        }
        return result->next;
    }
};


class Solution1 {
public:
    bool Find(int target, vector<vector<int> > array) {
        int len1=array.size();
        int len2=array[0].size();
        int i=len1-1,j=0;
        while(i>=0&&j<len2){
            if(array[i][j]==target){
                return true;
            } else if(array[i][j]>target){
                --i;
            } else{
                ++j;
            }
        }
        return false;
    }

};

class Solution2 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> sta;
        vector<int> vec;
        for(ListNode *i=head;i;i=i->next){
            sta.push(i->val);
        }
        while(!sta.empty()){
            int elem=sta.top();
            vec.push_back(elem);
            sta.pop();
        }
        return vec;
    }
};

class Solution3 {
public:
    TreeNode* reConstructBinaryTree(const vector<int> &pre,const vector<int> &vin) {
        if(vin.empty())
            return NULL;
        int len=vin.size(),i;
        vector<int> left_pre,left_vin,right_pre,right_vin;
        TreeNode *root=new TreeNode(pre[0]);
        for(i=0;vin[i]!=pre[0]&&i<1000;i++){
            left_pre.push_back(pre[i+1]);
            left_vin.push_back(vin[i]);
        }
        for(++i;i<len;i++){
            right_pre.push_back(pre[i]);
            right_vin.push_back(vin[i]);
        }
        root->left = reConstructBinaryTree(left_pre, left_vin);
        root->right = reConstructBinaryTree(right_pre, right_vin);
        return root;
    }
};

class Solution4 {
public:
    void push(int node) {
        stack1.push(node);
    }
    int pop() {
        while (!stack1.empty()) {
            int elem = stack1.top();
            stack2.push(elem);
            stack1.pop();
        }
        int res=stack2.top();
        stack2.pop();
        while (!stack2.empty()) {
            int elem=stack2.top();
            stack1.push(elem);
            stack2.pop();
        }
        return res;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

class Solution5 {
public:
    int minNumberInRotateArray(const vector<int> &rotateArray) {
        int len = rotateArray.size();
        if(len==0){
            return 0;
        }
        int low=0,high=len-1;
        int min = rotateArray[0];
        int mid=low+(high-low)/2;
        while(low<high&&mid>0){
            if (rotateArray[mid] < min) {
                min = rotateArray[mid];
                high = mid-1;
                mid=low+(high-low)/2;
            } else if (rotateArray[mid] > min) {
                low = mid+1;
                mid=low+(high-low)/2;
            } else {
                --mid;
            }
        }
        return min;
    }
};

int main(){
//    vector<int> tes={6501,6828,6963,7036,7422,7674,8146,8468,8704,8717,9170,9359,9719,9895,9896,9913,9962,154,293,334,
//                     492,1323,1479,1539,1727,1870,1943,2383,2392,2996,3282,3812,3903,4465,4605,4665,4772,4828,5142,5437,
//                     5448,5668,5706,5725,6300,6335};
    vector<int> tes={1,2,0,0,2,1,1};
    Solution5 sol;
    cout<<sol.minNumberInRotateArray(tes);
}

