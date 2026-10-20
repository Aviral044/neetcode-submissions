class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int l=0;int maxFreq=0;int best=0;
        for(int r=0;r<s.size();r++)
        {
            count[s[r]-'A']++;
            maxFreq=max(count[s[r]-'A'],maxFreq);

            if((r-l+1)-maxFreq>k)
            {
                count[s[l]-'A']--;
                l++;
            }

            best=max(best,r-l+1);
        }
        return best;
    }
};
