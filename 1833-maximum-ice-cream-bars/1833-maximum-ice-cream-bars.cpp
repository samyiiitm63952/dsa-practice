class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int icream=0;
        if(costs[0]>coins)return icream;
        for(int i =0;i<costs.size();i++){
            if(costs[i]<=coins){
                coins -= costs[i];
                icream++;
                
            }
        }
        return icream;
    }
};