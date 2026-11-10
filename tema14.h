#ifndef TEMA14_H_INCLUDED
#define TEMA14_H_INCLUDED
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int n, x[20], a[20];

bool prim(int nr)
{
    if(nr<2){
        return false;
    }

    for(int d=2;d*d<=nr;d++){
        if(nr%d==0){
            return false;
        }
    }

    return true;
}

bool valid(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(k>1 && prim(a[x[k]]+a[x[k-1]])==false){
        return false;
    }

    return true;
}

void afisare()
{
    for(int i=1;i<=n;i++){
        cout<<a[x[i]]<<" ";
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

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    back(1);

}

#endif // TEMA14_H_INCLUDED
