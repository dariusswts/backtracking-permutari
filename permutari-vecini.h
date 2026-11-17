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
    int p1;
    int pn;
    if(!nou(k)){
        return false;
    }

    for(int i=1;i<n;i++){
        if(x[i]==1){
            p1=i;
        }
        if(x[i]==n){
            pn=i;
        }
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

///3.2

void afisare3_2()
{
    for(int i=1;i<=n;i++){
        cout<<a[x[i]]<<" ";
    }
    cout<<endl;
}
bool valid3_2(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(k>1 && a[x[k]]%2==a[x[k-1]]%2){
        return false;
    }

    return true;
}
void back3_2(int k)
{
    for(int v=1;v<=n;v++){
        x[k]=v;

        if(valid3_2(k)){
            if(k==n){
                afisare3_2();
            }
            else{
                back3_2(k+1);
            }
        }
    }
}

void solutie3_2()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    back3_2(1);

}

///3.3
bool valid(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(k==1 && a[x[k]]==a[1]){

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

///3.4
bool prim3_4(int nr)
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

bool valid3_4(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(k>1 && prim3_4(a[x[k]]+a[x[k-1]])==false){
        return false;
    }

    return true;
}

void afisare3_4()
{
    for(int i=1;i<=n;i++){
        cout<<a[x[i]]<<" ";
    }
    cout<<endl;
}

void back3_4(int k)
{
    for(int v=1;v<=n;v++){
        x[k]=v;

        if(valid3_4(k)){
            if(k==n){
                afisare3_4();
            }
            else{
                back3_4(k+1);
            }
        }
    }
}
void solutie3_4()
{
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    back3_4(1);

}

///3.5
bool valid3_5(int k)
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

void afisare3_5()
{
    for(int i=1;i<=n;i++){
        cout<<a[x[i]]<<" ";
    }
    cout<<endl;
}

void back3_5(int k)
{
    for(int v=1;v<=n;v++){
        x[k]=v;

        if(valid(k)){
            if(k==n){
                afisare3_5();
            }
            else{
                back3_5(k+1);
            }
        }
    }
}

void solutie3_5()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    back(1);

}







#endif // PERMUTARI-VECINI_H_INCLUDED
