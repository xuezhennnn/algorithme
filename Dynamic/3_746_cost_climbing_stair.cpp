/*
    1.这道题嘴容易陷入的误区是对于dp数组的定义，dp[i]是到达第i阶台阶需要花费的cost，但是它只是一个计算花费的
    不一定dp[2]就是要到第二个，只是计算相应的花费
    2.为什么是i<cost.size()
    因为是从0开始的
    3.最后登顶有两种选择，可以从dp[size-1]走一个，或者从dp[size-2]走两个
    所以在遍历完整个表格的值之后，最后要加一步从这两个选择一个，但是最后的这一层的cost是0
*/

/*
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<cost.size(); i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return min(dp[cost.size()-1], dp[cost.size()-2]);
    }
};

*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp0 = cost[0];
        int dp1 = cost[1];
        for(int i=2; i<cost.size(); i++){
            int dpi = min(dp0, dp1) + cost[i];
            dp0 = dp1;
            dp1 = dpi;
        }
        return min(dp0, dp1);
    }
};
