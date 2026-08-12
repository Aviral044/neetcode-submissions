class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums,0,subset,res);
        return res;
    }

    void dfs(auto& nums,int i,auto& subset,auto& res)
    {
        if(i>=nums.size())
        {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums,i+1,subset,res);
        subset.pop_back();
        dfs(nums,i+1,subset,res);
    }
};
