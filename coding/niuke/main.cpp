#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>


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
        while(sta.size()){
            vec.push_back(sta.top());
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
            stack2.push(stack1.top());
            stack1.pop();
        }
        int res=stack2.top();
        stack2.pop();
        while (!stack2.empty()) {
            stack1.push(stack2.top());
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
        while(low<high){
            if (rotateArray[mid] < min) {
                min = rotateArray[mid];
                high = mid;
                mid=low+(high-low)/2;
            } else if (rotateArray[mid] > min) {
                low = mid+1;
                mid=low+(high-low)/2;
            } else {
                while(low<high){
                    if(rotateArray[low]<min){
                        min=rotateArray[low];
                    }
                    ++low;
                }
                break;
            }
        }
        return min;
    }
};


class Solution6 {
public:
    int jumpFloor(int number) {
        if(number<=0){
            return 0;
        }
        if(number==1){
            return 1;
        }
        if(number==2){
            return 2;
        }
        int bef1=1,bef2=2,res=0;
        for(int i=0;i<number-2;i++){
            res=bef1+bef2;
            bef1=bef2;
            bef2=res;
        }
        return res;
    }
};

class Solution7 {
public:
    int jumpFloorII(int number) {
        if(number<=0){
            return 0;
        }
        int res=1;
        for(int i=0;i<number-1;i++){
            res*=2;
        }
        return res;
    }
};


// 数值的整数次方
class Solution8 {
public:
    double Power(double base, int exponent) {
        bool sign= true;
        if(exponent==0){
            return 1;
        }
        if(base>-0.00001&&base<0.00001){
            return 0;
        }
        double res=1;
        if(exponent<0){
            exponent=-exponent;
            sign= false;
        }
        while(exponent){
            if(exponent&1){
                res*=base;
            }
            base*=base;
            exponent>>=1;
        }
        return sign?res:1/res;
    }
};


//使奇数位于偶数前
class Solution9 {
public:
    void reOrderArray(vector<int> &array) {
        queue<int> even;
        for(vector<int>::iterator itr=array.begin();itr!=array.end();itr++){
            if(!(*itr%2)){
                even.push(*itr);
                array.erase(itr);
                itr--;
            }
        }
        while(!even.empty()){
            array.push_back(even.front());
            even.pop();
        }
    }
};


// 输出倒数第k个节点
class Solution10 {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *target=pListHead;
        ListNode *end=target;
        for(int i=0;i<k;++i){
            if(!end){
                return nullptr;
            }
            end=end->next;
        }
        for(end;end;end=end->next){
            target=target->next;
        }
        return target;
    }
};

// 反转链表
class Solution11 {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead||!pHead->next){
            return pHead;
        }
        ListNode *before,*now,*after;
        before=pHead;
        now=pHead->next;
        before->next=NULL;
        while(now){
            after=now->next;
            now->next=before;
            before=now;
            now=after;
        }
        return before;
    }
};

//两个链表的排序
class Solution12 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        if(!pHead1){
            return pHead2;
        }
        if(!pHead2){
            return pHead1;
        }
        ListNode *res=pHead1;
        ListNode *after;
        while(pHead1->next&&pHead2){
            if(pHead1->val<pHead2->val){
                if((pHead1->next->val)>=pHead2->val){
                    after=pHead2->next;
                    pHead2->next=pHead1->next;
                    pHead1->next=pHead2;
                    pHead1=pHead1->next;
                    pHead2=after;
                } else{
                    pHead1=pHead1->next;
                    while(pHead1->next){
                        if((pHead1->next->val)>=pHead2->val){
                            after=pHead2->next;
                            pHead2->next=pHead1->next;
                            pHead1->next=pHead2;
                            pHead1=pHead1->next;
                            pHead2=after;
                            break;
                        } else{
                            pHead1=pHead1->next;
                        }
                    }
                }
            } else {
                after=pHead2->next;
                pHead2->next=pHead1;
                pHead1=pHead2;
                pHead2=after;
                res=pHead1;
            }
        }
        if(pHead2){
            pHead1->next=pHead2;
        }
        return res;
    }
};

// 判断子树
class Solution13 {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(!pRoot1||!pRoot2){
            return false;
        }
        if(pRoot1->val==pRoot2->val){
            if(Equaltree(pRoot1,pRoot2)){
                return true;
            }
        }
        return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);

    }

    bool Equaltree(TreeNode* pRoot1,TreeNode* pRoot2){
        if(!pRoot1){
            return pRoot2==NULL;
        }
        if(!pRoot2){
            return true;
        }
        if(pRoot1->val==pRoot2->val){
            return Equaltree(pRoot1->left,pRoot2->left)&&Equaltree(pRoot1->right,pRoot2->right);
        } else{
            return false;
        }
    }
};

//二叉树镜像
class Solution14 {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot){
            Mirror(pRoot->right);
            Mirror(pRoot->left);
            TreeNode *tmp;
            tmp=pRoot->left;
            pRoot->left=pRoot->right;
            pRoot->right=tmp;
        }
    }
};

//顺时针打印矩阵
class Solution15 {
public:
    vector<int> printMatrix(const vector<vector<int>> &matrix) {
        vector<int> res;
        auto line=int(matrix.size());
        auto column=int(matrix[0].size());
        int i=0,j=0,k;
        while(i<line-1&&j<column-1){
            for(k=j;k<column;k++){
                res.push_back(matrix[i][k]);
            }
            ++i;
            for(k=i;k<line;k++){
                res.push_back(matrix[k][column-1]);
            }
            --column;
            for(k=column-1;k>=j;k--){
                res.push_back(matrix[line-1][k]);
            }
            --line;
            for(k=line-1;k>=i;k--){
                res.push_back(matrix[k][j]);
            }
            --j;
        }
        if(i==line-1&&j<column){
            for(k=j;k<column;k++){
                res.push_back(matrix[i][k]);
            }
        } else if(j==column-1&&i<column){
            for(k=i;k<line;k++){
                res.push_back(matrix[k][j]);
            }
        }
        return res;
    }
};

class Solution16 {
    stack<int> data_stack,min_stack;
public:
    void push(int value) {
        data_stack.push(value);
        if(min_stack.empty()||value<=min_stack.top()){
            min_stack.push(value);
        }
    }
    void pop() {
        if(data_stack.top()==min_stack.top()){
            min_stack.pop();
        }
        data_stack.pop();
    }
    int top() {
        return data_stack.top();
    }
    int min() {
        return min_stack.top();
    }
};

class Solution17 {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> sta;
        for (int &pos : pushV) {
            sta.push(pos);
            if(pos ==popV.front()){
                sta.pop();
                popV.erase(popV.begin());
            }
        }
        for(int &pos: popV){
            if(pos==sta.top()){
                sta.pop();
            } else{
                return false;
            }
        }
        return true;
    }
};

//层序遍历
class Solution18 {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> vec;
        if(!root){
            return vec;
        }
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* tmp;
        while(!que.empty()){
            tmp=que.front();
            if(tmp->left){
                que.push(tmp->left);
            }
            if(tmp->right){
                que.push(tmp->right);
            }
            vec.push_back(tmp->val);
            que.pop();
        }
        return vec;
    }
};

class Solution19 {
public:
    bool VerifySquenceOfBST(const vector<int> &sequence) {
        if(sequence.empty()){
            return false;
        }
        return VerifyPart(sequence,0,sequence.size()-1);
    }

    bool VerifyPart(const vector<int> &sequence,int begin,int end){
        if(begin>=end){
            return true;
        }
        int root=sequence[end];
        int pos=begin;
        while(pos<end&&sequence[pos]<root)pos++;
        for(int i=pos;i<=end-1;++i){
            if(sequence[i]<root){
                return false;
            }
        }
        return VerifyPart(sequence,begin,pos-1)&&VerifyPart(sequence,pos,end-1);
    }
};

//计算1+2+...+n
class Solution20 {
public:
    int Sum_Solution(int n) {
        int res;
        res=n;
        return res&&(res+=Sum_Solution(n-1));
    }
};


//找出所有与expectNumber相等的路径
class Solution21 {
    vector<vector<int>> res;
    vector<int> tmp;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(!root){
            return res;
        }
        Judge(root,expectNumber);
        return res;
    }

    void Judge(TreeNode* root,int left){
        left-=root->val;
        tmp.push_back(root->val);
        if(root->left){
            Judge(root->left,left);
        }
        if(root->right){
            Judge(root->right,left);
        }
        if(!root->left&&!root->right&&left==0){
            res.push_back(tmp);
        }
        tmp.pop_back();
    }
};

//二叉搜索树与双向链表
class Solution22 {
    vector<TreeNode *> nodes;
    void Insert_node(TreeNode* root){
        if(root->left){
            Insert_node(root->left);
        }
        nodes.push_back(root);
        if(root->right){
            Insert_node(root->right);
        }
    }
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree){
            return NULL;
        }
        Insert_node(pRootOfTree);
        int len=nodes.size();
        for(int i=0;i<len-1;++i){
            nodes[i]->right=nodes[i+1];
        }
        for(int i=len-1;i>0;--i){
            nodes[i]->left=nodes[i-1];
        }
        return nodes[0];
    }
};


//****字符串排列****
class Solution23 {
    vector<string> res;
    void Forward(const string &str,string::iterator itr){
        if(itr+1==str.end()){
            return;
        }
        Forward(str,itr+1);
        for(auto pos=itr+1;pos!=str.end();pos++){
            if(*itr!=*pos){
                char t=*itr;
                *itr=*pos;
                *pos=t;
                Forward(str,itr+1);
                res.push_back(str);
                *pos=*itr;
                *itr=t;
            }
        }
    }
public:
    vector<string> Permutation(string str) {
        if(str.empty()){
            return res;
        }
        res.push_back(str);
        if(str.size()==1){
            return res;
        }
        Forward(str,str.begin());
        sort(res.begin(),res.end());
        return res;
    }
};


//数组中次数超过一半的数字
class Solution24 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int now=numbers.front();
        int count=0;
        for(auto num:numbers){
            if(count==0){
                now=num;
                ++count;
            } else if(now==num) {
                ++count;
            } else{
                --count;
            }
        }
        if(count>0){
            count=0;
            for(auto num:numbers){
                if(num==now){
                    count++;
                }
            }
            if(count>numbers.size()/2){
                return now;
            }
        }
        return 0;
    }
};

int main(){
    Solution23 so;
    string str="bba";
    auto res=so.Permutation(str);
    for (auto &re : res) {
        cout<< re <<endl;
    }
}
