/*
* 
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* leetcode 1 start */
/*
 * leetcode 1.两数之和
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.count(target - nums[i]))
                return {hash[target - nums[i]], i};
            hash[nums[i]] = i;
        }
        return {-1, -1};
    }
};
