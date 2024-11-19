/*
 * @lc app=leetcode.cn id=234 lang=cpp
 * @lcpr version=30204
 *
 * [234] 回文链表
 *
 * https://leetcode.cn/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (55.55%)
 * Likes:    1976
 * Dislikes: 0
 * Total Accepted:    844.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,2,1]'
 *
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,2,1]
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：head = [1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目在范围[1, 10^5] 内
 * 0 <= Node.val <= 9
 *
 *
 *
 *
 * 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
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
class Solution
{
public:
    // 转换成数组
    // bool isPalindrome(ListNode *head)
    // {
    //     vector<int> list;
    //     for (ListNode *p = head; p != nullptr; p = p->next)
    //     {
    //         list.push_back(p->val);
    //     }
    //     for (int i = 0; i < list.size() / 2; i++)
    //     {
    //         if (list[i] != list[list.size() - 1 - i])
    //             return false;
    //     }
    //     return true;
    // }

    // 反转后一半列表，与前一半对比
    // a b C d
    // a b c d e
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode *l1 = head;
        ListNode *l2 = head;
        while (l2 != nullptr && l2->next != nullptr)
        {
            l1 = l1->next;
            l2 = l2->next->next;
        }
        // 此时l1是第二段的head

        // 反转l1
        ListNode *prev = nullptr;
        ListNode *curr = l1;
        while (curr != nullptr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // 比较 head前半段 和 反转后的l1(prev) 是否完全相同
        while (prev != nullptr)
        {
            if (head->val != prev->val)
                return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
