#include <iostream>
#include <string>
using namespace std;

/*
 * 请实现一个函数，用来判断一颗二叉树是不是对称的。
 * 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    explicit TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
private:
    bool leftEqRight(TreeNode *left, TreeNode *right){
        // 两边都遍历到底
        if (left == nullptr && right == nullptr) {
            return true;
        }
        // 一个节点遍历到底，另一个还没有
        if (left == nullptr || right == nullptr) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return leftEqRight(left->left, right->right) && leftEqRight(left->right, right->left);
    }
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return true;
        }
        return leftEqRight(pRoot->left, pRoot->right);
    }
};
