class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            int num_check=target-nums[i];
            if(mp.find(num_check)!=mp.end() && mp[num_check]!=i)
            {
                result.push_back(i);
                result.push_back(mp[num_check]);
                return result;
            }
        }
        return {};
    }
};
