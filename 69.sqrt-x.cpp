/*
 * @lc app=leetcode.cn id=69 lang=cpp
 * @lcpr version=30204
 *
 * [69] x 的平方根
 *
 * https://leetcode.cn/problems/sqrtx/description/
 *
 * algorithms
 * Easy (38.64%)
 * Likes:    1606
 * Dislikes: 0
 * Total Accepted:    982.8K
 * Total Submissions: 2.5M
 * Testcase Example:  '4'
 *
 * 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
 *
 * 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
 *
 * 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：x = 4
 * 输出：2
 *
 *
 * 示例 2：
 *
 * 输入：x = 8
 * 输出：2
 * 解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= x <= 2^31 - 1
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
    // 袖珍计算器
    // 根x = x^1/2 = e^lh(x^1/2) = e^1/2lnx
    // int mySqrt(int x)
    // {
    //     if (x == 0)
    //         return 0;
    //     int ans = exp(0.5 * log(x)); // ans是整数部分

    //     // return ((long long)(ans * ans) <= x) ? ans : (ans + 1); // long long否则可能overflow
    //     return (long long)(ans + 1) * (ans + 1) <= x ? (ans + 1) : ans;

    //     // x=10:
    //     // log(10)≈2.30258.
    //     // 0.5×log(10)≈1.15129.
    //     // exp(1.15129)≈3.162.
    //     // Truncating 3.162 gives ans=3.
    //     // But ans×ans=9, which satisfies 9≤10, so no issue here.
    // }

    // 二分
    int mySqrt(int x)
    {
        int ans = 0;
        long long l = 0, r = x, mid = 0;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (mid * mid <= x)
            {
                l = mid + 1;
                ans = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */
