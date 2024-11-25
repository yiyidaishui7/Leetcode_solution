/*
 * @lc app=leetcode.cn id=278 lang=cpp
 * @lcpr version=30204
 *
 * [278] 第一个错误的版本
 *
 * https://leetcode.cn/problems/first-bad-version/description/
 *
 * algorithms
 * Easy (45.77%)
 * Likes:    1029
 * Dislikes: 0
 * Total Accepted:    509.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '5\n4'
 *
 *
 * 你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。
 *
 * 假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
 *
 * 你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version
 * 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。
 *
 *
 * 示例 1：
 *
 * 输入：n = 5, bad = 4
 * 输出：4
 * 解释：
 * 调用 isBadVersion(3) -> false
 * 调用 isBadVersion(5) -> true
 * 调用 isBadVersion(4) -> true
 * 所以，4 是第一个错误的版本。
 *
 *
 * 示例 2：
 *
 * 输入：n = 1, bad = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= bad <= n <= 2^31 - 1
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
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 1, r = n, mid = l + (r - l) / 2;
        while (l <= r)
        {
            if (isBadVersion(mid)) // mid==false, [l,mid]
                r = mid - 1;
            else
                l = mid + 1;
            mid = l + (r - l) / 2;
        }
        // 区间为一个点[l,r]，l==r==mid
        return mid;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n4\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */
