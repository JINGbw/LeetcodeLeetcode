class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      //题目是找到所有满足三数之和且不重复的三元组
      //思路：转化为两数之和
      //先将原数组排序，从两端加和求解
       //时间复杂度：O(N^2)
        vector<vector<int>> res ={};
        if (nums.size()==0)
            return res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size(); i++){
            if (i!=0&&nums[i]==nums[i-1])
                continue;
            int k = nums.size()-1;
            int j = i+1;//固定最左边的数字，用两个指针，在剩下的位置两边夹
            //k是从最后一个元素向前找
            //j是从i后面一个元素向后找 
            // 如果该数字和前一个数值相同，跳过，（第一个数除外）
            while (j<k){
                if (nums[i]+nums[j]+nums[k]==0){
                res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while (j<k&&nums[j]==nums[j-1])
                        j++;
                    while (j<k&&nums[k]==nums[k+1])
                        k--;
                }
                else if (nums[i]+nums[j]+nums[k]<0)
                    j++;
                else 
                    k--; 
            }
        }
        return res;
    }
};
