/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=30204
 *
 * [344] 反转字符串
 *
 * https://leetcode.cn/problems/reverse-string/description/
 *
 * algorithms
 * Easy (80.57%)
 * Likes:    922
 * Dislikes: 0
 * Total Accepted:    972.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
 *
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = ["h","e","l","l","o"]
 * 输出：["o","l","l","e","h"]
 *
 *
 * 示例 2：
 *
 * 输入：s = ["H","a","n","n","a","h"]
 * 输出：["h","a","n","n","a","H"]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] 都是 ASCII 码表中的可打印字符
 *
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
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        // 双指针
        // s[0] s[n-1], s[1] s[n-2]
        int l = 0, r = s.size() - 1;
        while (l <= r)
        {
            swap(s[l++], s[r--]);
        }
    }

    // void reverseString(vector<char> &s)
    // {
    //     // 递归 memory limit exceeded
    //     int n = s.size();
    //     if (n <= 1)
    //         return;

    //     else
    //     {
    //         swap(s[0], s[n - 1]);
    //         vector<char> sub(s.begin() + 1, s.end() - 1);
    //         reverseString(sub);
    //         for (int i = 0; i < n - 2; i++)
    //         {
    //             s[i + 1] = sub[i];
    //         }
    //     }
    // }
};
// @lc code=end

/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */
