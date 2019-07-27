//题目：给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//如："A man, a plan, a canal: Panama" 是回文串
class Solution {
public:
    bool isPalindrome(string s) {
    //思路：使用两个指针 ,从字符串的两端向中间走,跳过空格和特殊字符，都转换为大写字母就进行比较。一旦发现不匹配，函数返回false
    //注：c++中   isalnum()用来判断一个字符是否为数字或者字母
                 //toupper() 用来把字母转换为大写字母
    if (s.empty())
            return true;
    int len = s.size();
    if (len==1)
        return true; 
    for (int i= 0, j = len-1 ; j >i; i++ ,j-- ){
            while (isalnum(s[i])==false && i<j ) //如果 i不是数字和字母就跳过 
                i++;
            while (isalnum(s[j])==false && i<j )
                j--;
            if (toupper(s[i]) != toupper (s[j]))
                return false;
        }
        return true;
    }
};
