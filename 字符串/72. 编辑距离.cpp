class Solution {
public:

int min3(int a,int b, int c){
    return a<b?((a<c)?a:c):((b<c)?b:c);
}

    int minDistance(string word1, string word2) {
    int m = word2.size() ;
    int n = word1.size();
    vector<vector<int> >dp(m+1, vector<int>(n+1,0));
      for(int i = 0;i<=n;i++){
          dp[0][i]=i;
      }
      for(int i = 0;i<=m;i++){
          dp[i][0]=i;
      }
        
        for(int i = 0; i< n ;i++){
          for(int j = 0;j< m;j++){
              if(word1[i]==word2[j]){
                   dp[j+1][i+1]=min3(dp[j][i+1] +1,dp[j+1][i] +1 , dp[j][i]);
              }
              else{
                  dp[j+1][i+1]=min3(dp[j][i+1] +1,dp[j+1][i] +1 , dp[j][i]+1);
              }  
          }
      }
      return dp[m][n];
    }
};
