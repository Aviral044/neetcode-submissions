class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=0;
        vector<int> subset;
        dfs(nums,n,subset);
        return res;
    }
    void dfs(auto& nums,int n,vector<int>subset)
    {
        if(n>=nums.size())
        {
            res.push_back(subset);
            return;
        }
        
        subset.push_back(nums[n]);
        dfs(nums,n+1,subset);
        subset.pop_back();
        dfs(nums,n+1,subset);
    }
};
