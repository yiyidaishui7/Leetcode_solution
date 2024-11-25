/*
 * @lc app=leetcode.cn id=374 lang=cpp
 * @lcpr version=30204
 *
 * [374] 猜数字大小
 *
 * https://leetcode.cn/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (52.65%)
 * Likes:    351
 * Dislikes: 0
 * Total Accepted:    199.4K
 * Total Submissions: 378.5K
 * Testcase Example:  '10\n6'
 *
 * 我们正在玩猜数字游戏。猜数字游戏的规则如下：
 *
 * 我会从 1 到 n 随机选择一个数字。 请你猜选出的是哪个数字。
 *
 * 如果你猜错了，我会告诉你，我选出的数字比你猜测的数字大了还是小了。
 *
 * 你可以通过调用一个预先定义好的接口 int guess(int num) 来获取猜测结果，返回值一共有三种可能的情况：
 *
 *
 * -1：你猜的数字比我选出的数字大 （即 num > pick）。
 * 1：你猜的数字比我选出的数字小 （即 num < pick）。
 * 0：你猜的数字与我选出的数字相等。（即 num == pick）。
 *
 *
 * 返回我选出的数字。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 10, pick = 6
 * 输出：6
 *
 *
 * 示例 2：
 *
 * 输入：n = 1, pick = 1
 * 输出：1
 *
 *
 * 示例 3：
 *
 * 输入：n = 2, pick = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 2^31 - 1
 * 1 <= pick <= n
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
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1, r = n;
        int mid = l + (r - l) / 2;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            int res = guess(mid);
            if (res == -1)
                r = mid - 1;
            else if (res == 1)
                l = mid + 1;
            else
                return mid;
        }
        return mid;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 10\n6\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n1\n
// @lcpr case=end

 */
