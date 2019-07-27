class Solution {
public:
    bool isValid(string s) {
        //题目：判断判断字符串是否有效 （只包括 '('，')'，'{'，'}'，'['，']' ）左右括号必须闭合且必须以正确的顺序闭合
        //思路：使用栈  
        //时间复杂度：O(n)每一个字符都压入或者弹出过 
        //空间复杂度：O(n) 最差空间复杂度是要把所有括号都推到栈上
        stack<char> stack; 
        for(int i = 0; i < s.size(); i++){
            
            if( s[i] == '(' || s[i] == '{' || s[i] == '[')
                stack.push(s[i]);
             else{
                if( stack.size() == 0 )
                    return false;

             
              char c = stack.top();
              stack.pop();
                 
             char match; 
             if (s[i]== ')' ){
                 match= '(' ; 
             }
             else if (s[i]==']'){
                match ='['; 
             }
             else {
                 match = '{';
             }
             
             if (c != match)
                 return false;
         }   
        
        }
        
          if(stack.size() !=0)
             return false;
       
       return true; 
    }
};
