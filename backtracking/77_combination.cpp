class Solution {
private:
    vector<vector<int>> result; //存放最后的结果，每个里面有两个元素，所以是二维的，错！
                                //因为每组数据都是2个以上，是数组，所以数组的集合是二维的
    
    vector<int> path;           //存储的是每次找到的那组数据

    //n:从1到n k:每一个结果里面有几个元素 startIndex：下一层搜索开始的位置
    void backtracking(int n, int k, int startIndex){
        if(path.size()==k){
            result.push_back(path); //当满足条件之后把path里的数值放进result里面
            return;
        }
        for(int i =startIndex; i<=n; i++){ //i是从1开始的，所以最后是<=n，横向遍历所有元素	
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
