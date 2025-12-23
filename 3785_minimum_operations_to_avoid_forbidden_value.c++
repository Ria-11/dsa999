#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        unordered_map<int,int> badbonds;
        vector<pair<int,int>> goodbond;
        int ans = 0;
        int n = nums.size();

        // Step 1: classify bonds
        for(int i=0;i<n;i++){
            if(nums[i] == forbidden[i]){
                badbonds[nums[i]]++;
            } else {
                goodbond.push_back({nums[i], forbidden[i]});
            }
        }

        if(goodbond.empty()){
            if(badbonds.size() == 1){
            return -1 ;
            }
            int maxFreq = 0;
             for (auto &p : badbonds) maxFreq = max(maxFreq, p.second); 
             if (maxFreq > n/2) return -1; 
        }

        // Step 2: push bad bonds into max-heap
        priority_queue<pair<int,int>> pq;
        for(auto &i : badbonds){
            pq.push({i.second, i.first});
        }

        // Step 3: resolve bad bonds pairwise
        while(pq.size() > 1){
            auto [freqx, x] = pq.top(); pq.pop();
            auto [freqy, y] = pq.top(); pq.pop();

            int k = min(freqx, freqy);
            ans += k;

            // simulate swaps
            while(k--){
                goodbond.push_back({x,y});
            }

            if(freqx > freqy) pq.push({freqx - freqy, x});
            else if(freqy > freqx) pq.push({freqy - freqx, y});
        }

        // Step 4: handle leftover bad bonds
        if(!pq.empty()){
            int count = pq.top().first;
            int x = pq.top().second;

            while(count > 0){
                bool found = false;
                for(int i=0;i<goodbond.size();i++){
                    if(goodbond[i].first != x && goodbond[i].second != x){
                        ans++;
                        count--;

                        auto current = goodbond[i];
                        goodbond.erase(goodbond.begin() + i); // ✅ FIXED
                        goodbond.push_back({x, current.first});
                        goodbond.push_back({x, current.second});

                        found = true;
                        break;
                    }
                }
                if(!found) return -1; // impossible case
            }
        }
        return ans;
    }
};
