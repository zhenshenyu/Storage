#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
 * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 */

struct ListNode {
    int val;
    struct ListNode *next;
    explicit ListNode(int x) :
            val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (pHead == nullptr) {
            return pHead;
        }
        auto head = new ListNode(0);
        head->next = pHead;
        ListNode *tmp;
        ListNode *node = head;
        bool flag = false;
        while(node->next->next!= nullptr){
            if (node->next->val == node->next->next->val) {
                tmp=node->next;
                node->next=node->next->next;
                delete tmp;
                flag=true;
            } else if (flag) {
                tmp=node->next;
                node->next=node->next->next;
                delete tmp;
                flag=false;
            } else{
                node=node->next;
            }
        }
        if(flag){
            delete node->next;
            node->next = nullptr;
        }
        return head->next;
    }
};

