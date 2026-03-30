class Solution {
public:
    bool isValid(string s) {
        stack<char>open;
        if(s.length() ==1)
            return false;
        
        for(char c:s)
        {
            if(c == '[' || c == '(' || c == '{')
                open.push(c);
            else
            {
                if(open.empty())
                    return false;
                if(c == ')' && open.top() == '(')
                    open.pop();
                else if ( c == ']' && open.top() == '[')
                    open.pop();
                else if (c =='}' && open.top() == '{')
                    open.pop();
                else 
                    return false;
            }
        }
        return open.empty();
    }
};
