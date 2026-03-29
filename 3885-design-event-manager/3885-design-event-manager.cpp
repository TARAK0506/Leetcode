class EventManager {
private:
    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        }
    };
    set<pair<int, int>, cmp> s;
    unordered_map<int, int> mp;

public:
    EventManager(vector<vector<int>>& events) {
        for(int i = 0; i < events.size(); i++){
            int eventId = events[i][0];
            int priority = events[i][1];
            s.insert({eventId, priority});
            mp[eventId] = priority;
        }
    }

    void updatePriority(int eventId, int newPriority) {
        s.erase({eventId, mp[eventId]});
        mp[eventId] = newPriority;
        s.insert({eventId, newPriority});
    }

    int pollHighest() {
        if (s.empty())
            return -1;
        auto itr = s.begin();
        int eventId = itr->first;
        s.erase(itr);
        mp.erase(eventId);
        return eventId;
    }
};