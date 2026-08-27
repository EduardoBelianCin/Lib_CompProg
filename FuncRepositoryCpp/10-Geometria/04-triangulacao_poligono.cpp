#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x),y(y){}
    Point(const Point& p) : x(p.x), y(p.y){}

    Point operator + (const Point& p) const {return Point(x + p.x, y + p.y);}
    Point operator - (const Point& p) const {return Point(x - p.x, y - p.y);}
    Point operator * (const double k) const {return Point(x*k, y*k);}
    Point operator / (const double k) const {return Point(x/k, y/k);}
};

struct Triangle {
    Point a, b, c;
};

double cross(const Point& p, const Point& q) { return p.x*q.y - p.y*q.x; }
double orient(Point a, Point b, Point c) { return cross(b-a, c-a); }

// Checa se o ponto P está estritamente dentro ou na borda do triângulo ABC (em CCW)
bool pointInTriangle(Point p, Point a, Point b, Point c) {
    double o1 = orient(a, b, p);
    double o2 = orient(b, c, p);
    double o3 = orient(c, a, p);
    return (o1 >= -EPS && o2 >= -EPS && o3 >= -EPS);
}

// Algoritmo de Ear Clipping - O(N^2)
// Recebe os vértices de um polígono simples e retorna a lista de triângulos
// PEGA UM POLIGONO QUE PODE SER NAO-CONVEXO E RETORNA TRIANGULOS QUE FORMAM ELE
vector<Triangle> triangulate(vector<Point> poly) {
    vector<Triangle> triangles;
    int n = poly.size();
    if (n < 3) return triangles;

    // 1. Garante ordem anti-horária (CCW)
    double signed_area = 0;
    for (int i = 0; i < n; i++) {
        signed_area += cross(poly[i], poly[(i + 1) % n]);
    }
    if (signed_area < 0) {
        reverse(poly.begin(), poly.end());
    }

    // 2. Cria lista duplamente ligada circular via índices
    vector<int> prev(n), next(n);
    for (int i = 0; i < n; i++) {
        prev[i] = (i - 1 + n) % n;
        next[i] = (i + 1) % n;
    }

    int curr = 0;
    int remaining = n;
    int safety_counter = 0;

    // 3. Corta as orelhas (ears) sucessivamente
    while (remaining > 2 && safety_counter < 2 * remaining) {
        int p = prev[curr];
        int nxt = next[curr];

        Point a = poly[p];
        Point b = poly[curr];
        Point c = poly[nxt];

        // Vértice 'b' precisa ser convexo para formar uma orelha
        if (orient(a, b, c) > EPS) {
            bool is_ear = true;

            // Checa se nenhum outro vértice restante está dentro de ABC
            for (int i = next[nxt]; i != p; i = next[i]) {
                if (pointInTriangle(poly[i], a, b, c)) {
                    is_ear = false;
                    break;
                }
            }

            // Se for uma orelha válida, remove o vértice 'curr'
            if (is_ear) {
                triangles.push_back({a, b, c});
                next[p] = nxt;
                prev[nxt] = p;
                remaining--;
                safety_counter = 0;
                curr = nxt;
                continue;
            }
        }

        curr = next[curr];
        safety_counter++;
    }

    return triangles;
}