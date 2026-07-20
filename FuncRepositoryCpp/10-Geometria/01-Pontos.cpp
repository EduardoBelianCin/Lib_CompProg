#include <bits/stdc++.h>
using namespace std;
#define FORi(n) for(int i=0;i<n;i++)

// tratar os Points como ponto flutuante apenas se for necessario, senao faz com int ou ll

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

// Produto Escalar => Se > 0: ângulo agudo (<90°); Se == 0: perpendiculares; Se < 0: ângulo obtuso (>90°).
double dot(const Point& p, const Point& q) { return p.x*q.x + p.y*q.y; }

// Produto Vetorial (Cross Product): Retorna a área do paralelogramo formado pelos vetores.
// Se > 0: q está à esquerda de p; Se == 0: colineares; Se < 0: q está à direita de p (sentido horário).
double cross(const Point& p, const Point& q) { return p.x*q.y - p.y*q.x; }

// Norma (Magnitude/Comprimento): Retorna o tamanho do vetor a partir da origem (0,0).
double norm(const Point& p) { return sqrt(p.x*p.x + p.y*p.y); }

// Disntacia entre 2 pontos
double dist(const Point& p, const Point& q) { return norm(p-q); }

// Distância ao quadrado entre 2 pontos
double dist2(const Point& p, const Point& q) { return dot(p-q, p-q); }

// Normalizar vetor (Vetor Unitario): Mantém a direção do vetor, mas define seu comprimento como 1.
Point normalize(const Point &p) { return p / norm(p); }

// Angulo entre 2 vetores: Retorna o ângulo orientado (com sinal) de p até q, variando de -PI a PI.
double angle(const Point& p, const Point& q) { return atan2(cross(p, q), dot(p, q)); }

// Angulo com a origem: Retorna o ângulo absoluto do ponto em relação ao eixo X positivo (coordenada polar).
double angle(const Point& p) { return atan2(p.y, p.x); }

// Rotaciona um vetor no sentido horário por um ângulo 'ang' (em radianos)
Point rotate_horario(const Point &p, double ang) {
    Point q;
    q.x = p.x * cos(ang) + p.y * sin(ang);
    q.y = -p.x * sin(ang) + p.y * cos(ang);
    return q;
}
Point rotate_antihorario(const Point &p, double ang) { return rotate_horario(p, -ang); }

// Area com Sinal
double sig_area(Point p, Point q, Point r) {
    double x = cross(q-p, r-q);
	return x;
}
// Area do Polígono de Vertices em V
double pol_area(vector<Point> V) {
    int n = V.size();
	double soma = 0;
	FORi(n) {
		soma += sig_area(Point(0,0), V[i], V[(i+1) % n]);
    }
	return abs(soma);
}



int main() {
    ios::sync_with_stdio(false);cin.tie(0);

    Point p1(10.5, 20.0); // x = 10.5, y = 20.0
    Point p2(5);          // x = 5.0,  y = 0.0 (o y assume o default)
    Point p3;             // x = 0.0,  y = 0.0 (ambos default)
    Point p4 = {3.0, 4.0};
}

// DOT PRODUCT (PRODUTO ESCALAR)
// Mede alinhamento entre vetores:
// a · b > 0 -> mesmo sentido
// a · b = 0 -> perpendiculares
// a · b < 0 -> sentidos opostos

// CROSS PRODUCT (PRODUTO VETORIAL)
// Checar posição
// a × b > 0 -> anti-horário
// a × b < 0 -> horário
// Resulta no vetor perpendicular à ambos
// Módulo do vetor é igual à área do paralelogramo


// PERGUNTAS:
// Como saber se dois vetores são colineares? - R: cross(u,v) == 0 ou cmp(cross, 0) == 0
// Como calcular a área do triângulo formado entre dois vetores? - R: cross(u,v)/2 -> Metade do Módulo do vetor 
// Dados 3 pontos, como saber se eles são colineares? - R: Cria um vetor de A -> B e A -> C e vê se são colineares