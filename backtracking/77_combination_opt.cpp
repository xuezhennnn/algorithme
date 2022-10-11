class Solution {
private:
    vector<vector<int>> result; //存放最后的结果，每个里面有两个元素，所以是二维的
    vector<int> path; //一维数组 path //存储每一个找到的两个数字的数据

    //n:从1到n k:每一个结果里面有几个元素 startIndex：下一层搜索开始的位置
    void backtracking(int n, int k, int startIndex){
        if(path.size()==k){
            result.push_back(path); //当满足条件之后把path里的数值放进result里面
            return;
        }
        for(int i =startIndex; i<= n -(k- path.size()) + 1; i++){ //比如四个选两个，遍历到最后的4其实是无效的，所以是4-2+1 = 3的时候停止
            path.push_back(i);
            backtracking(n,k,i+1); //从节点回溯，如果符合两个的标准就加入path
            path.pop_back(); //释放位置
        }

}
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear(); // 可以不写
        path.clear();   // 可以不写
        backtracking(n, k, 1);
        return result;
    }

};
