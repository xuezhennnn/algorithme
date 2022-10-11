/*
1.为什么以前的输出结果是二维数组，但是这个数组可以是一维的string
    因为不同的char连接在一起就可以创造出新的数据类型 string
    a,b,c -----> abc
2.index的作用
    表示输入的string中有几个数，有几个就遍历到多少次
    当index的值和输入string的数据大小相等时，把结果存储在result中然后return
*/

class Solution {
private:
    const string letterMap[10] ={
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };

    vector<string> result;
    string s; //收集节点的数据

    void backtracking(const string &digits, int index){
        if(index == digits.size()){
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';        // 将index指向的数字转为int
        string letters = letterMap[digit];      // 取数字对应的字符集
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);            // 处理
            backtracking(digits, index + 1);    // 递归，注意index+1，一下层要处理下一个数字了
            s.pop_back();                       // 回溯
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if (digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};
