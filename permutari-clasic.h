#ifndef PERMUTARI-CLASIC_H_INCLUDED
#define PERMUTARI-CLASIC_H_INCLUDED

#include <iostream>

using namespace std;

int n, m, s, t, a[20], x[20];
char l[20];

bool nou(int k)
{
    for (int i = 1; i < k; i++)
    {
        if (x[i] == x[k])
        {
            return false;
        }
    }

    return true;
}
bool validPermutari(int k)
{
    return nou(k);
}

void afisare(int lungime)
{
    for (int i = 1; i <= lungime; i++)
    {
        if (i > 1)
        {
            cout << " ";
        }
        cout << x[i];
    }
    cout << endl;
}
void backPermutari(int k)
{
    for (int v = 1; v <= n; v++)
    {
        x[k] = v;
        if (validPermutari(k))
        {
            if (k == n)
            {
                afisare(n);
            }
            else
            {
                backPermutari(k + 1);
            }
        }
    }
}

void permutari()
{
    backPermutari(1);
}


///problema  1.1
bool validParImpar(int k){
     if(!nou(k)){
        return false;
     }

    if(k==1&&x[k]%2==0){
        return false;
    }
    if(k==n&&x[k]%2!=0){
        return false;
    }
    return true;
}


void backParImpar(int k){
    for(int v=1;v<=n;v++){
        x[k]=v;
        if(validParImpar(k)){
            if(k==n){
                afisare(n);
            }
            else{
                backParImpar(k+1);
            }
        }
    }
}

void solutie1_1(){
    cin>>n;
    backParImpar(1);
}


/// problema 1.2
///Afișează, în ordine lexicografică, permutările mulțimii {1, 2, …, n } în care primul element este strict mai mic decât ultimul.


bool validMicStrict(int k){
    if(!nou(k)){
        return false;
    }
    if(k==n&&x[1]>=x[n]){
        return false;
    }
    return true;
}


void backMicStrict(int k){
    for(int v=1;v<=n;v++){
     x[k]=v;
     if(validMicStrict(k)){
         if(k==n){
             afisare(n);
         }
         else{
             backMicStrict(k+1);
         }
     }
    }
}

void solutie1_2(){
    cin>>n;
    backMicStrict(1);
}
























#endif // PERMUTARI-CLASIC_H_INCLUDED
