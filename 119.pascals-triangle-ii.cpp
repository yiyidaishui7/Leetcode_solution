/*
 * @lc app=leetcode.cn id=119 lang=cpp
 * @lcpr version=30204
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode.cn/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (69.23%)
 * Likes:    557
 * Dislikes: 0
 * Total Accepted:    325K
 * Total Submissions: 469.5K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
 *
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 *
 *
 *
 *
 *
 * 示例 1:
 *
 * 输入: rowIndex = 3
 * 输出: [1,3,3,1]
 *
 *
 * 示例 2:
 *
 * 输入: rowIndex = 0
 * 输出: [1]
 *
 *
 * 示例 3:
 *
 * 输入: rowIndex = 1
 * 输出: [1,1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 0 <= rowIndex <= 33
 *
 *
 *
 *
 * 进阶：
 *
 * 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？
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
    // 求解第i行，只用知道i-1行内容就可以，滚动数组
    // 自己解法，分了rowIndex奇偶两种，代码重复了
    // vector<int> getRow(int rowIndex)
    // {
    //     vector<int> yhRow1;
    //     vector<int> yhRow2;
    //     for (int i = 0; i <= rowIndex; i++)
    //     {
    //         if (i % 2 == 0)
    //         {
    //             yhRow1.resize(i + 1);
    //             for (int j = 0; j <= i; j++)
    //             {
    //                 if (j == 0 || j == i)
    //                 {
    //                     yhRow1[j] = 1;
    //                 }
    //                 else
    //                 {
    //                     yhRow1[j] = yhRow2[j - 1] + yhRow2[j];
    //                 }
    //             }
    //         }
    //         else
    //         {
    //             yhRow2.resize(i + 1);
    //             for (int j = 0; j <= i; j++)
    //             {
    //                 if (j == 0 || j == i)
    //                 {
    //                     yhRow2[j] = 1;
    //                 }
    //                 else
    //                 {
    //                     yhRow2[j] = yhRow1[j - 1] + yhRow1[j];
    //                 }
    //             }
    //         }
    //     }
    //     return (rowIndex % 2 == 0) ? yhRow1 : yhRow2;
    // }

    vector<int> getRow(int rowIndex)
    {
        vector<int> prev, curr;
        for (int i = 0; i <= rowIndex; i++)
        {
            curr.resize(i + 1);
            curr[0] = curr[i] = 1;
            for (int j = 1; j < i; j++)
            {
                curr[j] = prev[j - 1] + prev[j];
            }
            prev = curr;
        }
        return curr;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
