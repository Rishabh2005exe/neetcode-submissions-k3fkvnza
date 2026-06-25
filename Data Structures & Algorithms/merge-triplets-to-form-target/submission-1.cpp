class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool>found(target.size() , false);
        for(auto& triplet : triplets)
        {
            if(triplet[0]> target[0] || triplet[1] > target[1] || triplet[2] > target[2])
                continue;
            if(triplet[0] == target[0])
                found[0]=true;
            if(triplet[1] == target[1])
                found[1] = true;
            if(triplet[2] == target[2])
                found[2] = true;
            if(found[0] && found[1] && found[2])
                return true;
        }
        return false;
    }
};
