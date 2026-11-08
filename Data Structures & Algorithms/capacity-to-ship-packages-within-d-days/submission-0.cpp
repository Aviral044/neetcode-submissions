class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int h=accumulate(weights.begin(),weights.end(),0);
        int res=h;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(check(weights,mid,days)==true)
            {
                res=min(res,mid);
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
    bool check(auto& weights, int cap,int days)
    {
        int ships = 1, currCap = cap;
        for (int w : weights) {
            if (currCap - w < 0) {
                ships++;
                if (ships > days) {
                    return false;
                }
                currCap = cap;
            }
            currCap -= w;
        }
        return true;   
    }
};