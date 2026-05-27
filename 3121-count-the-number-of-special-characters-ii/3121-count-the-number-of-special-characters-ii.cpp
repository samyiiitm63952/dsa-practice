class Solution {
public:

    int numberOfSpecialChars(string word) {

        vector<int> lastSmall(26, -1);
        vector<int> firstCapital(26, -1);

        for(int i = 0; i < word.size(); i++) {

            char ch = word[i];

            if(ch >= 'a' && ch <= 'z') {
                lastSmall[ch - 'a'] = i;
            }

            else {
                if(firstCapital[ch - 'A'] == -1) {
                    firstCapital[ch - 'A'] = i;
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i < 26; i++) {

            if(lastSmall[i] != -1 &&
               firstCapital[i] != -1 &&
               lastSmall[i] < firstCapital[i]) {

                cnt++;
            }
        }

        return cnt;
    }
};