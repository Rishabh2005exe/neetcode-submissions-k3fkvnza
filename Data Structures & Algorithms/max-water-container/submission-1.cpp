class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area=0;
        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights.size();j++)
            {
                if(i<j)
                {
                    int current = (j-i)*min(heights[i],heights[j]);
                    area = max(area,current);
                }
            }
        }
        return area;
    }

};
