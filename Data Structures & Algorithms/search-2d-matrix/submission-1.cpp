class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowfirst = 0;
        int rowlast = matrix.size()-1;
        int columnfirst=0;
        int columnlast = matrix[0].size()-1;
        while(rowfirst <=rowlast)
        {
            int mid = rowfirst + (rowlast-rowfirst)/2;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target)
            {
                if(matrix[mid][columnlast]>= target)
                {
                    int row = mid;
                    int cf = columnfirst;
                    int cl = columnlast;
                    while(cf<=cl)
                    {
                    int cmid = (cf+cl)/2;
                    if(matrix[row][cmid]== target)
                        return true;
                    else if(matrix[row][cmid] <  target)
                        cf=cmid+1;
                    else
                        cl = cmid-1;
                    }
                    return false;
                }
                rowfirst = mid +1;
            }
            else if(matrix[mid][0] > target)
            {
                rowlast = mid -1;
            }
        }
        return false;
    }
};
