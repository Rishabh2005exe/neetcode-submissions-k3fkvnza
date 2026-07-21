class CountSquares {
    map<pair<int,int>,int> freq;
    vector<pair<int,int>> points;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0] , y = point[1];
        freq[{x,y}]++;
        points.push_back({x,y});
    }
    
    int count(vector<int> point) {
        int x = point[0] , y = point[1];
        int ans =0;

        for(auto &[x2,y2] : points)
        {
            if(abs(x-x2) != abs(y-y2) || x ==x2 || y == y2)
                continue;
            ans += freq[{x,y2}]* freq[{x2,y}];
        }
        return ans;
    }
};
