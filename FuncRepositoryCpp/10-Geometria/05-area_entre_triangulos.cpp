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

double cross(const Point& p, const Point& q) { return p.x*q.y - p.y*q.x; }
double sig_area(Point a, Point b, Point c) { return cross(b-a, c-b); }
double pol_area(vector<Point> V) {
    int n = V.size();
	double soma = 0;
	for(int i = 0; i < n; i++) {
		soma += sig_area(Point(0,0), V[i], V[(i+1) % n]);
    }
	return abs(soma) / 2.0;
}
double orient(Point a, Point b, Point c) { return cross(b-a, c-a); }

struct Triangle {
    Point a, b, c;
};


// Ponto de interseção entre a reta suporte AB e o segmento PQ
Point lineIntersection(Point a, Point b, Point p, Point q) {
    Point ab = b - a;
    Point pq = q - p;
    double t = cross(p - a, pq) / cross(ab, pq);
    return a + ab * t;
}

// Corta um polígono convexo mantendo os pontos à esquerda da reta A -> B
vector<Point> clipPolygon(const vector<Point>& poly, Point a, Point b) {
    vector<Point> result;
    int n = poly.size();
    if (n == 0) return result;

    for (int i = 0; i < n; i++) {
        Point p1 = poly[i];
        Point p2 = poly[(i + 1) % n];

        double d1 = orient(a, b, p1);
        double d2 = orient(a, b, p2);

        if (d1 >= -EPS) { // p1 está dentro (ou na borda)
            result.push_back(p1);
            if (d2 < -EPS) { // p2 está fora (saiu)
                result.push_back(lineIntersection(a, b, p1, p2));
            }
        } else if (d2 >= -EPS) { // p1 estava fora, p2 entrou
            result.push_back(lineIntersection(a, b, p1, p2));
        }
    }
    return result;
}

double triangleIntersectionArea(Triangle t1, Triangle t2) {
    // 1. Garante que t2 esteja em ordem anti-horária (CCW)
    if (orient(t2.a, t2.b, t2.c) < 0) {
        swap(t2.b, t2.c);
    }

    // 2. Inicia com os vértices do triângulo 1
    vector<Point> subject = {t1.a, t1.b, t1.c};

    // 3. Corta o triângulo 1 sucessivamente pelas 3 arestas de t2
    subject = clipPolygon(subject, t2.a, t2.b);
    subject = clipPolygon(subject, t2.b, t2.c);
    subject = clipPolygon(subject, t2.c, t2.a);

    // 4. Retorna a área do polígono resultante
    return pol_area(subject);
}