// Sparse Table - RMQ (static) 
//
// build - O(n log n)
// query - O(1)

// Funciona: min, max, gcd, bitwise AND, bitwise OR.
// Essa técnica de consulta em O(1) só funciona para operações
// onde elementos repetidos não alteram o resultado final join(x,x) = x

struct Sparse {
    int n;
    vector<int> lg;
    vector<vector<int>> tab;

    int join(int a, int b) {
        return min(a,b);
    }

    Sparse(const vector<int>& V){
        n = V.size();

        lg.assign(n+1, 0);
        for(int i=2;i<=n;i++) lg[i] = lg[i/2] + 1;

        int K = lg[n]+1;
        tab.assign(K, vector<int>(n));

        tab[0]=V;

        for(int j=1;j<K;j++) {
            for(int i=0;i+(1<<j)-1<n;i++) {
                tab[j][i] = join( tab[j-1][i], tab[j-1][i+(1<<(j-1))] );
            }
        }
    }

    int query(int l, int r) {
        int j = lg[r-l+1];
        return join( tab[j][l], tab[j][r-(1<<j)+1] );
    }
};

/* USO:

    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    Sparse sp(v);
    cout<<sp.query(l,r)<<"\n";   // se o problema der l,r 1-indexado: query(l-1,r-1)

*/