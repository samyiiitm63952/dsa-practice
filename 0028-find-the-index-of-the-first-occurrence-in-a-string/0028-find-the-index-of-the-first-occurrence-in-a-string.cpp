class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m > n)
            return -1;
        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};