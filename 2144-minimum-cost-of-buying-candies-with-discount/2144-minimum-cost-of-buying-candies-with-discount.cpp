class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int k=0;
        int sum=0;
        for(int i=0;i<cost.size();i++){
            if(k==2){
                k=0;
                continue;
            }
            sum+=cost[i];
            k++;
            
        }
        return sum;
    }
};