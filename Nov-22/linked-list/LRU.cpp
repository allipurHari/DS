https://leetcode.com/problems/lru-cache/submissions/

class LRUCache {
public:
    unordered_map<int,pair<int, list<int>::iterator >>mp;
    list<int>l;
    int cap;
    int curr = 0;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        l.splice(l.begin(), l, mp[key].second);
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            l.splice(l.begin(), l, mp[key].second);
            mp[key].first = value;
        }
        else{
            if(curr == cap){
                mp.erase(l.back());
                l.pop_back();
                curr--;
            }
            mp[key].first = value;
            l.push_front(key);
            mp[key].second = l.begin();
            curr++;
        }
    }
};
