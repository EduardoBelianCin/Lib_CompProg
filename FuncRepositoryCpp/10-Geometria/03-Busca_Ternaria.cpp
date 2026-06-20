#include <bits/stdc++.h>
using namespace std;

long double X2(long double x) { return x*x; }

// Requisitos:
// Função Unimodal (começa monotonica crescente/decrescente e termina o inverso)
// *obs: no ponto de maximo/minimo, pode ser constante mas é dificil de ter

// k * f(x)  , k >= 0
// f(x) + g(x)
// max(f(x), g(x))

int main() {
    int n;

    vector<int> A(n);
    int l = 0, r = n-1;
    while(l <= r) {
        int dif = r-l;
        int m1 = l + dif/3, m2 = r - dif/3;

        int v1 = A[m1], v2 = A[m2];

        if(v1 < v2) { l = m1; }
        else if(v1 > v2) { r = m2; }
    //  else(v1 == v2) { l = m1; r = m2; }
    }

    // ou 

    long double low = 0, high = 1e9;
    for(int i=0;i<100;i++) {
        long double dif = r-l;
        long double m1 = l + dif/3, m2 = r - dif/3;

        long double v1 = X2(m1), v2 = X2(m2);

        if(v1 < v2) { l = m1; }
        else if(v1 > v2) { r = m2; }
    //  else(v1 == v2) { l = m1; r = m2; }
    }
}