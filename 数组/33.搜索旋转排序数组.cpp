class Solution {
public:
    int search(vector<int>& nums, int target) {
        //题目：在旋转前是升序的旋转数组中寻找目标值，返回目标值的索引
        //思路：直接用二分法
        //1.[mid]==target，找到了
        //mid在有序的一侧/无序的一侧
        //2. [mid]<[r]
            // target在有序的一侧
            //target在无序的一侧
        //3. [mid]>[l]
         // target在有序的一侧
            //target在无序的一侧 
        //时间复杂度：O(logN)
        //空间复杂度：O(1) 
        if(nums.empty())
            return -1;
        int left = 0;
        int right = nums.size()-1; 
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]==target)
                return mid;
            //1. mid在有序的一侧还是无序的一侧
            //2. 目标在mid左边还是右边
            if(nums[mid]<nums[right]){
                //mid在有序的一侧
                if (nums[mid]<target&&target<=nums[right])
                    //目标在mid右边
                    left = mid+1;
                else 
                    //目标在mid左边
                    right = mid-1;
            }
            else {
                //mid在无序的一边
                if(nums[mid]>target&&target>=nums[left])
                    right = mid-1;
                else 
                    left = mid+1;
            }  
        }
        return -1;
    }
};
