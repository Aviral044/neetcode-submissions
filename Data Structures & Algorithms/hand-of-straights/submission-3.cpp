class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize>0)
        {
            return false;
        }
        unordered_map<int,int> count;
        for(int card:hand)
        {
            count[card]+=1;
        }

        for(int num:hand)
        {
            if(count[num]==0)
            {
                continue;
            }
            int size_r=groupSize;
            int start=num;
            while(count[start]>0 && size_r>0)
            {
                count[start]--;
                start--;
                size_r--; 
            }
            while(size_r>0)
            {
                num++;
                if(count[num]>0)
                {
                    size_r--;
                    count[num]--;
                }
                else{
                    return false;
                }
            }
        }
        return true;

    }
};
