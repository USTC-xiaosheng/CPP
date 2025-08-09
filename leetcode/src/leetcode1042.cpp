//
// Created by xiaosheng on 25-8-3.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int i=0;
        int i1 =0;
        int i2 =0;
        int max1 = 0;
        int num{0};
        vector<int> map(1e6,0);
        while (i < fruits.size()) {
            if (fruits[i][0] >= startPos) {
                if (startPos==fruits[i][0]) {
                    i1=i+1;
                    i2=i-1;
                    num = fruits[i][1];
                }else {
                    i1=i;
                    i2=i-1;
                }
                break;
            }
            i++;
        }
        int temp = 0;
        for (int j = startPos+1; j <= k+startPos; j++) {
            if (i1<fruits.size() and fruits[i1][0]==j) {
                temp = fruits[i1][1];
                i1++;
            }else {
                temp=0;
            }
            map[j] = temp+map[j-1];
        }
        for (int j = startPos-1; j >= startPos-k and j>=0; j--) {
            if (i2>=0 and fruits[i2][0]==j) {
                temp = fruits[i2][1];
                i2--;
            }else {
                temp=0;
            }
            map[j] = temp+map[j+1];
        }
        int left=0;
        if (startPos>ceil(k/2)) {
            left=startPos-static_cast<int>(ceil(k / 2));
        }else {
            left=0;
        }
        for (; left<startPos; left++) {
            if (k-2*(startPos-left)+startPos==startPos) {
                continue;
            }
            max1 = max(max1, map[left]+map[k-2*(startPos-left)+startPos]);
        }
        int right=startPos+static_cast<int>(ceil(k/2));
        for (int j=0; right>startPos; right--) {
            if (startPos-j*2==startPos) {
                continue;
            }
            if (startPos-j*2<0) {
                max1 = max(max1, map[right]+map[0]);
                break;
            }
            max1 = max(max1, map[right]+map[startPos-j*2]);
            j++;
        }
        if (startPos>k) {
            max1=max(max1,map[startPos-k]);
        }else {
            max1=max(max1,map[0]);
        }
        return max(max1, map[startPos+k])+num;
    }
};
int main() {
    Solution s;
    vector<vector<int>>b = {{0,9},{4,1},{5,7},{6,2},{7,4},{10,9}};
    cout<<s.maxTotalFruits(b,5,4);
}