class Solution {
public:
    //题目：给定两个由小写字母构成的字符串 A 和 B ，
    //只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false 。
    //思路：1. 长度不等则不满足要求
    //2. 遍历字符串并记录 1. 两个字符串对应位置不相同的字符对 2. 两个字符串对应位置相同的字符和数目
    //3. 如果有一对（两个）不相同的字符对，看是否可以互换
    //4. 如果两个字符串完全相同，只要有一个字符重复出现，就满足要求
    //时间复杂度：O(n), 空间复杂度O(n)
    
    bool buddyStrings(string A, string B) {
        int m  = A.size();
        int n = B.size();
        if (m!=n)
            return false;
        vector<pair<int,int> >diff;//存放两个字符串中不同的字符
        unordered_map<char, int> um;//存放两个字符串中相同字符和数目 
        for(int i = 0; i < m ; i++){
            if (A[i]!=B[i]){
                diff.push_back({A[i], B[i]}); 
                if(diff.size()>2)
                    return false;
            }
            else{
                um[A[i]]++;
            }
            
        }
        if (diff.size()==2){//如果有一对（两个）的不同的字符 比较 是否可以互换
            if (diff[0].first == diff[1].second && diff[0].second == diff[1].first)
                return true;
        }
        if (diff.size()==0){
            for(auto & x:um){//对于两个完全相同的字符串，只要有一个字符是重复出现的，就满足要求
                if(x.second >1)
                    return true;
            }
        }
        return false;
    }   
};
