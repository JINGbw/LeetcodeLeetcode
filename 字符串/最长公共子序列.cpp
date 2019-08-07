class LCS {
public:
    int findLCS(string A, int n, string B, int m) {
        // write code here
       int dp[n+1][m+1];
        int maxlen = 0;
        for (int i = 1 ; i<=m ; i++){
            dp[0][i] = 0;
        }
        for (int i = 0 ; i<=n ; i++){
            dp[i][0] = 0;
        }
        for(int i = 1 ; i <=n; i++){
            for(int j = 1 ; j<=m ; j++){
            if (A[i-1]==B[j-1]){
            dp[i][j] = dp[i-1][j-1]+1;
             maxlen = max(maxlen,dp[i][j]);
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            } 
        }
        return maxlen;
  
    }
    
};
// class LCS {
// public:
// 这个下标就是按照数组的下标来的 要注意下标 
//     int findLCS(string A, int n, string B, int m) {
//         vector<vector<int> > dp(m+1,vector<int>(n+1,0));
//         for(int i = 1; i <= m; i++) {
//             for(int j = 1;j <= n ;j++){
//                 if (A[j-1]==B[i-1]){
//                      dp[i][j] = dp[i-1][j-1]+1; 
//                 }
//                 else 
//                      dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
//             }
//         }
//         return dp[m][n];
//     }
    
// };
