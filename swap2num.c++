#include<iostream>
#include<pairs>
#include<algorithm>
using namespace std;
class Solution {
  public:
    pair<int, int> get(int a, int b) {
        // code here
        a=a^b;
        b=a^b;
        a=a^b;
        return {a,b};
    }
};