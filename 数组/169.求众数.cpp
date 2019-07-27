class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //题目：找到数组中出现次数大于n/2的元素。
    
        // 1. 排序
        //时间 O(nlogn)
        //空间 O(1)
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
        //2. 用哈希表
//         unordered_map<int,int> res;
//         for(int i=0; i<nums.size();i++){
//             if (res.count(nums[i])==0){
//                 res[nums[i]]=1;
//                 if(res[nums[i]]>nums.size()/2)
//                     return nums[i];
//             } 
//             else{
//                 res[nums[i]] ++ ;
//                 if(res[nums[i]]>nums.size()/2)
//                     return nums[i];
//             }
                
//         }
//         return -1;
    }
};

//寻找出现次数大于n/2的数字，因为该数字出现的次数全部其他次数的和还要多
//另一个思路：剑指Offer中的，使用两个数字，用一个数记录数组中的一个数字，一个是次数，
//如果下一个数字与保存的数字是一样的，则次数加1，如果不同，就次数减一，如果次数为0，
//就保存下一个数字，把次数设为1，因为我们要找的数字出现的次数比其它全部数字的出现次数之和还要大，
//则要找的数字肯定是组后一次把次数设为1时相应的数字。该方法的时间复杂度为O(n)，空间复杂度为O(1)。

//该题的变种：寻找出现次数等于n/2的数字
//上一种解法在数字个数为偶数的时候就失效了。修改方法为：在数组中随便找一个数字，再对剩下的数字做刚刚的操作
//对比这个数字，和最后得到的数字，再遍历两遍原数组（一共遍历了三次数组复杂度为3n）
