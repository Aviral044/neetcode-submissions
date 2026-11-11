class Solution {
        vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        int open=0,close=0;string stack="";
        backtrack(n,open,close,stack);
        return res;
    }
    void backtrack(int n,int open,int close,auto& stack)
    {
        if(open==close and open==n)
        {
            res.push_back(stack);
            return;
        }
        if(open<n)
        {
            stack+='(';
            backtrack(n,open+1,close,stack);
            stack.pop_back();
        }
        if(close<open)
        {
            stack+=')';
            backtrack(n,open,close+1,stack);
            stack.pop_back();
        }
    }
};
