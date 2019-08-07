int getLongestPalindrome(string A, int n) {
      vector<vector<int> > dp(n,vector<int>(n,0));
      int maxlen = 0;
      // 字符串首尾字母长度差 (d = j-i)
      for (int d = 0; d < n; d++) {
          // 字符串起始位置 i
        for (int i = 0; i < n-d; i++) {
            // 字符串结束位置 j
            int j = i+d;
            // 如果字符串 i 到 j 的首尾相等，再根据字符串 i-1 到 j-1 来确定，即得到递推公式
            if( A[i] == A[j]){
                if(d == 0 || d == 1) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i+1][j-1];
                }
                if(dp[i][j]) {
                    // 更新最大长度
                    maxlen=   d+1 ;
                }
            }
        }
    }
      return maxlen;
}
