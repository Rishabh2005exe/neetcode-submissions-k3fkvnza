class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                for(int k=0;k<nums.size();k++)
                {
                    if(i!=j && i!=k && j!=k)
                    {
                        vector<int>pairs;
                        if(nums[i]+nums[j]+nums[k]==0)
                        {
                            pairs= {nums[i],nums[j],nums[k]};
                            sort(pairs.begin(),pairs.end());
                            if(!( find(res.begin(),res.end() ,pairs)!= res.end()))
                                res.push_back(pairs);
                        }
                        
                    }
                }
            }
            
        }
        return res;
    }
};
