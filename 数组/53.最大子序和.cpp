class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //题目：找到具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
        //思路：动态规划，dp[i]存放以第i个数字为结尾的最大子序和 
        //时间复杂度：O(n)
        vector<int>dp(nums.size());
        dp[0] = nums[0];
        for(int i = 1 ; i<nums.size();i++){
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
        }
        return *max_element(dp.begin(),dp.end());

//         //思路：用一个数local当前最大和 global存放全局的最大和
//         //一旦local小于零了，那么这之前的都直接抛弃，
//         //时间复杂度：O(n)
//          int local = nums[0] ;
//          int global = nums[0] ;
//         for(int i = 1; i<nums.size();i++){
//             local = max(nums[i]+local,nums[i]);
//             global = max(global,local);
//         }
//         return global;
    
    }
};
