#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode();
        dummyNode->next     = head;

        ListNode *current = dummyNode, *tail = dummyNode;

        for (int i = 0; i < n && tail; ++i) {
            tail = tail->next;
        }

        if (tail == nullptr) return nullptr;

        while (tail->next) {
            current = current->next;
            tail    = tail->next;
        }

        // delete current->next node
        ListNode* tmp = current->next;
        current->next = tmp->next;
        delete tmp;

        return dummyNode->next;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    Solution s;

    int       nums[] = {1};
    ListNode *head = nullptr, *current = nullptr;
    for (int i = 0; i < 1; ++i) {
        ListNode* tmp = new ListNode(nums[i]);
        if (i == 0) {
            head    = tmp;
            current = head;
        } else {
            current->next = tmp;
            current       = tmp;
        }
    }

    auto res = s.removeNthFromEnd(head, 2);

    for (auto c = res; c;) {
        cout << c->val << endl;
        c = c->next;
    }

    return 0;
}