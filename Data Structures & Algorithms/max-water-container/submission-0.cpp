class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;int r=heights.size()-1;int watmax=0;
        while(l<r)
        {
            int watercap=min(heights[l],heights[r])*(r-l);
            watmax=max(watmax,watercap);
            if(heights[l]<heights[r])
            {
                l++;
            }
            else{
                r--;
            }
        }
        return watmax;
    }
};
