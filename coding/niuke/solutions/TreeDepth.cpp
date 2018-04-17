#include <iostream>
#include <vector>

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
 * 输入一棵二叉树，求该树的深度。
 * 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
 */
// 回溯法
// 层序遍历会更好
class Solution {
private:
    int max_depth;
    void Get_Depth(TreeNode* pRoot,int depth){
        if(!pRoot){
            if (max_depth<depth) {
                max_depth = depth;
            }
            return;
        } else {
            Get_Depth(pRoot->left, depth + 1);
            Get_Depth(pRoot->right, depth + 1);
        }
    }
public:
    Solution(){
        max_depth=0;
    }
    int TreeDepth(TreeNode* pRoot) {
        Get_Depth(pRoot, 0);
        return max_depth;
    }
};

int main(){
    TreeNode *root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(2);
    Solution so;
    int res = so.TreeDepth(root);
    cout << res << endl;
}
