class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;int curSum=0;
        unordered_map<int,int> prefixSums;
        prefixSums[0]=1;
        for(int num:nums)
        {
            curSum+=num;
            if(prefixSums.find(curSum-k)!=prefixSums.end())
            {
                res+=prefixSums[curSum-k];
            }
            prefixSums[curSum]++;
        }
        return res;
    }
};