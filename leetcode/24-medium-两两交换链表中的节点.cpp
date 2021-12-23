#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *pre = nullptr, *first = nullptr, *second = nullptr;

        pre = dummy;
        if (pre && pre->next) first = pre->next;
        if (first) second = first->next;

        while (first && second) {
            pre->next    = second;
            first->next  = second->next;
            second->next = first;

            pre   = pre->next->next;
            first = pre->next, second = nullptr;
            if (first) second = first->next;
        }

        return dummy->next;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3, 4};
    ListNode *  head = nullptr, *current = nullptr;
    for (int i = 0; i < nums.size(); ++i) {
        ListNode* tmp = new ListNode(nums[i]);
        if (i == 0) {
            head    = tmp;
            current = head;
        } else {
            current->next = tmp;
            current       = tmp;
        }
    }
    ListNode* first = head;
    for (auto c = first; c;) {
        cout << c->val << " ";
        c = c->next;
    }
    cout << endl;

    Solution  s;
    ListNode* res = s.swapPairs(head);
    for (auto c = res; c;) {
        cout << c->val << " ";
        c = c->next;
    }
    cout << endl;

    return 0;
}