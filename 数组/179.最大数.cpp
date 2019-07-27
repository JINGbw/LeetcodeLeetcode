class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //题目：给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。返回字符串
        //sort函数自定义排序算法，将数字转换为字符串，再比较
        //如果有多个0，0一定出现在最右端，如果最高位不是0，就不需要处理，如果最高位为0，说明所有的位都是0 
        //数字转字符串： to_string(a)
        //时间复杂度 O(nlogn)
        //空间复杂度 O(n)
        sort(nums.begin(),nums.end(),[](int a,int b){
            string stra = to_string(a);
            string strb = to_string(b);
            return (stra + strb)>(strb+stra);
        });
        string s;
        for( auto it = nums.begin(); it !=nums.end(); it++ ){
            s+=to_string(*it);
        }
        if(s[0]=='0')
            return "0";
        else
            return s;
    }
};
