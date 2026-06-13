class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int sum =0;
        string res="";
        map<int,char>hash;
        char ch ='z';
        for(int i =0;i<26;i++,ch--){
            hash[i] = ch;
        }
        for(int i =0;i<words.size();i++){
            sum=0;
            for(int j=0;j<words[i].size();j++){
                int w = words[i][j]-'a';
                sum += weights[w];
            }
            sum = sum % 26;
            res += hash[sum];
        }
        return res;
    }
};