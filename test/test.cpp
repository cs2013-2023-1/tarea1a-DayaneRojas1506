// No modifique este archivo. Es el archivo de pruebas que se usara para corregir su tarea.
// Cualquier cambio que haga a este archivo sera penalizado con una nota de CERO.

#include "test.hpp"

TEST_CASE("parte1", "[constructores]"){
    SECTION("s1","Constructor por Defecto"){
        Matriz2D m1;
        REQUIRE(m1.getFilas() == 3);
        REQUIRE(m1.getColumnas() == 3);

        int i = random(0,2);
        int j = random(0,2);

        REQUIRE(m1.get(i,j) >= 0);
        REQUIRE(m1.get(i,j) <= 1);
    }

    SECTION("s2","Constructor con un Parametro"){
        Matriz2D m2(5);
        REQUIRE(m2.getFilas() == 5);
        REQUIRE(m2.getColumnas() == 5);
    }

    SECTION("s3","Constructor con dos Parametros"){
        Matriz2D m3(5,6);
        REQUIRE(m3.getFilas() == 5);
        REQUIRE(m3.getColumnas() == 6);
    }

    SECTION("s4","Constructor de Copia"){
        Matriz2D m4(5,6);
        Matriz2D m5 = m4;
        REQUIRE(m5.getFilas() == 5);
        REQUIRE(m5.getColumnas() == 6);
        
        int i = random(0,4);
        int j = random(0,5);

        REQUIRE(m4.get(i,j) == m5.get(i,j));
    }

    SECTION("s5","Constructor de Movimiento"){
        Matriz2D m6(5,6);
        int i = random(0,4);
        int j = random(0,5);
        float v = m6.get(i,j);

        Matriz2D m7 = std::move(m6);
        REQUIRE(m7.getFilas() == 5);
        REQUIRE(m7.getColumnas() == 6);
        REQUIRE(m7.get(i,j) == v);
    }
}

TEST_CASE("parte2", "[friends]"){
    SECTION("s1", "Transpuesta"){
        Matriz2D m1(5,6);
        Matriz2D m2 = t(m1);
        REQUIRE(m2.getFilas() == 6);
        REQUIRE(m2.getColumnas() == 5);

        int i = random(0,4);
        int j = random(0,5);

        REQUIRE(m1.get(i,j) == m2.get(j,i));
    }
    SECTION("s2", "Sobrecarga al operador <<"){
        Matriz2D m1(5,6);
        std::stringstream ss;
        ss << m1;
        std::string s = ss.str();
        REQUIRE(s.size() > 0);
    }
}

TEST_CASE("parte3", "[sobrecarga-con-matrices]"){
    SECTION("s1", "Sobrecarga al operador +"){
        Matriz2D m1(5,6);
        Matriz2D m2(5,6);
        Matriz2D m3 = m1 + m2;
        REQUIRE(m3.getFilas() == 5);
        REQUIRE(m3.getColumnas() == 6);

        int i = random(0,4);
        int j = random(0,5);

        REQUIRE(m3.get(i,j) == m1.get(i,j) + m2.get(i,j));
    }

    SECTION("s2", "Sobrecarga al operador -"){
        Matriz2D m1(5,6);
        Matriz2D m2(5,6);
        Matriz2D m3 = m1 - m2;
        REQUIRE(m3.getFilas() == 5);
        REQUIRE(m3.getColumnas() == 6);

        int i = random(0,4);
        int j = random(0,5);

        REQUIRE(m3.get(i,j) == m1.get(i,j) - m2.get(i,j));
    }

    SECTION("s3", "Sobrecarga al operador *"){
        Matriz2D m1(5,6);
        Matriz2D m2 = m1;
        Matriz2D m3 = m1 * t(m2);
        REQUIRE(m3.getFilas() == 5);
        REQUIRE(m3.getColumnas() == 7);

        int i = random(0,4);
        int j = random(0,6);

        float v = 0;
        for(int k = 0; k < 6; k++){
            v += m1.get(i,k) * m2.get(k,j);
        }

        REQUIRE(m3.get(i,j) == v);
    }
    
}

TEST_CASE("parte4", "[sobrecarga-con-escalares]"){
    SECTION("s1", "Sobrecarga al operador +"){
        Matriz2D m1(5,6);
        Matriz2D m2 = m1 + 5;
        REQUIRE(m2.getFilas() == 5);
        REQUIRE(m2.getColumnas() == 6);

        int i = random(0,4);
        int j = random(0,5);

        REQUIRE(m2.get(i,j) == m1.get(i,j) + 5);
    }

    SECTION("s2", "Sobrecarga al operador -"){
        Matriz2D m1(5,6);
        Matriz2D m2 = m1 - 5;
        REQUIRE(m2.getFilas() == 5);
        REQUIRE(m2.getColumnas() == 6);

        int i = random(0,4);
        int j = random(0,5);

        REQUIRE(m2.get(i,j) == m1.get(i,j) - 5);
    }

    SECTION("s3", "Sobrecarga al operador *"){
        Matriz2D m1(5,6);
        Matriz2D m2 = m1 * 5;
        REQUIRE(m2.getFilas() == 5);
        REQUIRE(m2.getColumnas() == 6);

        int i = random(0,4);
        int j = random(0,5);

        REQUIRE(m2.get(i,j) == m1.get(i,j) * 5);
    }

    SECTION("s4", "Sobrecarga al operador /"){
        Matriz2D m1(5,6);
        Matriz2D m2 = m1 / 5;
        REQUIRE(m2.getFilas() == 5);
        REQUIRE(m2.getColumnas() == 6);

        int i = random(0,4);
        int j = random(0,5);

        REQUIRE(m2.get(i,j) == m1.get(i,j) / 5);
    }
}