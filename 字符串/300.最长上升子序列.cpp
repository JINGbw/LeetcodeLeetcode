class Solution {
public:
//     int lengthOfLIS(vector<int>& nums) {
//         //题目：数组中的最长上升子序列的长度（最长上升子序列不一定是连续的）
//         //动态规划数组 dp[i]存放以i为结尾的最长上升子序列的长度,遍历i前的所有数字，找到最长上升子序列的长度
//         //时间复杂度：O(n^2) 有两个 n  的循环。
//         //空间复杂度：O(n)，用了大小为 n 的矩阵 dp。
//         if (nums.empty())
//             return 0;
//         vector<int>dp(nums.size(),1);
        
//         for(int i = 1 ; i<nums.size() ;i++){
//             for(int j = 0 ; j<i;j++){
//                 if (nums[i]>nums[j])
//                     dp[i]=max(dp[i],dp[j]+1);
//             }
            
//         }
//         return *max_element(dp.begin(),dp.end());
//     }
    
    
    //上面的解释是时间复杂度为O(n^2)的解法，还有另一种时间复杂度为O(nlogn)的解法
    //1. 用一个辅助数组dp(长度为n)，用来存放 最终的 最长上升子序列的 第i个 。
                //1. dp[i]中的数字是单调递增的。 
    //2. 一个数字记录最终的序列长度 len 
    //3. 利用一个辅助函数，用二分法来查找dp数组中第一个比目标值大的数字的下标。
     int findLongest(vector<int> A, int n) { 
        vector<int> dp(n);
        dp[0] = A[0];
        int len = 1 ;
        for(int i = 1; i< n ;i++){
            //如果 A[i]大于 dp中最后一个元素 则直接插入到dp数组末尾  
            if (A[i]> dp[len-1]){ 
                 dp[len++]= A[i] ; 
            }
            else{
                //替换dp数组中第一个比A[i]大的数字
                //找到 dp中第一个比A[i]大的数的下标 
                int pos = binary(A[i],dp,0,len);
                dp[pos] = A[i];
            }
        }
        return len;
    }
    private:
    //返回 dp 中第一个大于key 的元素的下角标  
    //大于dp的可能有很多个，返回最左边的下角标
    int binary(int key,vector<int>&dp,int left,int right  ){  
 
    while (left <= right) {
        int mid = (left + right) / 2;
        if (dp[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
    }
    
