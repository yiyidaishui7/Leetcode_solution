/*
 * @lc app=leetcode.cn id=367 lang=cpp
 * @lcpr version=30204
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode.cn/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (45.10%)
 * Likes:    589
 * Dislikes: 0
 * Total Accepted:    297.1K
 * Total Submissions: 658.7K
 * Testcase Example:  '16'
 *
 * 给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
 *
 * 完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。
 *
 * 不能使用任何内置的库函数，如  sqrt 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：num = 16
 * 输出：true
 * 解释：返回 true ，因为 4 * 4 = 16 且 4 是一个整数。
 *
 *
 * 示例 2：
 *
 * 输入：num = 14
 * 输出：false
 * 解释：返回 false ，因为 3.742 * 3.742 = 14 但 3.742 不是一个整数。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num <= 2^31 - 1
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
    bool isPerfectSquare(int num)
    {
        if (num == 1)
            return true;
<<<<<<< HEAD
        long l = 1, r = num / 2, mid = l + (r - l) / 2; // mid*mid的结果可能会溢出int
=======
        long l = 1, r = num / 2, mid = l + (r - l) / 2; // mid*mid的结果可能会溢出
>>>>>>> ab85fe06481760823c4a533c8b31d47c2fc2fb30
        while (l <= r)
        {
            if (mid * mid == num)
                return true;
            if (mid * mid < num)
                l = mid + 1;
            else
                r = mid - 1;
            mid = l + (r - l) / 2;
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 16\n
// @lcpr case=end

// @lcpr case=start
// 14\n
// @lcpr case=end

 */
