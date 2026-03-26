class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        int i=1;
            if(n&i<<k){
                return true;
            }
            else{
                false;
            }
    }
};