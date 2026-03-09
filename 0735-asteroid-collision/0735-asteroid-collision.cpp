class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ans) {
       vector<int>asnd;
    stack<int>st;
    for(int i=0;i<ans.size(); i++){
       if(ans[i] > 0){
        st.push(ans[i]);
       }
      else{
        while(!st.empty() && st.top() > 0 && st.top() < abs(ans[i])){
            st.pop();
        }
        if(!st.empty() && st.top()==abs(ans[i])){
            st.pop();
        }
        else if(st.empty() || st.top() < 0){
            st.push(ans[i]);
        }
      }
    }
    while(!st.empty()){
        asnd.push_back(st.top());
        st.pop();
    }
    reverse(asnd.begin(), asnd.end());
    return asnd;
    }
};