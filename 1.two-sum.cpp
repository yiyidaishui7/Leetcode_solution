// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30204
 *
 * [1] 两数之和
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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 哈希表
        // 遍历数组 找target-nums[i]有没有在哈希表的键里
        // 如果没有 存入这个数nums[i]和下标i
        // 如果有 输出{当前坐标，target-nums[i]的坐标}
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.count(target - nums[i]))
            {
                return {i, map[target - nums[i]]};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */
