#ifndef PERMUTARI-ANAGRAME_H_INCLUDED
#define PERMUTARI-ANAGRAME_H_INCLUDED
#include <iostream>
using namespace std;

int n, x[20];
char l[20];

///5_1
bool vocala(char c)
{
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

bool valid5_1(int k)
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

void back5_1(int k)
{
    for(int v=1;v<=n;v++){
        x[k]=v;

        if(valid5_1(k)){
            if(k==n){
                afisare();
            }
            else{
                back5_1(k+1);
            }
        }
    }
}

void anagrameVocalaInceput5_1()
{
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    back5_1(1);
}

///5_2
int n, x[20];
char l[20];



bool valid5_2(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }
    if(k>1 && vocala(l[x[k]]) && vocala(l[x[k-1]])){
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

void back5_2(int k)
{
    for(int v=1;v<=n;v++){
        x[k]=v;
        if(valid5_2(k)){
            if(k==n){
                afisare();
            }
            else{
                back5_2(k+1);
            }
        }
    }
}

void anagrameFaraVocaleAlaturate5_2()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    back5_2(1);
}



#endif // PERMUTARI-ANAGRAME_H_INCLUDED
