#ifndef PERMUTARI-VECINI_H_INCLUDED
#define PERMUTARI-VECINI_H_INCLUDED
#include <iostream>
using namespace std;


int n, m, s, t, a[20], x[20];


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


bool validPermutariVecini(int k)
{
    if (!nou(k))
    {
        return false;
    }
    if (k > 1 && (x[k] - x[k - 1] == 1 || x[k - 1] - x[k] == 1))
    {
        return false;
    }
    return true;
}

void backPermutariVecini(int k)
{
    for (int v = 1; v <= n; v++)
    {
        x[k] = v;
        if (validPermutariVecini(k))
        {
            if (k == n)
            {
                afisare(n);
            }
            else
            {
                backPermutariVecini(k + 1);
            }
        }
    }
}

void permutariVecini()
{
    backPermutariVecini(1);
}

/// problema 3_1
///1 și n alăturate Afișează, în ordine lexicografică, permutările mulțimii {1, 2, …, n } ( n ≥ 2) în care elementele 1 și n sunt vecine, în oricare ordine.

bool validNsi1Veci(int k){
    if(!nou(k)){
        return false;
    }
    if(k>1 &&(x[k] - x[k - 1] == 1 || x[k - 1] - x[k] == 1)){
        return false;
    }
    return true;
}

void backNsi1Veci(int k){
    for(int v=1;v<=n;v++){
        x[k]=v;
        if(validNsi1Veci(k)){
            if(k==n){
                afisare(n);
            }else{
                backNsi1Veci(k+1);
            }
        }
    }

}


void solutie3_1(){
    cin>>n;
    backNsi1Veci(1);
}







#endif // PERMUTARI-VECINI_H_INCLUDED
