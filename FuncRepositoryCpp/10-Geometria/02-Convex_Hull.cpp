#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()

// Dado um conjunto de pontos, ache o menor
// polígono convexo que abrange todos os pontos

const double EPS = 1e-9;
int cmp(double a, double b) {
    if(abs(a-b) < EPS) { return 0; }  // São "iguais", se dif < EPS
    return (a < b) ? -1 : 1;          // Retorna -1 se a < b, e 1 se a > b
}

struct Point {
    double x,y;
    Point(double x = 0, double y = 0) : x(x),y(y){}
    Point(const Point& p) : x(p.x), y(p.y){}

    bool operator < (const Point &p) const {
        if(cmp(x, p.x) == -1) return true;
        else if(cmp(x, p.x) == 1) return false;
        else { return cmp(y, p.y) < 0; }
    }
    bool operator == (const Point &p) const {return !cmp(x, p.x) && !cmp(y, p.y);}
    bool operator != (const Point &p) const {return !(p == *this);}

    // basic ops
    Point operator + (const Point& p) const {return Point(x + p.x, y + p.y);}
    Point operator - (const Point& p) const {return Point(x - p.x, y - p.y);}
    Point operator * (const double k) const {return Point(x*k, y*k);}
    Point operator / (const double k) const {return Point(x/k, y/k);}
};

double cross(const Point& p, const Point& q) { return p.x*q.y - p.y*q.x; }


// PELO MENOS 3 PONTOS DISTINTOS, SE PONTOS FOREM TODOS COLINEARES O CONVEX_HULL TERA AREA = 0
vector<Point> convexHull(vector<Point>& pts, bool sorted = false) {
    int n = pts.size();
    if(!sorted) { sort(all(pts)); }

    vector<Point> lower(n+1), upper(n+1);
    int s = 0;
    for(int i=0;i<n;i++){
        lower[s++] = pts[i];
        while(s >= 3) {
            Point a = lower[s-3], b = lower[s-2], c = lower[s-1];
            Point v1 = b-a, v2 = c-b;
            // coloca >= se quiser os colineares
            if(cross(v1,v2) > 0) { break; }
            lower[s-2] = lower[s-1];
            s--;
        }
    }
    lower.resize(s);
    s = 0;
    for(int i=0;i<n;i++) {
        upper[s++] = pts[i];
        while(s >= 3) {
            Point a = upper[s-3], b = upper[s-2], c = upper[s-1];
            Point v1 = b-a, v2 = c-b;
            // coloca <= se quiser os colineares
            if(cross(v1,v2) < 0) { break; }
            upper[s-2] = upper[s-1];
            s--;
        }
    }
    upper.resize(s-1);
    reverse(all(upper));
    upper.pop_back();
    lower.insert(end(lower), begin(upper), end(upper));
    return lower;
}

bool isInside(const vector<Point> &hull, Point pt) {
    int n = hull.size();
    Point v0 = pt - hull[0], v1 = hull[1] - hull[0], v2 = hull[n-1] - hull[0];
    if(cross(v0,v1) > 0 || cross(v0,v2) < 0) { return false; }

    int l = 1, r = n-1;
    while(l != r) {
        int mid = (l + r + 1) / 2;
        v0 = pt - hull[0]; v1 = hull[mid] - hull[0];

        if(cross(v0,v1) < 0) { l = mid; }
        else { r = mid-1; }
    }
    v0 = hull[(l+1)%n] - hull[l], v1 = pt - hull[l];
    // >= 0 considera a Borda, > 0 considera apenas Dentro
    return cross(v0,v1) >= 0;
}


int main() {
    int n;
    vector<Point> pts(n);
    vector<Point> Hull = convexHull(pts);

    if(isInside(Hull, pts[0])) { cout << "Ponto esta dentro!\n"; }
    else { cout << "Ponto esta fora!\n"; }
}