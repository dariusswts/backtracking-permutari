#ifndef TEMA9_H_INCLUDED
#define TEMA9_H_INCLUDED
#include <iostream>
using namespace std;


#include <iostream>
#include <cstdlib>
using namespace std;

int n, x[20], t;

bool valid(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(k>1 && abs(x[k]-x[k-1])<t){
        return false;
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

void solutie()
{
    cin>>n>>t;
    back(1);


}
#endif // TEMA9_H_INCLUDED
