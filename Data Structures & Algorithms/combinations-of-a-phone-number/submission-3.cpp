class Solution {
public:
vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        {
            return res;
        }
        dfs(digits,0,"");
        return res;
    }
    void dfs(auto& digits,int n,string x)
    {
        if(x.size()==digits.size())
        {
            res.push_back(x);
            return;
        }
        for(char i:digitToChar[digits[n]-'0'])
        {
            x+=i;
            dfs(digits,n+1,x);
            x.pop_back();
        }
    }

};
