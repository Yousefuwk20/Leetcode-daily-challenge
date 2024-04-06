typedef vector<int> vi;

int possible(vi v, int div){
        int sum{};
		for (int i = 0; i < (int) v.size(); i++)
		sum += (v[i] + div - 1) / div;
		return sum;
}


class Solution {
public:
    int smallestDivisor(vector<int>& v, int k){
        int start = 1, end = *max_element(v.begin(), v.end()), div = end;
        while(start <= end){
        int mid = start + (end - start) / 2;
        if(possible(v, mid) <= k)
            end = mid - 1, div = mid;
        else start = mid + 1;
    }
    return div;
    }
};

