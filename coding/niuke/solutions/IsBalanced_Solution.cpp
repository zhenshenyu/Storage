#include <iostream>
#include <hash_map>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

/*
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 */
class Solution {
private:
    int balance(int x, int y){
        return abs(x - y) <= 1;
    }

    int get_depth(TreeNode *pRoot){
        if (!pRoot) {
            return 0;
        }
        int left = get_depth(pRoot->left);
        int right = get_depth(pRoot->right);
        if(left==-1||right==-1||!balance(left,right)){
            return -1;
        } else{
            return max(left, right) + 1;
        }

    }
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return get_depth(pRoot) != -1;
    }
};


int main(){
    auto *root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(2);
    Solution so;
    bool res = so.IsBalanced_Solution(root);
    if (res) {
        cout << "yes";
    } else {
        cout << "no";
    }
}
