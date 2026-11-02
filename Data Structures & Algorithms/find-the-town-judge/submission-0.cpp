class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,unordered_set<int>> trustedby;
        vector<bool> trust_someone(n+1,false);
        for(auto& i:trust)
        {
            trustedby[i[1]].insert(i[0]);//i[0] trusts i[1]
            trust_someone[i[0]]=true;
        }
        for(int i=1;i<=n;i++)
        {
            if(trustedby[i].size()==(n-1) && trust_someone[i]==false)
            {
                return i;
            }
        }
        return -1;
    }
};