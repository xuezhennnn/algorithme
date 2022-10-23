/*
dp[i] 是i这个数的最大拆分乘积
那么就有两种拆分结果：如果从1开始遍历j的话
1) j*(i-j) 单纯把整数拆成两个数
2) j*dp[i-j] 至少两个
所以要取这两种方法的最大值，就相当于是最大乘积，但是还是要和本来的数作比较

一共有两个变量 i和j，j是对于每一个数的遍历数据，所以从1开始
i是我们可以取到的正整数
dp[0] dp[1]没有讨论的意义，我们不初始化这两个数字，dp[2]=1
但是就算不初始化，dp的size还是要加上他们两个！！！！！

j执行到i-1，不然再过去一个就是在重复之前的内容了
*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j <= i-1; j++){
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};
