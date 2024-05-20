class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int> >segments;
        vector<pair<int, pair<int, int> > > events;

        for(auto& interval: intervals){

            events.push_back({interval[0], {0, interval[1]}});
            events.push_back({interval[1], {1, interval[0]}});
        }

        sort(events.begin(), events.end());
        multiset<pair<int, pair<int, int> > >opened;
        int last_opened;

        for(auto event: events){

            if(event.second.first == 0){
                
                if(opened.size() == 0)last_opened = event.first;
                opened.insert(event);
            }
            else{

                event.second.first = 0;
                swap(event.first, event.second.second);
                opened.erase(opened.find(event));
                if(opened.size() == 0)
                    segments.push_back({last_opened, event.second.second});
            }
        }

        return segments;
    }
};
