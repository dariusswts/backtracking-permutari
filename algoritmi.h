#ifndef ALGORITMI_H_INCLUDED
#define ALGORITMI_H_INCLUDED

#include <iostream>

using namespace std;






//  datele comune: in headerele tale, ele stau in solutie.h
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

//  schema comuna (forma de bac): x[] global, indexat de la 1
//
//  void back(int k)
//  {
//      for (int v = 1; v <= n; v++)
//      {
//          x[k] = v;
//          if (valid(k))
//          {
//              if (k == n) afisare(n);
//              else back(k + 1);
//          }
//      }
//  }
//
//  difera doar valid(k): la permutari cere x[k] diferit de toate x[1..k-1] (nou) si, in plus, conditia problemei

//  ===== Permutările clasice =====
//  n = 3:  x = 1 _ _  ->  1 2 _  ->  1 2 3 (afisez)  ->  1 3 _  ->  1 3 2 (afisez)  ->  2 _ _  ->  ...
//  pe pozitia 2, v = 1 pica: x[2] == x[1], deci nou(2) e fals si back nu coboara

bool validPermutari(int k)
{
    return nou(k);
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

//  ===== Condiții pe poziții =====
//  n = 3, t = 2:  x = 2 _ _  ->  2 1 _  ->  2 1 3 (afisez)  ->  2 3 _  ->  2 3 1 (afisez)
//  valid(1) taie din prima orice valoare diferita de t: nu mai coboara pe 1 _ _ sau 3 _ _

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

//  ===== Condiții pe vecini =====
//  n = 4:  x = 1 _ _ _  ->  1 2 pica (2 - 1 == 1)  ->  1 3 _ _  ->  1 3 2 pica (2 e vecin cu 3)  ->  1 3 4 pica
//  k > 1 se verifica mereu inainte de x[k - 1]: la k = 1 nu exista vecin

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

//  ===== Permutări ale unei mulțimi date =====
//  a = 5 9 2:  x = 1 _ _  ->  1 2 _  ->  1 2 3 (afisez a[1] a[2] a[3] = 5 9 2)  ->  1 3 2 (afisez 5 2 9)
//  x[] tine indicii, nu valorile: nou(k) compara indicii, afisarea citeste a[x[i]]

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

//  ===== Anagrame =====
//  l = a c e:  x = 1 _ _  ->  1 2 _  ->  1 2 3 (afisez l[1] l[2] l[3] = ace)  ->  1 3 2 (afisez aec)
//  ca la mulțimea dată: x[] are indici de litere, afisarea scrie l[x[i]], fără spații

void afisareLitere(int lungime)
{
    for (int i = 1; i <= lungime; i++)
    {
        cout << l[x[i]];
    }
    cout << endl;
}

bool validAnagrame(int k)
{
    return nou(k);
}

void backAnagrame(int k)
{
    for (int v = 1; v <= n; v++)
    {
        x[k] = v;
        if (validAnagrame(k))
        {
            if (k == n)
            {
                afisareLitere(n);
            }
            else
            {
                backAnagrame(k + 1);
            }
        }
    }
}

void anagrame()
{
    backAnagrame(1);
}

bool validAnagrameDistincte(int k)
{
    if (!nou(k))
    {
        return false;
    }
    if (x[k] > 1 && l[x[k]] == l[x[k] - 1])
    {
        bool folosit = false;
        for (int i = 1; i < k; i++)
        {
            if (x[i] == x[k] - 1)
            {
                folosit = true;
            }
        }
        if (!folosit)
        {
            return false;
        }
    }
    return true;
}

void backAnagrameDistincte(int k)
{
    for (int v = 1; v <= n; v++)
    {
        x[k] = v;
        if (validAnagrameDistincte(k))
        {
            if (k == n)
            {
                afisareLitere(n);
            }
            else
            {
                backAnagrameDistincte(k + 1);
            }
        }
    }
}

void anagrameDistincte()
{
    backAnagrameDistincte(1);
}

void exemple()
{
    cout << "--- Permutările clasice ---" << endl;
    cout << "n = 3" << endl;
    n = 3;
    permutari();
    cout << endl;
    cout << "n = 1" << endl;
    n = 1;
    permutari();
    cout << endl;

    cout << "--- Condiții pe poziții ---" << endl;
    cout << "n = 3 , t = 2" << endl;
    n = 3;
    t = 2;
    permutariPrimEgal();
    cout << endl;
    cout << "n = 4 , t = 4" << endl;
    n = 4;
    t = 4;
    permutariPrimEgal();
    cout << endl;

    cout << "--- Condiții pe vecini ---" << endl;
    cout << "n = 4" << endl;
    n = 4;
    permutariVecini();
    cout << endl;
    cout << "n = 3" << endl;
    n = 3;
    permutariVecini();
    cout << endl;

    cout << "--- Permutări ale unei mulțimi date ---" << endl;
    cout << "a = 5 9 2" << endl;
    n = 3;
    a[1] = 5;
    a[2] = 9;
    a[3] = 2;
    permutariVector();
    cout << endl;

    cout << "--- Anagrame ---" << endl;
    cout << "l = a c e" << endl;
    n = 3;
    l[1] = 'a';
    l[2] = 'c';
    l[3] = 'e';
    anagrame();
    cout << endl;
    cout << "l = a a b" << endl;
    n = 3;
    l[1] = 'a';
    l[2] = 'a';
    l[3] = 'b';
    anagrameDistincte();
    cout << endl;
}

#endif // ALGORITMI_H_INCLUDED
