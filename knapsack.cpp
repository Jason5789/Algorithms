#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int s[8][17];
int v[8] = {0,8,6,15,3,2,5,9};
int w[8] = {0,2,3,5,4,3,2,6};

int main(){
    for(int i=0 ; i<8 ; i++){
        for(int j=0 ; j<17 ; j++){
            s[i][j] = 0;
        }
    }

    for(int k=0 ; k<18 ; k++){
        s[0][k]=0;
    }
    
    
    for(int i=0 ; i<8 ; i++){
        s[i][0]=0;
        for(int k=1 ; k<17 ; k++){
            if(i!=0){
                if(k<w[i]){
                    s[i][k] = s[i-1][k];
                }
                else{
                    s[i][k] = max( s[i-1][k] , v[i]+s[i-1][k-w[i]] );
                }
            }
        }
    }

    for(int i=0 ; i<8 ; i++){
        for(int j=0 ; j<17 ; j++){
            cout<<s[i][j]<<" ";
        }
        cout <<endl;
    }
    
    return 0;
}
