class Solution {
public:
    string reverseWords(string s) {
    //题目： 给定一个字符串，逐个翻转字符串中的每个单词。
    //无空格字符构成一个单词。
    //输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
    //如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
    
        //注： 函数str.erase(it)，每次删除之后，it会自动加一，移到原先删除节点的下一个节点。
        //string类型内部反转，reverse(s.begin(), s.end())。
        // 字符串结尾处需要额外处理，比较容易出错
        //  翻转整个字符串；删除前面的空格；用两个指针it和pre记录字符串中翻转的段落；用flag =1 代表有连续的空格   
       if(s.length() == 0)
            return s; 
        reverse(s.begin(), s.end());
        int flag = 0;
        auto it = s.begin(), pre = s.begin();//it指针向后走，pre指针指向子单词的第一个字符 
        // 删除前面的空格
        while(*it == ' ' && it != s.end())
            s.erase(it);
        
        while(it != s.end()){
            if(*it == ' ' ){
                if(flag == 1){//it指向空格，有重复的空格 删除  
                     s.erase(it);
                     continue;
                }
                else if(flag == 0){//当it指向空格，且flag为0, 就翻转
                     flag = 1;
                     reverse(pre, it);
                }
                    
            } 
            else if(*it != ' ' ){//it指向不为空。 it指向新的子串头 
                if(flag == 1){
                pre = it;
                flag = 0; 
                }
                 
            } 
            it ++;
        }
        //末尾有两种情况，1. 末尾有空格（那么在上面的循环就已经翻转过了最后一个单词，就需要删除最后一个空格）
        //2. 末尾没有空格，需要最后再翻转一次 
        //最后再翻转一次 
        if(flag == 0)
            reverse(pre, it);
        else
            s.erase(s.end() - 1);
        
        return s;
    }
};
