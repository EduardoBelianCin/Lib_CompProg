#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x,y;
    Point(double x = 0, double y = 0) : x(x),y(y){}
    Point(const Point& p) : x(p.x), y(p.y){}
};

// O(n) - n vertices do poligono

// Retorna: 1 (Dentro), 0 (Fora), -1 (Na Borda)
int pointInPolygon(Point &p, vector<Point> &poly) {
    int n = poly.size();
    bool inside = false;

    for (int i = 0; i < n; i++) {
        Point a = poly[i];
        Point b = poly[(i + 1) % n];

        // 1. Checa se o ponto está exatamente sobre a aresta AB
        double cross = (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
        if (abs(cross) < 1e-9) {
            if (min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
                min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y)) {
                return -1; // Na borda
            }
        }

        // 2. Ray casting horizontal para a direita
        bool condA = a.y <= p.y;
        bool condB = b.y <= p.y;

        // Aresta cruza a linha horizontal de p.y
        if (condA != condB) {
            // Calcula a coordenada X da interseção
            double x_int = a.x + (p.y - a.y) * (b.x - a.x) / (b.y - a.y);
            if (x_int > p.x) {
                inside = !inside;
            }
        }
    }

    return inside ? 1 : 0;
}