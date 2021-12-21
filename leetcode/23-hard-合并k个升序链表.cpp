#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    struct node {
        int       val;
        ListNode* ptr;
        bool      operator<(const node& right) const { return val > right.val; }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummyNode = new ListNode(), *tail = dummyNode;

        priority_queue<node> h;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) h.push({lists[i]->val, lists[i]});
        }

        while (!h.empty()) {
            auto top = h.top();
            h.pop();

            tail->next = top.ptr;
            tail       = tail->next;

            if (top.ptr->next) h.push({top.ptr->next->val, top.ptr->next});
        }

        return dummyNode->next;
    }
};
// @lc code=end

int main() {
    int       nums[] = {1, 4, 5};
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
        cout << c->val << " ";
        c = c->next;
    }
    cout << endl;

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
        cout << c->val << " ";
        c = c->next;
    }
    cout << endl;

    int numsss[] = {2, 6};
    head = nullptr, current = nullptr;
    for (int i = 0; i < 2; ++i) {
        ListNode* tmp = new ListNode(numsss[i]);
        if (i == 0) {
            head    = tmp;
            current = head;
        } else {
            current->next = tmp;
            current       = tmp;
        }
    }
    ListNode* third = head;
    for (auto c = third; c;) {
        cout << c->val << " ";
        c = c->next;
    }
    cout << endl;

    Solution          s;
    vector<ListNode*> lists = {first, second, third};
    auto              res   = s.mergeKLists(lists);
    for (auto c = res; c;) {
        cout << c->val << " ";
        c = c->next;
    }
    cout << endl;
}