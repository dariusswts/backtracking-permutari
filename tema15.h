#ifndef TEMA15_H_INCLUDED
#define TEMA15_H_INCLUDED
#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

int n, m, x[20], a[20];

bool valid(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(k<=m && k>1 && a[x[k]]<=a[x[k-1]]){
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
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    back(1);

}

#endif // TEMA15_H_INCLUDED
