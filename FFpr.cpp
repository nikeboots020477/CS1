#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <math.h>
#include <sstream>
using namespace std;

#define INF 9999999999999999

int main(){


 ifstream in("sc_9_0");
    int N, M,ll=0;
    int i, j, k, flag;
    string nums;
    getline(in, nums);
    stringstream stream(nums);
    stream >> N >> M;
    flag = N;
    vector <int> cost(M);
     vector <int> sm(N);
     vector <int> re(M);
    vector<vector<int> > T(N, vector<int> (M));

    for(k=0; k<M; k++){
        getline(in, nums);
        stringstream stream(nums);
        int n;
        stream >> cost[k];
        while(stream >> n) {
        T[n][k] = 1;
        }
    }
    

    cout<<endl;
    int sum;
    int it,uu=1;
    while(uu>0){
        uu=0;
        int min=INF;
        
        for(i=0;i<N;i++) sm[i]=0;
        for(i=0;i<N;i++){sum=0;
        for(j=0;j<M;j++){sum=sum + T[i][j];  }
        sm[i]=sum;
        if(sm[i]<min && sm[i]!=0) {min = sm[i]; it=i;}
        }
        int it2;
        int sum2=0;
        int max=0;
        for(i=0;i<M;i++) {
            if (T[it][i] == 1) {
                for(j=0;j<N;j++) sum2 = sum2 + T[j][i];}
            if(sum2>max && sum2) {max=sum2; it2=i;} 
        }
        re[it2]=1;
        for(i=0;i<N;i++) {
            if (T[i][it2] == 1) {for(j=0;j<M;j++) T[i][j]=0;  }
        }
    
    
    for(i=0;i<N;i++) uu=uu+sm[i];
    }
    cout<<endl;
    cout<<endl;
    for(i=0;i<M;i++) cout<<re[i]<<" " ;
    

    return 0;
}