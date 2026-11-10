#ifndef TEMA5_H_INCLUDED
#define TEMA5_H_INCLUDED
#include <iostream>
using namespace std;
int n, x[20], t;

bool valid5(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    int cnt=0;
    for(int i=1;i<=k;i++){
        if(x[i]==i){
            cnt++;
        }
    }
    if(cnt>t){
        return false;
    }

    if(k==n && cnt!=t){
        return false;
    }

    return true;
}
void afisare5()
{
    for(int i=1;i<=n;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
void back5(int k)
{
    for(int v=1;v<=n;v++){
        x[k]=v;
        if(valid5(k)){
            if(k==n){
                afisare5();
            }
            else{
                back5(k+1);
            }
        }
    }
}
void permutariPuncteFixe()
{
    cin>>n>>t;
    back5(1);
}

#endif // TEMA5_H_INCLUDED
