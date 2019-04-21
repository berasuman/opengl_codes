#include <bits/stdc++.h>
using namespace std;
int main(){
    int xf=785,yf=150;
    int n=8;
    while(n--){
        int x,y;
        cin>>x>>y;
        int m;
        m=2; // the scaling factor
        int ansx,ansy;
        ansx=((x-xf)*m)+x;
        ansy=((y-yf)*m)+y;
        cout<<"X: "<<ansx<<"Y: "<<ansy<<endl;
    }
}