#include<bits/stdc++.h>
using namespace std;


class Solution {
    long long totalcost = 0;
    vector<int> totalingroup;
    vector<vector<int>> graph;

    void dfs(int node, int parent, vector<int>& group, vector<vector<int>>& count) {
        
        count[node][group[node]]++;

        for (auto v : graph[node]) {
            if (v == parent) continue;

            dfs(v, node, group, count);

            for (int g = 1; g <= 20; g++) {
                if (totalingroup[g] < 2) continue;

                long insubtree = count[v][g];
                long outsidesubtree = totalingroup[g] - insubtree;

                totalcost += insubtree * outsidesubtree;
                count[node][g] += count[v][g];
            }
        }
    }

public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        graph.assign(n, {});


        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        totalingroup.assign(21, 0);
        for (int g : group) {
            totalingroup[g]++;
        }

        vector<vector<int>> count(n, vector<int>(21, 0));

        dfs(0, -1, group, count);

        return totalcost;
    }
};
