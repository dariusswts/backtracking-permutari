#ifndef TEMA2_H_INCLUDED
#define TEMA2_H_INCLUDED
#include <iostream>
using namespace std;

int n, x[20];

bool valid2(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(k==n && x[1]>=x[n]){
        return false;
    }

    return true;
}

void afisare2()
{
    for(int i=1;i<=n;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void back2(int k)
{
    for(int v=1;v<=n;v++){
        x[k]=v;

        if(valid2(k)){
            if(k==n){
                afisare2();
            }
            else{
                back2(k+1);
            }
        }
    }
}
void permutariPrimMic()
{
    cin>>n;
    back2(1);
}


#endif // TEMA2_H_INCLUDED
