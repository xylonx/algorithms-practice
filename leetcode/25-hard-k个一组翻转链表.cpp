#include <iostream>
#include <stack>
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
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head), *cur = dummy;

        stack<ListNode*> s;
        while (cur) {
            ListNode* pre = cur;
            for (int i = 0; i < k; ++i) {
                if (cur->next) {
                    s.push(cur->next);
                    cur = cur->next;
                } else {
                    break;
                }
            }

            if (s.size() < k) {
                break;
            }

            ListNode* tail = cur->next;
            while (!s.empty()) {
                ListNode* tmp = s.top();
                s.pop();
                pre->next = tmp;
                pre       = pre->next;
            }
            pre->next = tail;
            cur       = pre;
        }

        return dummy->next;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    vector<int> nums = {1, 2, 3, 4, 5};
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
    ListNode* res = s.reverseKGroup(head, 3);
    for (auto c = res; c;) {
        cout << c->val << " ";
        c = c->next;
    }
    cout << endl;

    return 0;
}