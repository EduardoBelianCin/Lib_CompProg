// Sparse Table 2D - RMQ (static) 
//
// build - O(n * m * log(n) * log(m))
// query - O(1)

struct Sparse2D {
    int n, m;
    vector<int> lg;
    vector<vector<vector<vector<int>>>> tab;

    int join(int a, int b) {
        return min(a, b);
    }

    Sparse2D(const vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return;
        n = M.size();
        m = M[0].size();

        // Pré-computa os logaritmos até o maior lado
        int max_len = max(n, m);
        lg.assign(max_len + 1, 0);
        for(int i = 2; i <= max_len; i++) lg[i] = lg[i/2] + 1;

        int KR = lg[n] + 1;
        int KC = lg[m] + 1;

        // tab[kr][kc][r][c]
        tab.assign(KR, vector<vector<vector<int>>>(
            KC, vector<vector<int>>(n, vector<int>(m))
        ));

        // Caso base (kr = 0, kc = 0)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tab[0][0][i][j] = M[i][j];
            }
        }

        // Construção DP
        for (int kr = 0; kr < KR; kr++) {
            for (int kc = 0; kc < KC; kc++) {
                if (kr == 0 && kc == 0) continue;
                
                for (int i = 0; i + (1 << kr) - 1 < n; i++) {
                    for (int j = 0; j + (1 << kc) - 1 < m; j++) {
                        if (kr == 0) {
                            // Junta na horizontal
                            tab[kr][kc][i][j] = join(
                                tab[kr][kc-1][i][j], 
                                tab[kr][kc-1][i][j + (1 << (kc-1))]
                            );
                        } else {
                            // Junta na vertical (podendo juntar matrizes já computadas na horizontal)
                            tab[kr][kc][i][j] = join(
                                tab[kr-1][kc][i][j], 
                                tab[kr-1][kc][i + (1 << (kr-1))][j]
                            );
                        }
                    }
                }
            }
        }
    }

    int query(int r1, int c1, int r2, int c2) {
        int kr = lg[r2 - r1 + 1];
        int kc = lg[c2 - c1 + 1];
        
        // Sobrepõe os 4 retângulos que cobrem a query completa
        int top_left     = tab[kr][kc][r1][c1];
        int top_right    = tab[kr][kc][r1][c2 - (1 << kc) + 1];
        int bottom_left  = tab[kr][kc][r2 - (1 << kr) + 1][c1];
        int bottom_right = tab[kr][kc][r2 - (1 << kr) + 1][c2 - (1 << kc) + 1];

        return join(join(top_left, top_right), join(bottom_left, bottom_right));
    }
};

/* USO:

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    Sparse2D sp(mat);
    
    // Consultando o retângulo do canto superior esquerdo (r1, c1) 
    // até o inferior direito (r2, c2)
    cout << sp.query(r1, c1, r2, c2) << "\n"; // Se for 1-indexado, faça r1-1, c1-1, etc.

*/