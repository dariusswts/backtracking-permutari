#ifndef PERMUTARI-POZITII_H_INCLUDED
#define PERMUTARI-POZITII_H_INCLUDED
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


bool validPermutariPrimEgal(int k)
{
    if (!nou(k))
    {
        return false;
    }
    if (k == 1 && x[k] != t)
    {
        return false;
    }
    return true;
}

void backPermutariPrimEgal(int k)
{
    for (int v = 1; v <= n; v++)
    {
        x[k] = v;
        if (validPermutariPrimEgal(k))
        {
            if (k == n)
            {
                afisare(n);
            }
            else
            {
                backPermutariPrimEgal(k + 1);
            }
        }
    }
}

void permutariPrimEgal()
{
    backPermutariPrimEgal(1);
}


///problema 2.1
///Afișează, în ordine lexicografică, permutările mulțimii {1, 2, …, n } (1 ≤ m ≤ n ) în care pe poziția m se află elementul t .

bool validPozM(int k){
    if(!nou(k)){
        return false;
    }
    if(k==m&&x[k]!=t){
        return false;
    }
    return true;
}

void backPozM(int k){
    for(int v=1;v<=n;v++){
        x[k]=v;
        if(validPozM(k)){
            if(k==n){
                afisare(n);
            }else{
                backPozM(k+1);
            }
        }
    }
}


void solutie2_1(){
    cin>>n>>m>>t;
    backPozM(1);
}

///problema 2_2
///Afișează, în ordine lexicografică, permutările mulțimii {1, 2, …, n } în care fiecare element are aceeași paritate cu poziția lui ( x[k] % 2 == k % 2 ).

bool validPozParitate(int k){
    if(!nou(k)){
      return false;
    }

    if(x[k]%2!=k%2){
        return false;
    }
    return true;
}

void backPozParitate(int k){
    for(int v=1;v<=n;v++){
        x[k]=v;
        if(validPozParitate(k)){
            if(k==n){
                afisare(n);
            }else{
                backPozParitate(k+1);
            }
        }
    }
}

void solutie2_2(){
    cin>>n;
    backPozParitate(1);
}



















#endif // PERMUTARI-POZITII_H_INCLUDED
