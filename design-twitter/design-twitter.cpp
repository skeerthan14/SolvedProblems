class Twitter {
public:
    unordered_map<int, unordered_set<int>>tu;
    unordered_map<int, vector<pair<int, int>>>nf;
    long long time;
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        nf[userId].push_back({time++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>>maxHeap;
        for(auto i:nf[userId]){
            maxHeap.push(i);
        }
        for(auto i: tu[userId]) {
            for(auto j:nf[i]){
                maxHeap.push(j);
            }
        }
        vector<int> res;
        while(maxHeap.size()) {
            res.push_back(maxHeap.top().second);
            if(res.size()==10) break;
            maxHeap.pop();
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        tu[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        tu[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */