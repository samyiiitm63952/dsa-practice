class Solution {
public:
    int candy(vector<int>& ratings) {
        int left[ratings.size()];
        int right[ratings.size()];
        left[0]=1;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                left[i]= left[i-1]+1;
            }
            else {
                left[i]=1;
            }
        }
        right[ratings.size()-1]=1;
        int sum=max(left[ratings.size()-1],right[ratings.size()-1]);
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }
            else{
                right[i]=1;
            }
            sum += max(left[i],right[i]);
        }
    
    return sum;}
};