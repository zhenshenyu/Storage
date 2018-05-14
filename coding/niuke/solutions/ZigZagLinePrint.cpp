#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
 * 请实现一个函数按照之字形打印二叉树，
 * 即第一行按照从左到右的顺序打印，
 * 第二层按照从右至左的顺序打印，
 * 第三行按照从左到右的顺序打印，
 * 其他行以此类推。
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
    vector<vector<int>> result;
    stack<TreeNode *> sta1;
    stack<TreeNode *> sta2;
public:
    vector<vector<int> > ZigZagLinePrint(TreeNode* pRoot) {
        vector<int> tmp;
        TreeNode *node= nullptr;
        if (pRoot == nullptr) {
            return result;
        }
        sta1.push(pRoot);
        while (!sta1.empty() || !sta2.empty()) {
            tmp.clear();
            while (!sta1.empty()) {
                node = sta1.top();
                tmp.push_back(node->val);
                if (node->left) {
                    sta2.push(node->left);
                }
                if (node->right) {
                    sta2.push(node->right);
                }
                sta1.pop();
            }
            result.push_back(tmp);
            if (!sta2.empty()) {
                tmp.clear();
                while (!sta2.empty()) {
                    node = sta2.top();
                    tmp.push_back(node->val);
                    if (node->right) {
                        sta1.push(node->right);
                    }
                    if (node->left) {
                        sta1.push(node->left);
                    }
                    sta2.pop();
                }
                result.push_back(tmp);
            }
        }
        return result;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    Solution solution;
    auto res = solution.ZigZagLinePrint(root);
    for (auto fl:res) {
        for (auto elem:fl) {
            cout << elem << endl;
        }
    }
    return 0;
}
