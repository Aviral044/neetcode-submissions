class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(char task:tasks)
        {
            count[task-'A']++;
        }
        priority_queue<int> maxHeap;//tasks with freq;
        for(int cnt:count){
            if(cnt>0)
            {
                maxHeap.push(cnt);
            }
        }
        int time=0;
        queue<pair<int,int>> q;//remaining freq,next available time
        while(!maxHeap.empty() || !q.empty())
        {
            time++;
            if(!maxHeap.empty()){
        
                int cnt=maxHeap.top()-1;
                maxHeap.pop();
                if(cnt>0)
                {
                    q.push({cnt,time+n});
                }
            }
            if(!q.empty() && q.front().second==time)
            {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
        
    }
};
