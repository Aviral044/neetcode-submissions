class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum=0;
        int maxsum=nums[0];

        for(int n:nums)
        {
            cursum+=n;
            maxsum=max(cursum,maxsum);
            if(cursum<0)
            {
                cursum=0;
            }
        }
        return maxsum;
    }
};
