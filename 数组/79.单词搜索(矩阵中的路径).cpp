        //题目：搜索二维数组中是否存在一个单词，使用回溯法，利用一个辅助数组来记录矩阵中的当前元素是否被访问过
        //这是一个使用回溯算法解决的问题，涉及的知识点有 DFS 和状态重置
        //遍历board中每一个元素，判断与word中的第一个字母是否相同，
//如果相同则在当前位置上去搜索上下左右相邻的单元格的元素是否和当前字母的下一个字母相同，
//不在搜索范围内或者字母不同就返回false，当搜索的字母数等于word的长度时，也就表明在board找到了这个word。
//注意每次判断一个字母要标记当前位置以搜索过，以防止字母重复利用。
//直接更改board元素，以便在后续的判断中不会重复判断此位置，在搜索结束后改回来就可以了。
        
//递归三要素：递归的定义 递归的出口 递归的拆解
    
    
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        h = board.size();
        w = board[0].size();
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; ++j){
                if(searchexist(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    //递归的定义:board[x][y] 是否可以找到 word中第n个词 
    int searchexist(vector<vector<char>>& board, string &word, int n, int x, int y){
        //递归的出口: 没找到：超出数组边界/数组该位置已经走过
        //找到了：超出word边界
        
        if(x < 0 || x > h-1 || y < 0 || y > w-1 || word[n] != board[x][y])
            return 0;
        if(n == word.length()-1)
            return 1;
        char temp = board[x][y];
        board[x][y] = 0;
        int flag = searchexist(board, word, n+1, x+1, y)
                 ||searchexist(board, word, n+1, x-1, y)
                 ||searchexist(board, word, n+1, x, y+1)
                 ||searchexist(board, word, n+1, x, y-1);
        board[x][y] = temp;
        return flag;
    }
private:
    int h, w;
};




















