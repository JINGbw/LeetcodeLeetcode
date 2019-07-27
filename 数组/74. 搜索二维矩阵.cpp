class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //题目： 二维矩阵（从左到右升序，每行的第一个整数大于前一行的最后一个整数。）是否有目标值？
        //思路： 1. 是否超出边界
        // 2. 先找该数字在哪一行，再找这个数字在哪一列
        if (matrix.empty()||matrix[0].empty()) return false;
        if (target<matrix[0][0]||target>matrix.back().back())
            return false;
        int m = matrix.size();//行
        int n = matrix[0].size();//列
        //先找到在哪一行 (找到比目标数字小的后一个)
        int left = 0, right = m-1;
        while(left <= right){
            
            int mid = (right+left)/2;
            
            if (matrix[mid][0] == target)
                return true;
            else if (target > matrix[mid][0])
                left = mid+1;
            else if (target < matrix[mid][0])
                right = mid-1 ;
             
        }
        int resrow = right;
        // 再找出在哪一列
        left = 0 ,right = n-1;
        while (left<=right){
        int mid = (right+left)/2;
         if (matrix[ resrow][mid] == target)
             return true;
        else if (target < matrix[resrow][mid])
            right = mid -1;
        else 
           left = mid+1 ;
            
        }
        return false;
    }
};
