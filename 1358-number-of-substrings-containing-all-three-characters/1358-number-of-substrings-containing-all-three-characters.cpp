class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int r=0;
        int cnt=0;
        int a=0;
        int b=0;
        int c=0;
        while(r<s.size()){
            if(s[r]=='a') a++;
            if(s[r]=='b')b++;
            if(s[r]=='c')c++;
            while(a>0 && b>0 && c>0 ){
                 cnt += (s.size() - r);
                   if(s[l] == 'a') a--;
                if(s[l] == 'b') b--;
                if(s[l] == 'c') c--;
                 l++;
            }
            r++;
        }
        return cnt;
    }
};