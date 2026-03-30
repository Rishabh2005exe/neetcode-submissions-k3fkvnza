class TimeMap {
public: 
    unordered_map<string,unordered_map<int,string>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        while(timestamp>=1)
        {
            if(mp[key].count(timestamp))
                return mp[key][timestamp];
            timestamp--;
        }
        return "";
    }
};
