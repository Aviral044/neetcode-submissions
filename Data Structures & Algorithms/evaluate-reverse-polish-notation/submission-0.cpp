class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for(auto& a:tokens)
        {
            if(a=="+")
            {
                int a=stack.top();stack.pop();
                int b=stack.top();stack.pop();
                stack.push(a+b);
            }
            else if(a=="-")
            {
                int a=stack.top();stack.pop();
                int b=stack.top();stack.pop();
                stack.push(b-a); 
            }
            else if(a=="/")
            {
                int a=stack.top();stack.pop();
                int b=stack.top();stack.pop();
                stack.push(b/a);
            }
            else if(a=="*")
            {
                int a=stack.top();stack.pop();
                int b=stack.top();stack.pop();
                stack.push(b*a);
            }
            else{
                stack.push(stoi(a));
            }
        }
        return stack.top();
    }
};
