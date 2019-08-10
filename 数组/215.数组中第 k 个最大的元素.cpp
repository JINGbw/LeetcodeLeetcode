class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //题目：在未排序的数组中找到第 k 个最大的元素。
        //思路：用最小堆存放当前最大的K个元素（比最小堆中最小的大，就放入小顶堆中 ）
        //如果该元素比堆顶元素大，压入堆中，删除堆中的最小元素，调整堆 以保证堆中的K个元素总数最大的K个 
        if (k>nums.size()||nums.empty())
            return -1;
        vector<int >res(nums.begin(),nums.begin()+k);
        make_heap(res.begin(),res.end(),greater<int>());
        for(int i = k ; i<nums.size() ; i++){
            
            if (nums[i]>res[0]){  
                pop_heap(res.begin(),res.end(),greater<int>());//将最小元素放到堆最后
                res.pop_back();//删除当前最小的元素
                res.push_back(nums[i]);//将新元素，放在堆最后
                push_heap(res.begin(),res.end(),greater<int>());// 调整堆 
            }
        }
        // sort_heap(res.begin(),res.end());
        return res.front();
    }
};
