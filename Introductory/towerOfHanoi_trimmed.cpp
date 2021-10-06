// Author: Vishvesh Trivedi (NerdyVisky)
// Solution to the problem - Tower of Hanoi under the CSES Introductory Problem set.

#include <bits/stdc++.h>
using namespace std;

int hanoiMoves(int n){
    return ((1<<n)-1);
}

void hanoi(int n, int start, int end){
   if(n==1){
       cout<<(start)<<(" ")<<(end)<<endl;
       return;
   }
   int other = 6 - (start + end);
   hanoi(n-1, start, other);
   cout<<(start)<<(" ")<<(end)<<endl;
   hanoi(n-1, other, end);
   return;
}

int main(){
    int n;
    cin>>n;
    cout<<(hanoiMoves(n))<<endl;
    hanoi(n, 1, 3);
    return 0;
}