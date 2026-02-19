#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // bas case handle
        unordered_set<string> dict(wordList.begin() , wordList.end());

        if(!dict.count(endWord)){
            return 0;
        }
      // now every word is node , there iis a edge if there is node with only one difference predsent

      queue<pair<string ,int>> q;
      q.push({beginWord ,1});
      while(!q.empty()){
        auto[word , level] = q.front();
        q.pop();
        for(int i=0;i<word.size() ;i++){
            string temp = word ;
            for(char c= 'a' ; c<= 'z' ;c++){
                temp[i] =c;
                if(dict.count(temp)){
                    if(temp == endWord){
                        return level +1;
                    }
                    q.push({temp , level +1});
                    dict.erase(temp);
                }
            }
        }
      }
      return 0;
    }
};