/*
    1.substr(startIndex, 需要数据的长度)
    2.i是为了从前向后遍历，startindex是每一次刚进去时候的index，所以每次截取前面的部分[startIndex, i]
      string jie = s.substr(startindex, i-startIndex+1)
    3.为什么i到s.size()之前就可以：
      因为最多分到最后一位之前，再在最后一位的后面来一刀在for循环里面是没有意义的
      一开始把所有的回溯算法放在判断回文串里面，但是如果不是回文串也可以接着向下回溯
      if(huiwenchuan(s, startIndex, i)){
            string jie = s.substr(startIndex, i-startIndex + 1);
            path.push_back(jie);
            backtracking(s, startIndex+1);
            path.pop_back();
        }
*/

class Solution {

private:

    vector<string> path;
    vector<vector<string>> result;

    void backtracking(const string& s, int startIndex){
        if(startIndex >= s.size()){
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < s.size(); i++){ 
    
            if(huiwenchuan(s, startIndex, i)){
                string jie = s.substr(startIndex, i-startIndex + 1);
                path.push_back(jie);
            }else{
                continue;
            }

            //backtracking(s, startIndex+1); 又写成startIndex了，为什么！！！！！！！！！
            backtracking(s,i+1);
            path.pop_back();
        }

        
    }
    

    //判断回文串的双指针方法
    bool huiwenchuan(const string& s, int begin, int end){
        for( int i = begin, j = end; i < j ; i++, j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }


public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s,0);
        return result;
    }
};
