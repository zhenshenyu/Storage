#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    explicit TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

/*
 * 遍历二叉树
 */
class BinaryTreeTraversal {
private:
    // 遍历结果
    vector<int> result;

    // 前序遍历的递归实现
    void FrontNext(TreeNode *Node){
        if (Node == nullptr) {
            return;
        }
        result.push_back(Node->val);
        FrontNext(Node->left);
        FrontNext(Node->right);
    }

    // 中序遍历的递归实现
    void MidNext(TreeNode *Node){
        if (Node == nullptr) {
            return;
        }
        MidNext(Node->left);
        result.push_back(Node->val);
        MidNext(Node->right);
    }

    // 后序遍历的递归实现
    void AfterNext(TreeNode *Node){
        if (Node == nullptr) {
            return;
        }
        AfterNext(Node->left);
        AfterNext(Node->right);
        result.push_back(Node->val);
    }

    // 前序遍历非递归实现
    void FrontOrder(TreeNode *Node){
        stack<TreeNode*> tmp;
        while (!tmp.empty() || Node) {
            if (Node) {
                result.push_back(Node->val);
                tmp.push(Node);
                Node = Node->left;
            } else {
                Node=tmp.top();
                tmp.pop();
                Node = Node->right;
            }
        }
    }

    // 中序遍历非递归实现
    void MidOrder(TreeNode *Node){
        stack<TreeNode*> tmp;
        while (!tmp.empty() || Node) {
            if (Node) {
                tmp.push(Node);
                Node = Node->left;
            } else{
                Node=tmp.top();
                tmp.pop();
                result.push_back(Node->val);
                Node = Node->right;
            }
        }
    }

    // 后序遍历非递归实现
    void AfterOrder(TreeNode *Node){
        stack<TreeNode*> tmp;
        TreeNode *last = nullptr;
        while (Node) {
            tmp.push(Node);
            Node = Node->left;
        }
        while (!tmp.empty()) {
            Node = tmp.top();
            if(Node->right== nullptr||Node->right==last){
                tmp.pop();
                result.push_back(Node->val);
                last = Node;
            } else{
                Node = Node->right;
                while (Node) {
                    tmp.push(Node);
                    Node = Node->left;
                }
            }
        }
    }

public:
    void Traversal(TreeNode *pRoot, char method = 'f', bool recursion= true){
        result.clear();
        switch (method) {
            case 'f':
                if(recursion){
                    FrontNext(pRoot);
                } else{
                    FrontOrder(pRoot);
                }
                break;
            case 'm':
                if(recursion){
                    MidNext(pRoot);
                } else {
                    MidOrder(pRoot);
                }
                break;
            case 'a':
                if(recursion){
                    AfterNext(pRoot);
                } else{
                    AfterOrder(pRoot);
                }
                break;
            default:
                return;
        }
    }

    void ShowResult(){
        for (auto elem: result) {
            cout << elem << endl;
        }
    }

    vector<int> GetOrder(){
        return result;
    }
};


int main(){
    auto *root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);
    BinaryTreeTraversal so;
    cout << "RecursionTraversalFront:" << endl;
    so.Traversal(root, 'f');
    so.ShowResult();
    cout << "RecursionTraversalMid:" << endl;
    so.Traversal(root, 'm');
    so.ShowResult();
    cout << "RecursionTraversalAfter:" << endl;
    so.Traversal(root, 'a');
    so.ShowResult();
    cout << "NonRecursionTraversalFront:" << endl;
    so.Traversal(root, 'f', false);
    so.ShowResult();
    cout << "NonRecursionTraversalMid:" << endl;
    so.Traversal(root, 'm', false);
    so.ShowResult();
    cout << "NonRecursionTraversalAfter:" << endl;
    so.Traversal(root, 'a', false);
    so.ShowResult();
    return 0;
}

