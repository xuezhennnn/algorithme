/*
1.多了一个有障碍物表示的二维表格，有障碍物是1，无障碍物是0，obstacleGrid.length=m, obstacleGrid[i].length=n
2.表格初始化
    原先侧边都直接初始化为1，但是如果侧边存在障碍物，那么障碍物之后的路径为0---< 当探测到obstacleGrid[i][0]为1之后，停止赋值动作

*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i = 0; i<m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for(int j = 0; j<n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        for(int i =1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }else{
                    dp[i][j] = 0;
                }
                /*
                if(obstacleGrid[i][j] == 1) continue;
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                continue是跳过当前循环，然后在不是这种情况的时候，执行下一句话
                */
            }
        }
        return dp[m-1][n-1];
    }
};
