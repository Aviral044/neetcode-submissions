class Solution {
    vector<vector<string>> res;
public:
    bool isPalindrome(string s)
    {
        int l=0;int r=s.size()-1;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l++;r--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string> subset;
        dfs(s,0,subset);
        return res;
    }
    void dfs(auto& s,int i,auto subset)
    {
        if(i==s.size())
        {
            res.push_back(subset);
            return;
        }
        string x="";
        for(int j=i;j<s.size();j++)
        {
            x+=s[j];
            if(isPalindrome(x))
            {
                subset.push_back(x);
                dfs(s,j+1,subset);
                subset.pop_back();
            }

        }
        
    }
};
