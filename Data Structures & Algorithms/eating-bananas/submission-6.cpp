class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin() , piles.end());
        int wantedK = maxPile;
        for(int k= 1;k<=maxPile;k++)
        {
            long long count =0;
            for(int j=0;j< piles.size(); j++)
            {
                if(piles[j] <= k)
                    count++;
                else
                {
                    if(piles[j] % k == 0)
                        count += piles[j]/k;
                    else
                        count += piles[j]/k +1;
                }
            }
            if(count <= h)
            {
                wantedK = k;
                break;
            }
        }
        return wantedK;
    }
};
