class Solution {
public:

    bool check(vector<int>& nums) {

        int i = 0;
        int k = 0;

        while(k < nums.size()){

            if(nums[i] > nums[(i+1)%nums.size()]){

                int l = 0;
                i = (i+1)%nums.size();

                while(l < nums.size()-1){

                    if(nums[i] > nums[(i+1)%nums.size()]){
                        return false;
                    }

                    i = (i+1)%nums.size();
                    l++;
                }

                break;
            }

            i = (i+1)%nums.size();
            k++;
        }

        return true;
    }
};