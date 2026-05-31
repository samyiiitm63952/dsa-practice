class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long power =mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<asteroids.size();i++){
            if(power>=asteroids[i])power+=asteroids[i];
            else return false;
        }
        return true;
    }
};