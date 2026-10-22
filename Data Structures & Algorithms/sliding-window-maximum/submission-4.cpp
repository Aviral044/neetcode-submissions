class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;int l=0;int r=0;vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            while(!q.empty() && nums[q.back()]<nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            if((i-k+1)>q.front())
            {
                q.pop_front();
            }
            if((i+1)>=k)
            {
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};
