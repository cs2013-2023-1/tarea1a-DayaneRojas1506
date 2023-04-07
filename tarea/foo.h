#include <iostream>
#include <iostream>
#include <random>

using namespace std;

class Matriz2D{
    friend Matriz2D t(Matriz2D& m);
    friend ostream& operator<<(ostream&, const Matriz2D& m);
    friend Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2);
    friend Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2);
    friend Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2);
    friend Matriz2D operator+(const Matriz2D& m, float n);
    friend Matriz2D operator-(const Matriz2D& m, float n);
    friend Matriz2D operator*(const Matriz2D& m, float n);
    friend Matriz2D operator/(const Matriz2D& m, float n);
public:
    Matriz2D();
    Matriz2D(int n);
    Matriz2D(int n, int m);
    Matriz2D(const Matriz2D& m);
    Matriz2D(Matriz2D&& m);
    ~Matriz2D();
    float get(int i, int j);
    int getFilas();
    int getColumnas();

private:
    float** ptr;
    int filas;
    int columnas;


};





