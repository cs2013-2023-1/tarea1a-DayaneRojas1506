#include <iostream>
#include <cstdlib>
#include <ctime>

class Matriz2D {
    friend std::ostream& operator<<(std::ostream&, const Matriz2D&);
private:
    int nfilas, ncolumnas;
    float **datos;
public:
    // Constructores
    Matriz2D(): nfilas(0), ncolumnas(0), datos(nullptr) {}
    Matriz2D(int nf, int nc): nfilas(nf), ncolumnas(nc) {
        datos = new float*[nfilas];
        for (int i = 0; i < nfilas; ++i) {
            datos[i] = new float[ncolumnas];
            for (int j = 0; j < ncolumnas; ++j) {
                datos[i][j] = (float)rand() / RAND_MAX; // Genera número aleatorio entre 0 y 1
            }
        }
    }
    Matriz2D(const Matriz2D& otra): nfilas(otra.nfilas), ncolumnas(otra.ncolumnas) {
        datos = new float*[nfilas];
        for (int i = 0; i < nfilas; ++i) {
            datos[i] = new float[ncolumnas];
            for (int j = 0; j < ncolumnas; ++j) {
                datos[i][j] = otra.datos[i][j];
            }
        }
    }
    Matriz2D(Matriz2D&& otra) noexcept : nfilas(otra.nfilas), ncolumnas(otra.ncolumnas), datos(otra.datos) {
        otra.nfilas = 0;
        otra.ncolumnas = 0;
        otra.datos = nullptr;
    }
    // Destructor
    ~Matriz2D() {
        for (int i = 0; i < nfilas; ++i) {
            delete[] datos[i];
        }
        delete[] datos;
    }
    // Operadores de asignación
    Matriz2D& operator=(const Matriz2D& otra) {
        if (this == &otra) {
            return *this;
        }
        for (int i = 0; i < nfilas; ++i) {
            delete[] datos[i];
        }
        delete[] datos;
        nfilas = otra.nfilas;
        ncolumnas = otra.ncolumnas;
        datos = new float*[nfilas];
        for (int i = 0; i < nfilas; ++i) {
            datos[i] = new float[ncolumnas];
            for (int j = 0; j < ncolumnas; ++j) {
                datos[i][j] = otra.datos[i][j];
            }
        }
        return *this;
    }
    Matriz2D& operator=(Matriz2D&& otra) noexcept {
        if (this == &otra) {
            return *this;
        }
        for (int i = 0; i < nfilas; ++i) {
            delete[] datos[i];
        }
        delete[] datos;
        nfilas = otra.nfilas;
        ncolumnas = otra.ncolumnas;
        datos = otra.datos;
        otra.nfilas = 0;
        otra.ncolumnas = 0;
        otra.datos = nullptr;
        return *this;
    }
    // Operadores aritméticos
    Matriz2D operator+(const Matriz2D& otra) const {
        if (nfilas != otra.nfilas || ncolumnas != otra.ncolumnas) {
            throw std::invalid_argument("Las matrices deben tener las mismas dimensiones");
        }
        Matriz2D resultado(nfilas, ncolumnas);
        for (int i = 0; i < nfilas; ++i) {
            for (int j = 0; j < ncolumnas; ++j) {
                resultado.datos[i][j] = datos[i][j] + otra.datos[i][j];
            }
        }
        return resultado;
    }
    Matriz2D operator-(const Matriz2D& otra) const {
        if (nfilas != otra.nfilas || ncolumnas != otra.ncolumnas) {
            throw std::invalid_argument("Las matrices deben tener las mismas dimensiones");
        }
        Matriz2D resultado(nfilas, ncolumnas);
        for (int i = 0; i < nfilas; ++i) {
            for (int j = 0; j < ncolumnas; ++j) {
                resultado.datos[i][j] = datos[i][j] - otra.datos[i][j];
            }
        }
        return resultado;
    }
    Matriz2D operator*(const Matriz2D& otra) const {
        if (ncolumnas != otra.nfilas) {
            throw std::invalid_argument("El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz");
        }
        Matriz2D resultado(nfilas, otra.ncolumnas);
        for (int i = 0; i < nfilas; ++i) {
            for (int j = 0; j < otra.ncolumnas; ++j) {
                resultado.datos[i][j] = 0;
                for (int k = 0; k < ncolumnas; ++k) {
                    resultado.datos[i][j] += datos[i][k] * otra.datos[k][j];
                }
            }
        }
        return resultado;
    }
    Matriz2D operator/(float divisor) const {
        if (divisor == 0) {
            throw std::invalid_argument("No se puede dividir por cero");
        }
        Matriz2D resultado(nfilas, ncolumnas);
        for (int i = 0; i < nfilas; ++i) {
            for (int j = 0; j < ncolumnas; ++j) {
                resultado.datos[i][j] = datos[i][j] / divisor;
            }
        }
        return resultado;
    }
    // Funciones de utilidad
    void imprimir() const {
        for (int i = 0; i < nfilas; ++i) {
            for (int j = 0; j < ncolumnas; ++j) {
                std::cout << datos[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Función para imprimir matrices con std::cout
std::ostream& operator<<(std::ostream& os, const Matriz2D& matriz) {
    for(int i = 0; i < matriz.nfilas; i++){
            for(int j = 0; j < matriz.ncolumnas; j++){
                os << matriz.datos[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

