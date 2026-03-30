class Twitter {
public:
    vector<tuple<int,int,int>> q; // time, userId, tweetId
    unordered_map<int, unordered_set<int>> followed;
    int count = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        q.push_back({count, userId, tweetId});
        count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        for (int i = q.size() - 1; i >= 0 && res.size() < 10; i--) {
            auto [time, uid, tid] = q[i];

            if (uid == userId || followed[userId].count(uid)) {
                res.push_back(tid);
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followed[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followed[followerId].erase(followeeId);
    }
};