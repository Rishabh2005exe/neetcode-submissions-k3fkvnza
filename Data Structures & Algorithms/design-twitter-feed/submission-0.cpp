class Twitter {
    int time = 0;

    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap; 
    // {time, tweetId}

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        
        followMap[userId].insert(userId);

        for(int user : followMap[userId]) {
            auto &tweets = tweetMap[user];

            if(!tweets.empty()) {
                int idx = tweets.size()-1;

                pq.push({
                    tweets[idx].first,     // time
                    tweets[idx].second,    // tweetId
                    user,
                    idx
                });
            }
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10) {
            auto top = pq.top();
            pq.pop();

            ans.push_back(top[1]);

            int user = top[2];
            int idx = top[3] - 1;

            if(idx >= 0) {
                pq.push({
                    tweetMap[user][idx].first,
                    tweetMap[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followMap[followerId].erase(followeeId);
    }
};