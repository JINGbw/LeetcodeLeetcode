//题目：给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
//换句话说，第一个字符串的排列之一是第二个字符串的子串。

//思路1：//1.对s1全排列 //2.判断有没有是s2子串的 时间超出了 
//思路2：//滑动窗口 
//双指针 
bool checkInclusion(string s1, string s2) {
    int count[256] = { 0 };
    //统计s1中每个字符的出现次数
    for (auto c : s1) count[c]++;
    //如何判断相同：s1中每个字符出现的次数与s2窗口中相同即为相同 
    // len是 
    for (int len = 0, l = 0, r = 0; r < s2.length(); ++r) {
        count[s2[r]]--;
        if (count[s2[r]]>= 0){
        ++len;
        } 
        while (r - l + 1 > len){
           l++;
           count[s2[l]++; 
           if ( count[s2[l]] > 0){
               --len;
           }
        } 
        if (len == s1.length()) return true;
    }
    return false;
}
 
