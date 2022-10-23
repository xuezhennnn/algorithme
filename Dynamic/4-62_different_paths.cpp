/*
    1.创建一个二维表格的dp
    2.把所有dp[i,0] dp[0,j] 都初始化为1
    3.dp[i,j-1]+dp[i-1,j] = dp[i,j]
    
    debug 日记：
    把每一个空位赋值的时候使用的是其他两个变量p q，但是程序并不能运行
    所以变量要始终如一

    二维vector的创建和初始化 vector<vector<int>> dp(m,vector<int>(n,0));
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0; i<m; i++) dp[i][0] =1;
        for(int j=0; j<n; j++) dp[0][j] =1;
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }

        return dp[m-1][n-1];
    }
};
