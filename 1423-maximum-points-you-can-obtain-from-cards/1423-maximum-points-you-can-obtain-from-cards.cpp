class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0;
        int rsum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            lsum +=cardPoints[i];
        }
        int sum=lsum;
        int maxsum=max(lsum,sum);
        int r=n-1;
        for(int i=k-1;i>=0,r>=n-k;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[r];
            r--;
            sum=lsum+rsum;
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};