class Solution {
private:
    vector<vector<int>> result; 
    vector<int> path; 

    void backtracking(vector<int>& candidates, int target, int sum, int startIndex){
        if(sum > target) return;
        if(sum == target){
            result.push_back(path); 
            return;
        }

        for(int i =startIndex; i< candidates.size(); i++){ 
            sum += candidates[i];
            path.push_back(candidates[i]);
            
            backtracking(candidates,target,sum,i); 
            sum -= candidates[i]; //回溯
            path.pop_back();
        }
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        backtracking(candidates,target,0,0);
        return result;
    }
};
