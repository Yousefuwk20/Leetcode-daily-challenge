class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.length();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(num[i]);
            }
            else if(st.top()>num[i]){
                while(!st.empty() &&  st.top()>num[i] && k>0){
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
            else if(st.top()<=num[i])
                st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans==\\) return\0\;
        int i=0;
        while(ans[i]=='0') i++;
        if(i>0)return ans.substr(i,ans.size()-i)!=\\ ?ans.substr(i,ans.size()-i) : \0\;
return ans;
    }
};