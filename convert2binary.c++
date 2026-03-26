#include<iostream>
#include<string>
#include<algorithm>
string convert2binary(int num){
    if(num==0)return "0";
    string res ="";
    while (num!=0)
    {
        if(num%2==1){
            res+="1";
        }
        else {
            res+="0";
        }
    num=num/2;
    }
    reverse(res.begin(),res.end());
    return res;
    
}
int main(){
    cout<<convert2binary(84);
    return 0;
}