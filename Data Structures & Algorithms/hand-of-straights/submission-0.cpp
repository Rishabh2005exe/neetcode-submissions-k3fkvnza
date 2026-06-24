class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
            return false;
        sort(hand.begin() , hand.end());
        unordered_map<int,int>freq;
        for(int num:hand)
        {
            freq[num]++;
        }
        for(int num:hand)
        {
            if(freq[num] == 0)
                continue;
            for(int i=0;i<groupSize ;i++)
            {
                if(freq[num + i] !=0)
                {
                    freq[num +i]--;
                }
                else
                    return false;
            }
            
        }
        return true;
    }
};
