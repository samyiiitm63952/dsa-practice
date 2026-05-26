class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt=0;
        set<int>st;
        for(auto it:word){
            st.insert(it);
        }

        for(auto it:st){
            if(it>=97 && it<=122){
                if(st.find(it-32)!=st.end()){
                  cnt++;  
                }
            }
        }
        return cnt;
    }
};