class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        stack<double> s;
        vector<pair<int,int>> cars;
        for(int i=0;i<n;i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end(),[](auto &a, auto &b){
            return a.first>b.first;
        });
        for(auto p:cars){
            double time = (double)(target-p.first)/p.second;
            s.push(time);
            if(s.size()>=2){
            double first = s.top();
            s.pop();
            double secTop = s.top();
            s.push(first);
            
            if(s.top()<=secTop){
                s.pop();
                }
            }
        }
        return s.size();
    }
};
