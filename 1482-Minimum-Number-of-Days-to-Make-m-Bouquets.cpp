typedef long long ll;
typedef vector<int> vi;
#define maxEle *max_element(v.begin(), v.end())

int possible(vi v, int bouquet, int k, int days){
    ll flowers{}, bouquets{};
    for(int i = 0; i < v.size(); ++i){
        if(v[i] <= days){
            flowers++;
            if(flowers >= k)
                bouquets++, flowers = 0;
            if(bouquets == bouquet)
                return 1;
        }
        else flowers = 0;
    }
    return 0;
}

class Solution {
public:
    int minDays(vector<int>& v, int m, int k){
        int start{}, end = maxEle, ans{};
        if((ll)m * (ll)k > v.size()) return -1;
        while(start <= end){
        ll mid = start + (end - start) / 2;
        if(possible(v, m, k, mid))
            end = mid - 1, ans = mid;
        else start = mid + 1;
    }       
    return ans;
    }
};