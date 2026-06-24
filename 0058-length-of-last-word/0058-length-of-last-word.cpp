class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size() - 1;

        while (end >= 0 && s[end] == ' ') {
            end--;
        }

        int len = 0;

        for (int i = end; i >= 0; i--) {
            if (s[i] == ' ') {
                break;
            }
            len++;
        }

        return len;
    }
};