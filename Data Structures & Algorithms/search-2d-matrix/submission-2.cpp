class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS=matrix.size();
        int COLS=matrix[0].size();

        int l=0;int h=ROWS-1;
        int mid=0;int flag=0;

        while(l<=h)
        {
            mid=(l+h)/2;
            if(target>matrix[mid][COLS-1])
            {
                l=mid+1;
            }
            else if(target<matrix[mid][0])
            {
                h=mid-1;
            }
            else{
                flag=1;
                break;
            }
        }    
        if(flag==0){
            return false;
        }
        l=0;h=COLS-1;int r=mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(target<matrix[r][mid])
            {
                h=mid-1;
            }
            else if(target>matrix[r][mid])
            {
                l=mid+1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
