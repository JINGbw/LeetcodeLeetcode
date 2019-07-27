class Solution {
public:
    int search(vector<int>& nums, int target) {
        //题目：在旋转前是升序的旋转数组中寻找目标值，返回目标值的索引
        //思路：直接用二分法
        //1.[mid]==target，找到了
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
            if(nums[mid]<nums[right]){
                if (nums[mid]<target&&target<=nums[right])
                    left = mid+1;
                else 
                    right = mid-1;
            }
            else {
                if(nums[mid]>target&&target>=nums[left])
                    right = mid-1;
                else 
                    left = mid+1;
            }  
        }
        return -1;
    }
};
