#ifndef TEMA19_H_INCLUDED
#define TEMA19_H_INCLUDED
#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

int n, x[20];
char l[20];
bool folosit[20];

bool valid(int k)
{
    if(k>1 && l[x[k]]==l[x[k-1]] && folosit[x[k-1]]==false){
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
        if(folosit[v]==false){
            x[k]=v;

            if(valid(k)){
                folosit[v]=true;

                if(k==n){
                    afisare();
                }
                else{
                    back(k+1);
                }

                folosit[v]=false;
            }
        }
    }
}

void solutie()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i];}
    back(1);

}

#endif // TEMA19_H_INCLUDED
