//题目：求两个字符串的公共子串的长度 
//dp[i][j]存放的是str1[i]和str2[j]所在公共子串的长度
//1、把两个字符串分别以行和列组成一个二维矩阵。
//2、比较二维矩阵中每个点对应行列字符中否相等，相等的话值设置为1，否则设置为0。
//3、通过查找出值为1的最长对角线就能找到最长公共子串。
//为了进一步优化算法的效率，我们可以再计算某个二维矩阵的值的时候顺便计算出来当前最长的公共子串的长度，
//即某个二维矩阵元素的值由item[i][j]=1演变为item[i][j]=1 +item[i-1][j-1]，这样就避免了后续查找对角线长度的操作了。
//假设两个字符串为str1和str2，它们的长度分别为n和m。d[i][j]表示str1中前i个字符与str2中前j个字符分别组成的两个前缀字符串的最长公共长度。
//这样就把长度为n的str1和长度为m的str2划分成长度为i和长度为j的子问题进行求解。状态转移方程如下：

//1. dp[0][j] = 0; (0<=j<=m)
//2. dp[i][0] = 0; (0<=i<=n)
//3. dp[i][j] = dp[i-1][j-1] +1; (str1[i] == str2[j])
//4. dp[i][j] = 0; (str1[i] != str2[j])
//因为最长公共子串要求必须在原串中是连续的，所以一但某处出现不匹配的情况，此处的值就重置为0。


//时间复杂度： 

    int findLongest(string A, int n, string B, int m) {
        // write code here
        int dp[m][n];
        int maxlen = 0;
        for(int i = 0 ; i < n ; i++ ){
            //第一行
            dp[0][i] = (A[i]==B[0])?1:0 ;
        }
        for(int i = 1 ; i < m ; i++ ){
            //第一列
            dp[i][0] =(B[i] == A[0] ) ? 1:0 ; 
        }
        for(int i = 1; i < m ; i++ ){
            for(int j = 1; j< n; j++){
                if (A[j]==B[i]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxlen = max(maxlen,dp[i][j] );
                }
                 else {
                     dp[i][j] = 0;
                 }
            }
        }
        return maxlen;
        
    }

// class LongestSubstring {
// public:
//     int findLongest(string A, int n, string B, int m) {
//         //B在列，A在行 
//         // dp[i][j] 存放的是 以B[i] A[j] 为结尾的 最长子序列的长度 
//        vector<vector<int> > dp(m,vector<int>(n,0));//先初始化为 0 
//        int max_len=0;
//         //一行一行地 
//         for(int i = 0 ; i < m ; i++ ){
//             for( int j =0 ; j < n ;j++){
//                 if (A[j]==B[i]){
//                     if (i==0||j==0){//第一行和第一列
//                         dp[i][j]=1;
//                         max_len = max(dp[i][j],max_len);
//                     }
//                     else{
//                         dp[i][j] = dp[i-1][j-1]+1;
//                         max_len = max(dp[i][j],max_len);
//                     }   
//                 } 
//             }
//         }
//         return max_len; 
//     }
// };
