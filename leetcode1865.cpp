//
// Created by xiaosheng on 25-7-12.
//
#include<bits/stdc++.h>
using namespace std;

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (auto num:nums2) {
            map2[num] += 1;
        }
        nums_2=nums2;
        nums_1=nums1;
        ranges::sort(nums_1);
    }

    void add(int index, int val) {
        map2[nums_2[index]] -= 1;
        nums_2[index] += val;
        map2[nums_2[index]] += 1;
    }

    int count(int tot) {
        int output{};
        for (const auto num:nums_1) {
            if (tot<=num) break;
            if (map2.contains(tot-num))output+=map2[tot-num];
        }
        return output;
    }
private:
    map<int, int> map2;
    vector<int> nums_1;
    vector<int> nums_2;
};