class Solution {
public:
    int trap(vector<int>& height) {
        int trap=0;
        if(height.size()<=2)
        {
            return 0;
        }
        int n=height.size();
        int l=0;int r=n-1;
        int leftmax=height[l];int rightmax=height[r];
        while(l<r)
        {
            if(leftmax<rightmax)
            {
                l=l+1;leftmax=max(height[l],leftmax);
                trap+=leftmax-height[l];
            }
            else{
                r=r-1;rightmax=max(height[r],rightmax);
                trap+=rightmax-height[r];
            }
        }
        return trap;

    }
};
