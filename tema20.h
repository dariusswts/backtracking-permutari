#ifndef TEMA20_H_INCLUDED
#define TEMA20_H_INCLUDED
#include <iostream>
using namespace std;

int n, x[20];
char l[20];

bool vocala(char c)
{
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

bool valid(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(k==1 && !vocala(l[x[k]])){
        return false;
    }

    return true;
}

void afisare()
{
    for(int i=1;i<=n;i++){
        cout<<l[x[i]];
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

void anagrameVocalaInceput()
{
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    back(1);
}

#endif // TEMA20_H_INCLUDED
