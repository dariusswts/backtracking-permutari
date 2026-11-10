#ifndef TEMA6_H_INCLUDED
#define TEMA6_H_INCLUDED
#include <iostream>
using namespace std;

int n, x[20];

bool valid(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(k==n){
        int p1=0, pn=0;

        for(int i=1;i<=n;i++){
            if(x[i]==1){
                p1=i;
            }
            if(x[i]==n){
                pn=i;
            }
        }

        if(abs(p1-pn)!=1){
            return false;
        }
    }

    return true;
}

void afisare()
{
    for(int i=1;i<=n;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void back(int k)
{
    for(int v=1;v<=n;v++){
        x[k]=v;
        if(valid(k)){
            if(k==n){
                afisare();
            }
            else{
                back(k+1);
            }
        }
    }
}

void rezolvare()
{
    cin>>n;
    back(1);
}

#endif // TEMA6_H_INCLUDED
