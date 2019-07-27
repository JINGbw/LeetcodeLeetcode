class Solution {
public:
    int uniquePaths(int m, int n) {
//         //题目：一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//         //机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。问总共有多少条不同的路径？
//         //思路：走到当前点只有两种情况（从上面走下来，从左半走过来）dp[i][j]= dp[i-1][j] + dp[i][j-1] 
//         //因为不能向左移动和向上移动，第一行和第一列只会有一种走法,所以dp数组的第一行和第一列都是1
//         //空间时间复杂度：O(M*N)
//         vector<vector<int> >dp(m,vector<int>(n,1));
//         for(int i =1; i< m ; i++){
//          for(int j =1; j < n; j++){
//                 dp[i][j]=dp[i-1][j] + dp[i][j-1];
//             }
//         }
//         return dp[m-1][n-1];
//     }
    //优化：只使用一个一维辅助数组（长度与该列的长度相同）
    //dp[0]一直是1，表示每一行最左边的dp,后面的dp[i]保存的这行这个位置的上一行位置，代表从上往下的方向。
     vector<int>  dp(n,1 );
        for(int i =1; i< m ; i++){
         for(int j =1; j< n; j++){
                dp[j]+=dp[j-1];
            }
        }
        return dp[n-1];
    }

};
