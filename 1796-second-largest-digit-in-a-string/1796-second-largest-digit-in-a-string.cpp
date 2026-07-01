class Solution {
public:
    int secondHighest(string s) {
        vector<int>nums;
        for(auto it:s){
            if(it>='0' && it<='9'){
                nums.push_back(it-'0');
            }
        }
        if(!nums.size())return -1;
        sort(nums.begin(),nums.end());
        int largest = nums.back();
        int ans = -1;
        for(int i = nums.size()-1;i>=0;i--){
            if(nums[i]!= largest){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};