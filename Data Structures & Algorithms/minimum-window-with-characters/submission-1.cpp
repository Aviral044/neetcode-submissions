class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> countT,window;int n=s.size();
        for(char x:t)
        {
            countT[x]++;
        }
        int have=0;int need=countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;
        for(int r=0;r<s.size();r++)
        { 
            char c=s[r];
            window[c]++;
            if(countT.count(c) && window[c]==countT[c])//character exists in the window and frequency is correct
            {
                have++;
            }
            while(have==need)//shrink the window
            {
                if((r-l+1)<resLen)
                {
                    resLen=r-l+1;
                    res={l,r};
                }
                window[s[l]]--;//remove the left from window
                if(countT.count(s[l]) && window[s[l]]<countT[s[l]])//
                {
                    have--;
                }
                l++;
            }
        }
        return resLen==INT_MAX?"":s.substr(res.first,resLen);
    }

};
