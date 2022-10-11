/*
回溯算法是一种不能直接思考的逻辑，你需要赋予程序一个过程，然后这个程序可以不停地被自己调用，之后你再设置这个程序停止的条件，以及你需要
的数据的个数，设置好之后它就会自动给出你需要的东西
*/

class Solution {
private:
    vector<vector<int>> result; 
    vector<int> path; 

    void backtracking(int targetSum, int k, int sum, int startIndex){
        if(path.size()==k){
            if(sum == targetSum) result.push_back(path); // 求和是我们需要的，加入result
            return;//当结果中数据数量达到要求，我们就终止操作
        }

        for(int i =startIndex; i<=9; i++){ //要遍历到9，所以此时是固定为9
            sum += i;
            path.push_back(i);
            
            backtracking(targetSum, k, sum, i+1); 
            sum -= i; //回溯
            path.pop_back();
        }
}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear(); // 可以不写
        path.clear();   // 可以不写
        backtracking(n, k, 0, 1);
        return result;
    }

};
