#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int convert2decimal(string bin){
    int res = 0;

    for(int i = bin.size() - 1; i >= 0; i--){
        res = res + (bin[i] - '0') * pow(2, (bin.size() - 1 - i));
    }

    return res;
}

int main(){
    string bin = "1011";
    cout << convert2decimal(bin);
}