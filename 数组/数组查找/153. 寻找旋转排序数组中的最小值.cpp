class Solution {
public:
    int findMin(vector<int>& nums) {
        //题目：找到旋转排序数组的最小值（原来数组按照升序排列），且数组没有重复元素
        //思路：利用二分法 
        //1. 如果长度为1 
        //2. 如果旋转偶数次
        //3. 二分法循环，边界条件[mid]和两边的[mid-1]和[mid+1]比较
        //4. 左边有序（到右边找） 右边有序（到左边找）
        //时间复杂度：和二分搜索一样 O(logN)
        //空间复杂度： O(1)
        int left = 0;
        int right = nums.size()-1;
        if (nums.size()==1)
            return nums[0];
        if(nums[left]<nums[right]){
            return nums[left];
        }
        //循环
        while(left<=right){
            int mid = (left+right)/2;
            if (nums[mid] > nums[mid+1])
                return nums[mid+1];
            if (nums[mid] < nums[mid-1])
                return nums[mid];
            if (nums[left] < nums[mid])
                left = mid+1;
            else 
                right = mid-1;
        }
        return -1; 
    }
};
