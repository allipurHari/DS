https://leetcode.com/problems/hand-of-straights/description/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize)return false;
        map<int, int> mp;
        for(int i = 0;i < n;i++){
            mp[hand[i]]++;
        }
        auto itr = mp.begin();
        int count = 0, prev = itr->first-1;
        while(itr != mp.end()){
            itr->second = itr->second - 1;
            if(itr->first == prev+1){
                prev++;
            }
            else{
                return false;
            }
            if(!itr->second){
                mp.erase(itr);
            }
            count++;
            if(count == groupSize){
                count = 0;
                itr = mp.begin();
                prev = itr->first -1;
            }else{
                itr++;
            }
        }
        return !count ? true : false;
    }
};
