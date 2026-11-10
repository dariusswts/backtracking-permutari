#ifndef TEMA4_H_INCLUDED
#define TEMA4_H_INCLUDED
#include <iostream>
using namespace std;
int n, x[20];

bool valid4(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(x[k]==k){
        return false;
    }

    return true;
}

void afisare4()
{
    for(int i=1;i<=n;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void back4(int k)
{
    for(int v=1;v<=n;v++){
        x[k]=v;
        if(valid4(k)){
            if(k==n){
                afisare4();
            }
            else{
                back4(k+1);
            }
        }
    }
}
void permutariFaraPunctFix()
{
    cin>>n;
    back4(1);
}

#endif // TEMA4_H_INCLUDED
