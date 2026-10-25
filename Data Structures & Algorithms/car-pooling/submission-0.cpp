class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //calculate Range
        int L = INT_MAX, R = INT_MIN;
        for (const auto& trip : trips) {
            L = min(L, trip[1]);
            R = max(R, trip[2]);
        }
        int N=R-L+1;//
        vector<int> diff(N+1,0);
        for(auto& trip:trips)
        {
            int from=trip[1]-L;
            int to=trip[2]-L;
            int np=trip[0];

            diff[from]+=np;
            diff[to]-=np;
        }
        int currPass=0;
        for(int change:diff)
        {
            currPass+=change;
            if(currPass>capacity)
            {
                return false;
            }
        }
        return true;
    }
};