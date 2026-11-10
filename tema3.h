#ifndef TEMA3_H_INCLUDED
#define TEMA3_H_INCLUDED
#include <iostream>
using namespace std;
int n, x[20];

bool valid3(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(x[k]==n){
        bool gasit=false;

        for(int i=1;i<k;i++){
            if(x[i]==1){
                gasit=true;
            }
        }

        if(gasit==false){
            return false;
        }
    }

    return true;
}

void afisare3()
{
    for(int i=1;i<=n;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void back3(int k)
{
    for(int v=1;v<=n;v++){
        x[k]=v;

        if(valid3(k)){
            if(k==n){
                afisare3();
            }
            else{
                back3(k+1);
            }
        }
    }
}

void permutariUnuInainte()
{
    cin>>n;
    back3(1);
}

#endif // TEMA3_H_INCLUDED
