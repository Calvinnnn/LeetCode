#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Twitter {
public:
    int time=-1;
    unordered_map<int,vector<int>>user_and_posts;
    unordered_map<int,vector<int>> following;
    unordered_map<int,int> post_time;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        user_and_posts[userId].push_back(tweetId);
        post_time[tweetId] = time++;
    }

    vector<int> getUserPosts(int userId){
        return user_and_posts[userId];
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> answer;
        vector<int> feeds;
        vector<int> & user_posts = user_and_posts[userId];
        feeds.insert(feeds.end(),user_posts.begin(),user_posts.end());
        vector<int> & user_following = following[userId];
        for(int & x : user_following){
            vector<int> follwing_posts =  getUserPosts(x);
            feeds.insert(feeds.end(),follwing_posts.begin(),follwing_posts.end());
        }
        auto cmp = [this](int a,int b){
            return post_time[a] < post_time[b];
        };
        priority_queue<int,vector<int>,decltype(cmp)>q1(cmp);
        for(int i=0; i<feeds.size();i++){
            q1.push(feeds[i]);
        }
        for(int i=0; i<10;i++){
            if(q1.empty()) break;
            answer.push_back(q1.top());
            q1.pop();
        }
        return answer;
    }
    void follow(int followerId, int followeeId) {
        vector<int> &followers = following[followerId];
        if(find(followers.begin(),followers.end(),followeeId)==followers.end()){
            following[followerId].push_back(followeeId);
        }
        
    }
    void unfollow(int followerId, int followeeId) {
        following.erase(followerId);
    }
};
