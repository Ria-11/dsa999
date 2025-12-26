

#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> count(10 ,0);
        int sum =0;
        for(int d :digits){
            count[d]++;
            sum+=d;

        }

        auto removeDigits = [&](int rem , int times)->bool{
            for(int i=1 ;i <= 9 && times > 0 ;i++){
                if( i % 3 == rem ){
                    while(count[i] > 0 && times >0){
                        count[i]--;
                        times--;
                    }
                }
            }
            return times == 0;
        };



        if( sum % 3 == 1){
            if(!removeDigits(1,1))removeDigits(2,2);
            // if not possible remove digit of 1 remainder, 
            //remove 2 digit of rem 2 to get same configuration

        }
        else if( sum % 3 == 2){
            if(!removeDigits(2,1))removeDigits(1,2);
        }

    string ans; for (int d = 9; d >= 0; d--) {
         ans.append(count[d], char('0' + d)); 
         }
    if (ans.empty()) return "";
    if (ans[0] == '0') return "0"; 

    return ans ;
        
    }
};