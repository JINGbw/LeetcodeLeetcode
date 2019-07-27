class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    //题目：编写一个函数来查找字符串数组中的最长公共前缀。
    //如果不存在公共前缀，返回空字符串 ""。
        //当做矩阵来遍历 strs有j行i列
        //如果指针没有超过第i行的长度，并且第j行第i个字母与第一行第i个字母相同，就继续向下找。 
        if(strs.empty()) 
            return "";
        for(int j=0; j<strs[0].size(); ++j) {//j列
            for(int i=0; i<strs.size(); ++i) {//i行
                if(j >=strs[i].size() || strs[i][j] != strs[0][j]) 
                    return strs[i].substr(0,j);
            } 
        }//如果遍历结束前没有返回结果的话，说明第一个单词就是公共前缀
        return strs[0];
    }
};
