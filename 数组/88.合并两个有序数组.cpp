class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //从后往前合并
      int i = m-1;
      int j = n-1;
      int sum = m + n -1 ;
      //如果j = 0 了，说明存完了，
      //如果i = 0 了 , 需要把 nums2中的全都拷贝过来 
      while(i>=0  && j >=0 ){
        if(nums1[i]>nums2[j]){
          nums1[sum-- ] =  nums1[i--];
        }
        else {
          nums1[sum-- ] = nums2[j--];
        }
      }
      while(j>= 0 ){
        nums1[sum-- ] = nums2[j--];
      }
    }
};
