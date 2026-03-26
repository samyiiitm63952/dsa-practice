class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        int i=1;
        return n | i<<k;
    }
};
