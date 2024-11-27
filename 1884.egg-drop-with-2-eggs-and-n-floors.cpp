/*
 * @lc app=leetcode.cn id=1884 lang=cpp
 * @lcpr version=30204
 *
 * [1884] 鸡蛋掉落-两枚鸡蛋
 *
 * https://leetcode.cn/problems/egg-drop-with-2-eggs-and-n-floors/description/
 *
 * algorithms
 * Medium (78.18%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    25.7K
 * Total Submissions: 32.9K
 * Testcase Example:  '2'
 *
 * 给你 2 枚相同 的鸡蛋，和一栋从第 1 层到第 n 层共有 n 层楼的建筑。
 *
 * 已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都 会碎 ，从 f 楼层或比它低 的楼层落下的鸡蛋都 不会碎 。
 *
 * 每次操作，你可以取一枚 没有碎 的鸡蛋并把它从任一楼层 x 扔下（满足 1 <= x <=
 * n）。如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中 重复使用 这枚鸡蛋。
 *
 * 请你计算并返回要确定 f 确切的值 的 最小操作次数 是多少？
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 2
 * 输出：2
 * 解释：我们可以将第一枚鸡蛋从 1 楼扔下，然后将第二枚从 2 楼扔下。
 * 如果第一枚鸡蛋碎了，可知 f = 0；
 * 如果第二枚鸡蛋碎了，但第一枚没碎，可知 f = 1；
 * 否则，当两个鸡蛋都没碎时，可知 f = 2。
 *
 *
 * 示例 2：
 *
 * 输入：n = 100
 * 输出：14
 * 解释：
 * 一种最优的策略是：
 * - 将第一枚鸡蛋从 9 楼扔下。如果碎了，那么 f 在 0 和 8 之间。将第二枚从 1 楼扔下，然后每扔一次上一层楼，在 8 次内找到 f
 * 。总操作次数 = 1 + 8 = 9 。
 * - 如果第一枚鸡蛋没有碎，那么再把第一枚鸡蛋从 22 层扔下。如果碎了，那么 f 在 9 和 21 之间。将第二枚鸡蛋从 10
 * 楼扔下，然后每扔一次上一层楼，在 12 次内找到 f 。总操作次数 = 2 + 12 = 14 。
 * - 如果第一枚鸡蛋没有再次碎掉，则按照类似的方法从 34, 45, 55, 64, 72, 79, 85, 90, 94, 97, 99 和 100
 * 楼分别扔下第一枚鸡蛋。
 * 不管结果如何，最多需要扔 14 次来确定 f 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 1000
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
    // 假设第一个鸡蛋在第k层扔
    // 如果碎了，说明在[0,k-1] 还需要在1，2，…… k-1层依次扔 共k-1次
    // 如果没碎，说明在[k,n] 此时仍有两个鸡蛋 等价于2个鸡蛋，n-k层 f(n-k)次
    // f(n) = min(f(n), max(k-1,f(n-k))+1)
    int twoEggDrop(int n)
    {
        vector<int> dp(n + 1, INT_MAX / 2);
        // 注意！这次初始化不能初始化为0！因为后面求min
        // 同时用INT_MAX可能会导致溢出 所以可以用INT_MAX/2 INT_MAX-1
        dp[0] = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int k = 0; k <= i; k++)
            {
                dp[i] = min(dp[i], max(k - 1, dp[i - k]) + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 100\n
// @lcpr case=end

 */
