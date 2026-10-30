class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;int r=nums.size()-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        int pivot=l;//array min is here
        //check which part does target lie
        if(target>=nums[pivot] && target<=nums[nums.size()-1])
        {
            l=pivot;r=nums.size()-1;
        }
        else{
            l=0;r=pivot-1;
        }
        int index=binary_search(nums,l,r,target);
        return index;
    }
    int binary_search(auto& nums,int l,int r,int target)
    {
        int index=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(target<nums[mid])
            {
                r=mid-1;
            }
            else if(target==nums[mid]){
                index=mid;
                break;
            }
            else{
                l=mid+1;
            }
        }
        return index;
    }
};
