/*
    这个题目最大的问题是选择之后不能有重复的数组：
    在每一个树枝里面是可以有相同的数字的
    但是在每一个树层是不可以的

    1.给数组排序，相同的数字会相邻
    2.引入一个记录用过的数字的bool数组 used
    3.在for循环里面，如果相邻的数字是相等的 candidates[i]= candidates[i-1], 且used[i-1]==0, 说明在之前备用过了，那么需要去重

*/

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int>& candidates, int target, int sum, int startIndex,vector<bool>& used){
        if(sum == target){
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i <candidates.size() && sum+candidates[i] <= target ; i++){
            //if( candidates[i] == candidates[i-1] && used[i-1] == false){:因为程序里index会-1，所以如果从0开始会出现负索引的可能性
            //系统就会报错，所以增加一个条件， i>0就可以了
          
            if( i>0 && candidates[i] == candidates[i-1] && used[i-1] == false){
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtracking( candidates, target, sum, i+1,used);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }


public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        path.clear();
        result.clear();
        // 首先把给candidates排序，让其相同的元素都挨在一起。
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};
