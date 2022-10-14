/*
    1.从1,2阶上第三个台阶开始推导：
    在第一阶的时候，再一下上两阶就可以
    在第二阶的时候，再一下上一阶就可以
    --->为什么不考虑从第一阶上两个一阶的情况，因为这种情况已经包含在第二个里面了
    所以dp[i]=dp[i-1]+dp[i+1]

    2.初始化dp[i]:
    不需要讨论dp[0]的值，因为n为正整数，只需要定义dp[1]=1, dp[2]=2就好

*/
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return n;
        vector<int> dp(3);//注意这里是三个，因为dp是从dp[0]开始的
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++){
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};
