#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
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


//******最小的K个数******
//TODO 堆排序，红黑树
class Solution25 {
public:
    vector<int> GetLeastNumbers_Solution(const vector<int> &input, int k) {
        vector<int> res;
        auto len=int(input.size());
        if(len<k||k==0||len==0){
            return res;
        }
        list<int> fuck_res;
        fuck_res.push_back(input[0]);
        list<int>::iterator res_pos;
        bool judge= true;
        for(int i=1;i<k;++i){
            res_pos=fuck_res.begin();
            while(res_pos!=fuck_res.end()){
                if(*res_pos>=input[i]){
                    fuck_res.insert(res_pos,input[i]);
                    judge=false;
                    break;
                }
                ++res_pos;
            }
            if(judge){
                fuck_res.insert(res_pos,input[i]);
            }
            judge=true;
        }
        for(int i=k;i<len;++i){
            res_pos=fuck_res.begin();
            while(res_pos!=fuck_res.end()){
                if((*res_pos>=input[i])){
                    fuck_res.insert(res_pos,input[i]);
                    fuck_res.pop_back();
                    break;
                }
                ++res_pos;
            }
        }
        for(res_pos=fuck_res.begin();res_pos!=fuck_res.end();++res_pos){
            res.push_back(*res_pos);
        }
        return res;
    }
};


//连续子数组的最大和
class Solution26 {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int res=array[0],tmp=0;
        for(auto elem=array.begin();elem!=array.end();*elem++){
            if(tmp+*elem<0){
                tmp=(tmp<=0)?*elem:0;
            } else {
                tmp=(tmp<=0)?*elem:tmp+*elem;
            }
            res=res<tmp?tmp:res;
        }
        return res;
    }
};

//整数中1出现的次数
class Solution27 {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        if(n<=0){
            return 0;
        }
        int base=1;
        int point;
        int right=0;
        int count=0;
        while(n) {
            point = n % 10;
            n = n / 10;
            if (point > 1) {
                count+=(n+1)*base;
            } else if(point==0){
                count+=n*base;
            } else{
                count+=n*base+right+1;
            }
            right=right+point*base;
            base*=10;
        }
        return count;
    }
};


//****把数组排成最小的数****
class Solution28 {
    static bool Compare(int a, int b){
        string ab = to_string(a)+to_string(b);
        string ba = to_string(b)+to_string(a);
        return ab<ba;
    }
public:
    string PrintMinNumber(vector<int> numbers) {
        string result;
        if(numbers.empty()){
            return result;
        }
        sort(numbers.begin(),numbers.end(),Compare);
        for(auto elem:numbers){
            result.append(to_string(elem));
        }
        return result;
    }
};


//丑数
class Solution29 {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<1){
            return 0;
        }
        vector<int> uglynumbers(index);
        int position2=0;
        int position3=0;
        int position5=0;
        uglynumbers[0]=1;
        int next;
        for(int i=1;i<index;i++){
            int next=min(uglynumbers[position2]*2,min(uglynumbers[position3]*3,uglynumbers[position5]*5));
            uglynumbers[i]=next;
            if(uglynumbers[position2]*2<=next){
                ++position2;
            }
            if(uglynumbers[position3]*3<=next){
                ++position3;
            }
            if(uglynumbers[position5]*5<=next){
                ++position5;
            }
        }
        return uglynumbers[index-1];
    }
};


class Solution30 {
public:
    int FirstNotRepeatingChar(string str) {
        map<char,int> elem_times;
        for(auto i:str){
            elem_times[i]++;
        }
        for (int i = 0; i < str.size(); ++i) {
            if(elem_times[str[i]]==1){
                return i;
            }
        }
        return -1;
    }
};

//****数组中的逆序对****
class Solution31 {
public:
    int InversePairs(vector<int> data) {
        if(data.empty()){
            return 0;
        }
        long count=CountTwoPairs(data,0,data.size()-1);
        return count%1000000007;
    }

    long CountTwoPairs(vector<int> &data,int start,int end){
        if(start>=end){
            return 0;
        }
        int mid=(start+end)/2;
        long count=0;
        count=count+CountTwoPairs(data,start,mid)+CountTwoPairs(data,mid+1,end);
        int i=mid;
        int j=end;
        int insert_pos;
        stack<int> tmp;
        while(i>=start&&j>mid){
            if(data[i]>data[j]){
                count+=(j-mid);
                tmp.push(data[i]);
                i--;
            } else{
                tmp.push(data[j]);
                j--;
            }
        }
        if(j==mid){
            ++i;
            for(;i<=end;i++){
                data[i]=tmp.top();
                tmp.pop();
            }
        } else {
            for (insert_pos = j; insert_pos > mid; insert_pos--) {
                tmp.push(data[insert_pos]);
            }
            while (start <= end) {
                data[start] = tmp.top();
                tmp.pop();
                ++start;
            }
        }
        return count;
    }
};


//两个链表的第一个公共节点
class Solution32 {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2) {
            return NULL;
        }
        int len1=0,len2=0;
        ListNode *pos1=pHead1,*pos2=pHead2;
        while(pos1->val){
            ++len1;
            pos1=pos1->next;
        }
        while(pos2->val){
            ++len2;
            pos2=pos2->next;
        }
        if(len1>len2){
            for (int i = 0; i < len1 - len2; i++) {
                pHead1=pHead1->next;
            }
        } else{
            for (int i = 0; i < len2-len1; ++i) {
                pHead2=pHead2->next;
            }
        }
        while(pHead1){
            if(pHead1==pHead2){
                break;
            }
            pHead1=pHead1->next;
            pHead2=pHead2->next;
        }
        return pHead1;
    }
};

//统计数字在排序数组中出现的次数
class Solution33 {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int len=data.size();
        int low=0,high=len-1;
        int mid=(high+low)/2;
        while(low<=high){
            if(data[mid]==k){
                int count=0;

            }
            if(data[mid]>k){
                high=mid-1;
                mid=(high+low)/2;
            }else{
                low=mid+1;
                mid=(high+low)/2;
            }
        }
        return 0;
    }
};

class Year {
private:
    int y;
public:
    static int Inity;
public:
    static void print_static(){
        cout<<Inity<<endl;
    }
};
int Year::Inity=1997;//静态变量的赋值方法,注意必须放在类外定义


int main()
{
    Solution31 so;
    cout<<49333027700%1000000007<<endl;
    return 0;
}


//int main(){
//    vector<int> res;
//    vector<int> input={1,2,3,4,5};
//    res.push_back(0);
//    cout<<res[0];
//}
