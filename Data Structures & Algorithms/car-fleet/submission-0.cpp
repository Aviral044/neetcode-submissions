class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;//postion,speed
        for(int i=0;i<position.size();i++)
        {
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.rbegin(),cars.rend());
        vector<double> stack;
        for(auto p:cars)
        {
            stack.push_back((double)(target-p.first)/p.second);//checking time it needs to reach the end.
            if(stack.size()>=2 && stack.back()<=stack[stack.size()-2])
            {
                stack.pop_back();
            }
        }
        return stack.size();
    }
};
