#include <iostream>

using namespace std;

struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return nullptr;
        if (list1 && !list2) return list1;
        if (!list1 && list2) return list2;

        ListNode *dummyNode = new ListNode(), *current = dummyNode;
        ListNode *first = list1, *second = list2;
        while (first && second) {
            if (first->val < second->val) {
                current->next = first;
                first         = first->next;
            } else {
                current->next = second;
                second        = second->next;
            }

            current = current->next;
        }

        if (first) current->next = first;
        if (second) current->next = second;

        return dummyNode->next;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    int       nums[] = {1, 2, 4};
    ListNode *head = nullptr, *current = nullptr;
    for (int i = 0; i < 3; ++i) {
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
        cout << c->val << endl;
        c = c->next;
    }

    int numss[] = {1, 3, 4};
    head = nullptr, current = nullptr;
    for (int i = 0; i < 3; ++i) {
        ListNode* tmp = new ListNode(numss[i]);
        if (i == 0) {
            head    = tmp;
            current = head;
        } else {
            current->next = tmp;
            current       = tmp;
        }
    }

    ListNode* second = head;
    for (auto c = second; c;) {
        cout << c->val << endl;
        c = c->next;
    }

    Solution s;
    auto     res = s.mergeTwoLists(first, second);
    for (auto c = res; c;) {
        cout << c->val << endl;
        c = c->next;
    }
}