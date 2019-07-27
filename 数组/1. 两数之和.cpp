class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //思路：使用哈希表存放每个找到的数和它的下标(找到一对就可以了）
        //给定一个整数数组nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个整数，并返回他们的数组下标
        //时间复杂度：O(1)
        //空间复杂度：O(n)
        unordered_map<int, int> hash;
        vector<int> res = {};
        for(int i = 0 ; i<nums.size(); i++){
            //如果这个数存在于哈希表中，查看是否有和它相加等于target的数 
            if (hash.count(target-nums[i]) ){
                res = {hash[target-nums[i]],i};
                break;
            }
                        
            //如果这个数从来没出现过，就把这个数放入哈希表中
            hash[nums[i]]=i;
        }
      return res;
    }
};
