class Solution {
private:
    vector<vector<int>> result; 
    vector<int> path; 

    void backtracking(int targetSum, int k, int sum, int startIndex){
        if(sum > targetSum) return;
        if(path.size()==k){
            if(sum == targetSum) result.push_back(path); // 求和是我们需要的，加入result
            return;//当结果中数据数量达到要求，我们就终止操作
        }

        for(int i =startIndex; i<= 9-(k-path.size())+1; i++){ 
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
