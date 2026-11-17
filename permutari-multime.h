#ifndef PERMUTARI-MULTIME_H_INCLUDED
#define PERMUTARI-MULTIME_H_INCLUDED
#include <iostream>;
usign namespace std;


void afisareValori(int lungime)
{
    for (int i = 1; i <= lungime; i++)
    {
        if (i > 1)
        {
            cout << " ";
        }
        cout << a[x[i]];
    }
    cout << endl;
}

bool validPermutariVector(int k)
{
    return nou(k);
}

void backPermutariVector(int k)
{
    for (int v = 1; v <= n; v++)
    {
        x[k] = v;
        if (validPermutariVector(k))
        {
            if (k == n)
            {
                afisareValori(n);
            }
            else
            {
                backPermutariVector(k + 1);
            }
        }
    }
}

void permutariVector()
{
    backPermutariVector(1);
}


///4.1
int n, x[20];
char l[20];

bool vocala(char c)
{
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

bool valid4_1(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(k==1 && vocala(l[x[k]])==false){
        return false;
    }

    return true;
}


void back4_1(int k)
{
    for(int v=1;v<=n;v++){
        x[k]=v;

        if(valid(k)){
            if(k==n){
                afisare();
            }
            else{
                back4_1(k+1);
            }
        }
    }
}

void solutie()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    back4_1(1);

}
///4_2
bool vocala4_2(char c)
{
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

bool valid4_2(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(k>1 && vocala4_2(l[x[k]]) && vocala4_2(l[x[k-1]])){
        return false;
    }

    return true;
}

void afisare4_2()
{
    for(int i=1;i<=n;i++){
        cout<<l[x[i]];
    }
    cout<<endl;
}

void back4_2(int k)
{
    for(int v=1;v<=n;v++){
        x[k]=v;

        if(valid(k)){
            if(k==n){
                afisare4_2();
            }
            else{
                back4_2(k+1);
            }
        }
    }
}

void solutie4_2()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    back4_2(1);
}

///4_3
bool vocala4_3(char c)
{
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

bool valid4_3(int k)
{
    for(int i=1;i<k;i++){
        if(x[i]==x[k]){
            return false;
        }
    }

    if(vocala(l[x[k]])){
        for(int i=1;i<k;i++){
            if(vocala4_3(l[x[i]]) && l[x[i]]>l[x[k]]){
                return false;
            }
        }
    }

    return true;
}

void afisare4_3()
{
    for(int i=1;i<=n;i++){
        cout<<l[x[i]];
    }
    cout<<endl;
}

void back4_3(int k)
{
    for(int v=1;v<=n;v++){
        x[k]=v;

        if(valid4_3(k)){
            if(k==n){
                afisare4_3();
            }
            else{
                back4_3(k+1);
            }
        }
    }
}

void solutie4_3()
{
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>l[i];
    }



    back4_3(1);

}

///4_4

bool folosit[20];

bool valid4_4(int k)
{
    if(k>1 && l[x[k]]==l[x[k-1]] && folosit[x[k-1]]==false){
        return false;
    }

    return true;
}

void afisare4_4()
{
    for(int i=1;i<=n;i++){
        cout<<l[x[i]];
    }
    cout<<endl;
}

void back4_4(int k)
{
    for(int v=1;v<=n;v++){
        if(folosit[v]==false){
            x[k]=v;

            if(valid4_4(k)){
                folosit[v]=true;

                if(k==n){
                    afisare4_4();
                }
                else{
                    back4_4(k+1);
                }

                folosit[v]=false;
            }
        }
    }
}

void solutie4_4()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i];}
    back4_4(1);

}



#endif // PERMUTARI-MULTIME_H_INCLUDED
