class Solution {
    struct data{
        double val;
        double wt;
        double ratio;
    };
    static bool comp (const data &a,const data &b){
        return a.ratio>b.ratio;
    }
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
       vector<data> arr(val.size());
        for(int i=0;i<val.size();i++){
            arr[i].val=val[i];
            arr[i].wt=wt[i];
            arr[i].ratio=(double)arr[i].val/arr[i].wt;
        }
        sort(arr.begin(),arr.end(),comp);
        double totalprof=0;
        double wts=0;
        for(int i=0;i<val.size();i++){
          if(wts+arr[i].wt<=capacity){
              totalprof += arr[i].val;
              wts +=arr[i].wt;
              
          }
          else{
              double remain =capacity - wts;
              totalprof += arr[i].ratio*remain;
              break;
          }
        }
        return totalprof;
    }
};
