class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;int n=0;
        dfs(nums,n,subset);
        return res;
    }
    void dfs(auto& nums,int n,auto& subset)
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
