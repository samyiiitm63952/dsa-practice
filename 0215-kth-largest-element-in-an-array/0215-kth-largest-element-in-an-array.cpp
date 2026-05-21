class Solution {
public:
    void heapify(vector<int> &nums,int n,int i){
        int largest =i;
        int li=2*i+1;
        int ri=2*i+2;
        if(li<n && nums[largest]<nums[li]){
            largest =li;
        }
        if(ri<n && nums[largest]<nums[ri]){
            largest =ri;
        }
        if(!(largest==i)){
            swap(nums[largest ],nums[i]);
            heapify(nums,n,largest);
        }
        else{
            return ;
        }
    }

    vector<int>buildheap(vector<int>&nums,int n){
        for(int i=(n/2)-1;i>=0;i--){
            heapify(nums,n,i);
        }
        return nums;
    }

    void removetop(vector<int>&nums,int &n){
        nums[0]=nums[n-1];
        n--;
        heapify(nums,n,0);
    }

    int findKthLargest(vector<int>& nums, int k) {
        if(k>nums.size())return -1;
        int n=nums.size();
        nums =buildheap(nums,nums.size());
        while(k>1){
            removetop(nums,n);
            k--;
        }
        return nums[0];
    }
};