class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        int prev=INT_MIN;
        int curr=0;
        int rank=1;
        vector<int>rankans(arr.size());
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            curr=top.first;
            if(curr==prev){
                rankans[top.second]=rank-1;
            }
            else{
                rankans[top.second]=rank;
                rank++;
            }
            prev=curr;
        }
        return rankans;
    }
};