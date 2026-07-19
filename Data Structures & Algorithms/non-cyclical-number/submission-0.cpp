class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>seen;
        while(n != 1)
        {
            if(seen.find(n) !=seen.end())
                return false;
            seen.insert(n);

            int temp =n;
            n=0;
            while(temp)
            {
                n += (temp%10) *(temp%10);
                temp = temp/10;
            }
        }
        return true;
    }
};
