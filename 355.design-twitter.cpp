/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
class Twitter
{
public:
    /** Initialize your data structure here. */
    Twitter()
    {
        time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        map1[userId].insert({time, tweetId});
        time++;

        // 把自己放入follow裡面, 這樣後面traverse才會traverse到自己
        if (!map2[userId].count(userId))
            map2[userId].insert(userId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        map<int, int> top10;
        // Traverse its follow 有包含自己
        for (auto v : map2[userId])
        {
            // Traverse其文章
            for (auto k : map1[v])
            {
                top10[k.first] = k.second;
                if (top10.size() > 10)
                    top10.erase(top10.begin());
            }
        }

        // 從後面traverse過來, 因為map從小排到大
        for (auto a = top10.rbegin(); a != top10.rend(); a++)
        {
            res.push_back(a->second);
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        map2[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if (followeeId != followerId)
            map2[followerId].erase(followeeId);
    }

private:
    int time;
    // User對應其文章, time and 文章ID
    unordered_map<int, map<int, int>> map1;
    // User對應其follow
    unordered_map<int, unordered_set<int>> map2;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
