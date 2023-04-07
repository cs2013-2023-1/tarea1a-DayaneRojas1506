#include "foo.h"

// Matriz2D::Matriz2D(){
//     // Constructor por defecto
// }

// Matriz2D::Matriz2D(int n){
//     // Constructor con un parametro
// }

// Matriz2D::Matriz2D(int n, int m){
//     // Constructor con dos parametros
// }

// Matriz2D::Matriz2D(const Matriz2D& m){
//     // Constructor de copia
// }

// Matriz2D::Matriz2D(Matriz2D&& m){
//     // Constructor de movimiento
// }

// Matriz2D t(Matriz2D& m){
//     // Transpuesta de una matriz
// }

// std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
//     // Sobrecarga del operador <<
// }

// Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
//     // Sobrecarga del operador +
// }

// Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
//     // Sobrecarga del operador -
// }

// Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
//     // Sobrecarga del operador *
// }

// Matriz2D operator+(const Matriz2D& m, float n){
//     // Sobrecarga del operador +
// }

// Matriz2D operator-(const Matriz2D& m, float n){
//     // Sobrecarga del operador -
// }

// Matriz2D operator*(const Matriz2D& m, float n){
//     // Sobrecarga del operador *
// }

// Matriz2D operator/(const Matriz2D& m, float n){
//     // Sobrecarga del operador /
// }

// float Matriz2D::get(int i, int j){
//     return ptr[i][j];
// }

// int Matriz2D::getFilas(){
//     return filas;
// }

// int Matriz2D::getColumnas(){
//     return columnas;
// }

#include <random>

using namespace std;

 //  Constructor por defecto
Matriz2D::Matriz2D(): filas(0), columnas(0), ptr(nullptr){}


Matriz2D::Matriz2D(int n):filas(n), columnas(n){
    // Constructor con un parametro
    if (n > 0) {
        ptr = new float*[filas];
        for (int i = 0; i < filas; i++) {
            ptr[i] = new float[columnas];
            for (int j = 0; j < columnas; j++) {
                ptr[i][j] = (float)rand() / RAND_MAX;
            }
        }
    }
    else {
        filas = columnas = 0;
        ptr = nullptr;
    }
}


// Constructor con dos parametros
Matriz2D::Matriz2D(int n, int m): filas(n), columnas(m){
    if (n > 0 && m > 0) {
        ptr = new float*[filas];
        for (int i = 0; i < filas; i++) {
            ptr[i] = new float[columnas];
            for (int j = 0; j < columnas; j++) {
                ptr[i][j] = (float)rand() / RAND_MAX;
            }
        }
    }
    else {
        filas = columnas = 0;
        ptr = nullptr;
    }
}

// Constructor de copia
Matriz2D::Matriz2D(const Matriz2D& m):filas(m.filas), columnas(m.columnas), ptr(nullptr) {
    ptr = new float*[filas];
    for (int i = 0; i < filas; i++) {
        ptr[i] = new float[columnas];
        for (int j = 0; j < columnas; j++) {
            ptr[i][j] = m.ptr[i][j];
        }
    }
}

// Constructor de movimiento
Matriz2D::Matriz2D(Matriz2D&& m) : filas(m.filas), columnas(m.columnas), ptr(m.ptr) {
    m.filas = m.columnas = 0;
    m.ptr = nullptr;
}


// Destructor
Matriz2D::~Matriz2D() {
    for (int i = 0; i < filas; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;
    ptr = nullptr;
    filas = columnas = 0;
}


// Transpuesta de una matriz
Matriz2D t(Matriz2D& m) {
    Matriz2D transpuesta(m.columnas, m.filas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            transpuesta.ptr[j][i] = m.ptr[i][j];
        }
    }
    return transpuesta;
}
std::ostream& operator<<(std::ostream& os, const Matriz2D& item){
    // Sobrecarga del operador <<
    for(int i = 0; i < item.filas; i++){
        for(int j = 0; j < item.columnas; j++){
            os << item.ptr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}



Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    if (m1.filas != m2.filas || m1.columnas != m2.columnas) {
        throw std::invalid_argument("No se pueden sumar matrices de distintas dimensiones");
    }
    Matriz2D res(m1.filas, m1.columnas);
    for (int i = 0; i < m1.filas; i++) {
        for (int j = 0; j < m1.columnas; j++) {
            res.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
        }
    }
    return res;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    if (m1.filas != m2.filas || m1.columnas != m2.columnas) {
        throw std::invalid_argument("No se pueden restar matrices de distintas dimensiones");
    }
    Matriz2D res(m1.filas, m1.columnas);
    for (int i = 0; i < m1.filas; i++) {
        for (int j = 0; j < m1.columnas; j++) {
            res.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
        }
    }
    return res;
}

//sobrecarga del operaor *
Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    if (m1.columnas != m2.filas) {
        throw std::invalid_argument("No se pueden multiplicar matrices de dimensiones invalidas");
    }
    Matriz2D res(m1.filas, m2.columnas);
    for (int i = 0; i < m1.filas; i++) {
        for (int j = 0; j < m2.columnas; j++) {
            for (int k = 0; k < m1.columnas; k++) {
                res.ptr[i][j] += m1.ptr[i][k] * m2.ptr[k][j];
            }
        }
    }
    return res;
}

Matriz2D operator+(const Matriz2D& m, float n){
    Matriz2D res(m.filas, m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            res.ptr[i][j] = m.ptr[i][j] + n;
        }
    }
    return res;
}

Matriz2D operator-(const Matriz2D& m, float n){
    Matriz2D res(m.filas, m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            res.ptr[i][j] = m.ptr[i][j] - n;
        }
    }
    return res;
}

Matriz2D operator*(const Matriz2D& m, float n){
    Matriz2D res(m.filas, m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            res.ptr[i][j] = m.ptr[i][j] * n;
        }
    }
    return res;
}

Matriz2D operator/(const Matriz2D& m, float n){
    Matriz2D res(m.filas, m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            res.ptr[i][j] = m.ptr[i][j] / n;
        }
    }
    return res;
}

