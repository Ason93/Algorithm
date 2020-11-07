#include "questions.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // with head
    ListNode* createList() {
        ListNode* head = new ListNode();
        ListNode* curr_node = head;
        for (int i = 1; i < 10; i++) {
            ListNode* next_node = new ListNode(i);
            curr_node->next = next_node;
            curr_node = next_node;
        }
        return head;
    }

    void printNode(ListNode* head) {
        if (head != nullptr && head->next == nullptr)
            return;
        head = head->next;
        while (head != nullptr) {
            cout << head->val;
            head = head->next;
            if (head != nullptr) {
                cout << "-->";
            }
        }
        cout << endl;
    }

    // 206.Reverse Linked List
    ListNode* reverseList(ListNode* head) {
        //if (head != nullptr && head->next == nullptr)
        //    return head;
        head = head->next;
        ListNode* newHead = nullptr;
        ListNode* node = nullptr;
        while (head != nullptr) {
            //1. 对之前的链表做头删
            node = head;
            head = head->next;
            //2. 对新链表做头插
            node->next = newHead;
            newHead = node;
        }
        ListNode* reverseHead = new ListNode();
        reverseHead->next = newHead;
        return reverseHead;
    }

    // 24.Swap Nodes in Pairs
    ListNode* swapPairs(ListNode* head) {
        //if (head == nullptr || head->next == nullptr)
        //    return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* next = nullptr;
        while (cur && cur->next){
            next = cur->next->next; // 1)
            pre->next = cur->next;  // 2)
            cur->next->next = cur;  // 3)
            cur->next = next; // 4)
            pre = cur;
            cur = next;
        }
        return head;
    }

    // 141. Linked List Cycle
    bool hasCycle(ListNode* head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        while (fastPtr && fastPtr->next) { // P.S.: warning list only has one element
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if (slowPtr == fastPtr) {
                return true;
            }
        }
        return false;
    }

    // 142. Linked List Cycle II
    ListNode* detectCycle(ListNode* head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        while (fastPtr && fastPtr->next) { // P.S.: Warning list only has one element
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if (slowPtr == fastPtr) { // There is a cycle
                slowPtr = head;
                // Both pointers advance at the same time
                while (slowPtr != fastPtr) {
                    slowPtr = slowPtr->next;
                    fastPtr = fastPtr->next;
                }
                return slowPtr; // Slow is the begin of cycle
            }
        }
        return nullptr; // No cycle.
    }

    // 25. Reverse Nodes in k-Group
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr_dummy = head;
        ListNode* curr = head->next;
        int len = 0;
        while (curr) {
            curr = curr->next;
            len = (len + 1) % k;
            if (len == 0) {
                ListNode* next_dummy = curr_dummy->next;
                reverse(curr_dummy, curr);
                curr_dummy = next_dummy;
            }
        }
        return head;
    }

    void reverse(ListNode* begin, const ListNode* end) {
        ListNode* first = begin->next;
        ListNode* curr = first->next;
        while (curr != end) {
            first->next = curr->next;
            curr->next = begin->next;
            begin->next = curr;
            curr = first->next;
        }
    }
};

int UseList() {

    // 以下题目不能同时跑

    cout << "*************** Linked List ***************" << endl;
	Solution S;
    ListNode* head = S.createList();
    S.printNode(head);

 //   cout << "*************** 206.Reverse Linked List ***************" << endl;
	//ListNode* reverseHead = S.reverseList(head);
 //   S.printNode(reverseHead);

    //cout << "*************** 24.Swap Nodes in Pairs ***************" << endl;
    //ListNode* swapHead = S.swapPairs(head);
    //S.printNode(swapHead);

    //cout << "*************** 141. Linked List Cycle ***************" << endl;
    //bool has_cycle = S.hasCycle(head);
    //cout << "Whether Linked List Has Cycle is: " << has_cycle << endl;

    //cout << "*************** 142. Linked List Cycle II ***************" << endl;
    //ListNode* beginNode = S.detectCycle(head);
    //cout << "The Node Where the Cycle Begins is: " << beginNode << endl;

    cout << "*************** 25. Reverse Nodes in k-Group ***************" << endl;
    const int k = 3;
    ListNode* reverseGroupNode = S.reverseKGroup(head, k);
    S.printNode(reverseGroupNode);

	return 0;
}