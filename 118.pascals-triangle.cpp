/*
 * @lc app=leetcode.cn id=118 lang=cpp
 * @lcpr version=30204
 *
 * [118] 杨辉三角
 *
 * https://leetcode.cn/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (76.75%)
 * Likes:    1200
 * Dislikes: 0
 * Total Accepted:    584.2K
 * Total Submissions: 761.2K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
 *
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 *
 *
 *
 *
 *
 * 示例 1:
 *
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 *
 *
 * 示例 2:
 *
 * 输入: numRows = 1
 * 输出: [[1]]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= numRows <= 30
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
    // yhRec[i][j] = yhRec[i-1][j-1]+yhRec[i-1][j];
    // if(j==0||i) yhRec[i][j]=1;
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> yhRec(numRows); // 注意初始化yhRec
        for (int i = 0; i < numRows; i++)
        {
            // yhRec[i].resize(i + 1);
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                    // yhRec[i][j] = 1;
                    yhRec[i].push_back(1);
                else
                    // yhRec[i][j] = yhRec[i - 1][j - 1] + yhRec[i - 1][j];
                    yhRec[i].push_back(yhRec[i - 1][j - 1] + yhRec[i - 1][j]);
            }
        }
        return yhRec;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
