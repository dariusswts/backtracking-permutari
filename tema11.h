#ifndef TEMA11_H_INCLUDED
#define TEMA11_H_INCLUDED
#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

int n, x[20], a[20], s;

bool valid(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(k==n && a[x[1]]+a[x[n]]!=s){
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

    cin>>s;
    back(1);

}

#endif // TEMA11_H_INCLUDED
