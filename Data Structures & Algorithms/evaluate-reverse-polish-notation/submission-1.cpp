class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>nums;
        int result =0;
        for(int i=0;i<tokens.size();i++)
        {
            if(!(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*"))
            {
                nums.push(stoi(tokens[i]));
            }
            else
            {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                if(tokens[i]=="+" )
                    result = a+b;
                if(tokens[i]=="-")
                    result = a-b;
                if(tokens[i]=="/")
                    result = a/b;
                if(tokens[i] == "*")
                    result = a*b;
                nums.push(result);
            }

        }
        return nums.top();
    }
};
