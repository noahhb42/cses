#include"bits/stdc++.h"
using namespace std;
 
void hanoi(int n, int left, int middle, int right){
    if(n==1){
        cout << left << " " << right << "\n";
    }
    else{
        hanoi(n-1,left,right,middle);
        cout << left << " " << right << "\n";
        hanoi(n-1,middle,left,right);
    }
}
 
int main(){
    int n;cin>>n;
    cout << (1<<n)-1 << "\n";
    hanoi(n,1,2,3);
}