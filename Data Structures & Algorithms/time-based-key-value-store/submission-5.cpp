class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> keyStore;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto& values=keyStore[key];
        int left=0;int right=values.size()-1;
        string result;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(values[mid].first<=timestamp)
            {
                result=values[mid].second;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return result;
    }

};
