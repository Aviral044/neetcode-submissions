class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> subset;int n=0;int sum=0;
        dfs(candidates,target,n,sum,subset);
        return result;
    }
    void dfs(auto& candidates,int target,int n,int sum,auto& subset)
    {
        if(sum==target){
            result.push_back(subset);
            return;
        }
        else if(sum>target || n>=candidates.size())
        {
            return;
        }
        subset.push_back(candidates[n]);
        sum+=candidates[n];
        dfs(candidates,target,n+1,sum,subset);
        while(n+1<candidates.size() && candidates[n+1]==candidates[n])
        {
            n=n+1;
        }
        sum=sum-candidates[n];
        subset.pop_back();
        dfs(candidates,target,n+1,sum,subset);
    }
};
