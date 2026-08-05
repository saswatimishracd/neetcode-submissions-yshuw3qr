class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> timeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>> searchSpace = timeMap[key];
        int left= 0; int right = searchSpace.size()-1;
        string result="";
        while(left<=right){
            int mid = left+(right-left)/2;
            if(searchSpace[mid].first==timestamp) return searchSpace[mid].second;
            else if(searchSpace[mid].first<timestamp) {
                left = mid+1;
                result = searchSpace[mid].second;
            }
            else {
                right = mid-1;
            }
        }
        return result;
    }
};
// We are going to add the key to a hash map
// against the key we are going to add a vector of pairs of value string & timestamp
// during the get by matching the key the timestamp that we give
// we will perform binary search upon the 1st value of the pairs of the key
// if the mid is same as the timestamp then we return mid pair second element
// if not we check whether any prev index has any string then we return
// else we return false