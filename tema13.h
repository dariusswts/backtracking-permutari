#ifndef TEMA13_H_INCLUDED
#define TEMA13_H_INCLUDED
#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

int n, x[20], a[20];

bool valid(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(k==1 && a[x[k]]==a[1]){
        // Nu verificăm maximul aici.
    }

    if(k==n){
        int poz=1;

        for(int i=2;i<=n;i++){
            if(a[i]>a[poz]){
                poz=i;
            }
        }

        if(x[1]==poz || x[n]==poz){
            return false;
        }
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

#endif // TEMA13_H_INCLUDED
