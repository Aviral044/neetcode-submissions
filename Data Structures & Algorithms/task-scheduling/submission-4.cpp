class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> tf(26,0);//making the frequency map
        for(char t:tasks)
        {
            tf[t-'A']+=1;
        }
        queue<vector<int>> cooldown;//time available,id,remaining freq
        priority_queue<pair<int,int>> task_queue;//Maxheap

        for(int i=0;i<26;i++)
        {
            if(tf[i]>0)
            {
                task_queue.push({tf[i],i});//frequency,id
            }        
        }
        int cycles=0;
        while(!cooldown.empty() || !task_queue.empty())
        {
            cycles++;
            if(!task_queue.empty())
            {
                auto cur_task=task_queue.top();
                task_queue.pop();
                cur_task.first--;//decrease the frequency
                if(cur_task.first>0)
                {
                    cooldown.push({cycles+n,cur_task.second,cur_task.first});
                }
            }
            if(!cooldown.empty() && cooldown.front()[0]==cycles)
            {
                auto t=cooldown.front();
                cooldown.pop();
                task_queue.push({t[2],t[1]});
            }
        }
        return cycles;
    }
};
