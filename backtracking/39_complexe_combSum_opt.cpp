/*
for 循环是选择完新的数据之后，对它及它之后的数据进行遍历
除了拥有 i<candidates.size() 这个条件之外
还可以再加一个，当上一回合的sum加上这个遍历的数据已经> target，那么程序就可以停止继续遍历了
&& sum+candidates[i]<= target

debug好久最后发现是没有排序的问题，比如这一层我们选择了5，如果不排序的话可以依次选择 7,5,3
如果需要的和是7的话，后面的5和3因为7在他们前面所以可以直接略过，程序就不争取了
所以应该先从大到小排序sort(candidates.begin(), candidates.end()); // 需要排序
*/


class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int>& candidates, int target, int sum, int startIndex){
        //if(sum > target) return;
        if(sum == target){
            result.push_back(path);
            return;
        }

        for(int i= startIndex; i < candidates.size() && sum + candidates[i]<= target ; i++){
     
            path.push_back(candidates[i]);
            sum += candidates[i];
            //backtracking(candidates,target,sum,startIndex);//这里不是startindex，它在程序里是一个被赋值的量，所以要写循环里用到的变量
            backtracking(candidates,target,sum,i);//不需要+1，可以读当前的数据
            sum -= candidates[i];
            path.pop_back();

        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        sort(candidates.begin(), candidates.end()); // 需要排序
        backtracking(candidates,target,0,0);
        return result;
    }
};
