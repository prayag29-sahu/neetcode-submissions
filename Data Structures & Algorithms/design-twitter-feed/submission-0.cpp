class Twitter {
public:

    int time;

    unordered_map<int, vector<pair<int, int>>> tweets;

    unordered_map<int, unordered_set<int>> following;

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        // {timestamp, {userId, index}}
        priority_queue<
            pair<int, pair<int, int>>
        > maxHeap;

        // User should always see their own tweets
        unordered_set<int> users = following[userId];

        users.insert(userId);

        // Add latest tweet of every relevant user
        for (int id : users) {

            if (!tweets[id].empty()) {

                int index = tweets[id].size() - 1;

                int timestamp = tweets[id][index].first;

                maxHeap.push({
                    timestamp,
                    {id, index}
                });
            }
        }

        vector<int> feed;

        while (!maxHeap.empty() && feed.size() < 10) {

            auto top = maxHeap.top();
            maxHeap.pop();

            int userId = top.second.first;
            int index = top.second.second;

            int tweetId = tweets[userId][index].second;

            feed.push_back(tweetId);

            // Add previous tweet from same user
            if (index > 0) {

                int previousIndex = index - 1;

                int timestamp =
                    tweets[userId][previousIndex].first;

                maxHeap.push({
                    timestamp,
                    {userId, previousIndex}
                });
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {

        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
    }
};