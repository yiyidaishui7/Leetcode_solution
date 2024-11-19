/*
 * @lc app=leetcode.cn id=169 lang=cpp
 * @lcpr version=30204
 *
 * [169] 多数元素
 *
 * https://leetcode.cn/problems/majority-element/description/
 *
 * algorithms
 * Easy (66.58%)
 * Likes:    2331
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 *
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [3,2,3]
 * 输出：3
 *
 * 示例 2：
 *
 * 输入：nums = [2,2,1,1,1,2,2]
 * 输出：2
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 *
 *
 *
 * 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
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
    // int majorityElement(vector<int> &nums)
    // {
    //     //ID136做法 哈希表存储出现次数 时间O(n) 空间O(n)
    //     unordered_map<int, int> map;
    //     for (int num : nums)
    //     {
    //         map[num]++;
    //     }
    //     for (auto &[num, count] : map)
    //     {
    //         if (count > (nums.size() / 2))
    //             return num;
    //     }
    //     return 0;
    // }

    // Boyer-Moore Voting Algorithm 摩尔投票

    // 因为要找到的数>n/2，所以是唯一的
    // 此数和所有非此数一一抵消，最后还是此数最多
    //
    int majorityElement(vector<int> &nums)
    {
        int count = 0, candidate = nums[0];
        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
                count++;
            }
            else if (candidate == num)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return candidate;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,1,1,2,2]\n
// @lcpr case=end

 */
