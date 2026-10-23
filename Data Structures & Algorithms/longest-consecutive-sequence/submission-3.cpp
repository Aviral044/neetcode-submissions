class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq(nums.begin(),nums.end());
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(seq.find(nums[i]-1)==seq.end())
            {
                int start=nums[i];
                int length=1;
                while(seq.find(nums[i]+length)!=seq.end())
                {
                    length+=1;
                }
                res=max(res,length);
            }
        }
        return res;
    }
};
