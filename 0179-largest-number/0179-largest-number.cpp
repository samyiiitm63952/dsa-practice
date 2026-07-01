class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>temp;
        for(auto it:nums){
            temp.push_back(to_string(it));
        }
        sort(temp.begin(),temp.end(),[](string &a,string &b){
            return a+b > b+a;
        });
        string ans="";
        for(auto it:temp){
            ans += it;
        }
          if (ans[0] == '0') return "0";
        return ans;
    }
};