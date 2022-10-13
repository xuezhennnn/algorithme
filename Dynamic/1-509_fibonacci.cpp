/*
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;              //当n为0或者1的时候，他们的值和n是一样的，所以直接返回
        vector<int> dp(n+1);            //创建一个长度为N+1的斐波那契数列，因为是从0开始，所以要+1
        dp[0] = 0;
        dp[1] = 1;                      //初始情况
        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
*/

//创建一个只有两个值的情况
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;              
        vector<int> dp(2);            
        dp[0] = 0;
        dp[1] = 1;                      
        for(int i = 2; i<=n; i++){
            int sum = dp[1] + dp[0];
            dp[0] = dp[1];             //进行一个参数的传递，原先0里面的数据直接舍弃，然后下一位传进上一位的位置
            dp[1] = sum;
        }
        return dp[1];
    }
};
