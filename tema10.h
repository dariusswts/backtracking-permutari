#ifndef TEMA10_H_INCLUDED
#define TEMA10_H_INCLUDED
#include <iostream>
using namespace std;

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

    if(k>1 && x[k]%2==x[k-1]%2){
        return false;
    }

    if(k==n && x[n]%2==x[1]%2){
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
    cin>>n;
    back(1);

}

#endif // TEMA10_H_INCLUDED
