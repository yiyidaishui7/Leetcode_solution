/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括号
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
// stack
// if(){}[], push
// if ) } ], pop, until ({[

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        if (s.empty())
            return true;
        if (s.length() % 2 != 0)
            return false;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stack.push(c);
            }
            else
            {
                //!!!!!注意要加判断是否为空，否则top无法访问到
                if (stack.empty())
                    return false;
                char top = stack.top();
                if (
                    (c == ')' && top == '(') ||
                    (c == ']' && top == '[') ||
                    (c == '}' && top == '{'))
                    stack.pop();
                else
                    return false;
            }
        }
        return stack.empty();
    }
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

 */
