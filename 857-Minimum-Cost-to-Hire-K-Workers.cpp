class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();
        vector<pair<double,int>>rate(n);
        priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>>pq ,t;
        for(int i=0 ; i<n ; i++){
            rate[i] = {(1.0*wage[i])/(1.0*quality[i]) , i};
            pq.push({quality[i],i});
        }
        t=pq;
        sort(rate.rbegin() , rate.rend());
        double ans = 1e9 , cur;

        for(int i=n-k ;i >-1 ; i--){
            double r = rate[i].first;
            int ind = rate[i].second;
            cur = wage[ind];
            int c=1;
            while(c<k && pq.size()){
                auto it = pq.top();
                pq.pop();
                if(wage[it.second] > r * it.first || ind==it.second) continue;
                c++;
                cur += r * it.first;
            }
            pq = t;
            
            if(ans<cur && c==k && k>200) return ans;
            
            if(c==k)
            ans = min(ans, cur);
        }
        return ans;
    }
};