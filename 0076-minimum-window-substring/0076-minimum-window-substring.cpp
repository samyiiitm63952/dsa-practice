class Solution {

public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);

        // store frequency of t
        for(char c : t){
            freq[c]++;
        }

        int l = 0, count = t.size();
        int minLen = INT_MAX, start = 0;

        for(int r = 0; r < s.size(); r++){
            // if char is needed
            if(freq[s[r]] > 0){
                count--;
            }
            freq[s[r]]--;

            // when valid window found
            while(count == 0){
                // update answer
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    start = l;
                }

                // try to shrink
                freq[s[l]]++;
                if(freq[s[l]] > 0){
                    count++;
                }
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};