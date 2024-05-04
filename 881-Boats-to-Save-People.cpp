class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int l=0;
        int high=p.size()-1;
        int ans=0;
        while(high>=l){
            int curr=p[high];
            if(curr+p[l]<=limit){
                ans++;
                high--;
                l++;

            }else{
                ans++;
                high--;

            }
        }
        return ans;
        
    }
};