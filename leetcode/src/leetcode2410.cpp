//
// Created by xiaosheng on 25-7-13.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        ranges::sort(trainers,greater{});
        ranges::sort(players,greater{});
        int result = 0;
        for(auto i=0,j=0;i<trainers.size() and j<players.size();) {
            if(trainers[i]>=players[j]) {i++;j++;result++;}
            else {j++;}
        }
        return result;
    }
};