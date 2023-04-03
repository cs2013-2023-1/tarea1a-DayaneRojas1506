#include "foo.h"

Matriz2D::Matriz2D(){
    // Constructor por defecto
}

Matriz2D::Matriz2D(int n){
    // Constructor con un parametro
}

Matriz2D::Matriz2D(int n, int m){
    // Constructor con dos parametros
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
}

Matriz2D::Matriz2D(Matriz2D&& m){
    // Constructor de movimiento
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}