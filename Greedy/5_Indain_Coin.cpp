#include <iostream>
#include <vector>
using namespace std;

int countChange(vector<int> Coins,int V){
    int ans=0;
    for(int i=Coins.size()-1;i>=0 && V>0;i--){
        if(V >= Coins[i]){
            ans+=V/Coins[i];
            V=V%Coins[i];
        }
    }
    return ans;
}


int main(){
    vector<int> Coins={1,2,5,10,20,50,100,500,2000};
    int V=590;
    cout<<countChange(Coins,V);
    return 0;
}