class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> st;

        for(int i = 0; i < nums.size(); i++) {

            int req = target - nums[i];

            if(st.find(req) != st.end()) {
                return {st[req], i};
            }

            st[nums[i]] = i;
        }

        return {-1, -1};
    }
};