# :wave: PROGRAMACION III: TAREA 1A

- Apellidos: *Completar*
- Nombres: *Completar*
- Sección: *Completar*

En la presente tarea usted debe **modificar/completar** los archivos dentro de la carpeta <tt>tarea</tt>.

## Requerimientos
* Implementar la Clase <tt>Matriz2D</tt> para generar matrices de dos dimensiones y realizar operaciones
  aritméticas entre ellas.
* Los elementos de la matriz deben ser números aleatorios entre 0 y 1 (<tt>float</tt>). 
* Constructores por defecto, de copia, y movimiento:
```
Matriz2D m1;            // Matriz cuadrada de 3x3
Matriz2D m2(5);         // Matriz cuadrada de 5x5
Matriz2D m3(5,2);       // Matriz cuadrada de 5x2
```

```
Matriz2D m4 = m2;      
Matriz2D m5 = move(m2); 
```

* Funciones *auxiliares*:
```
Matriz2D m6 = t(m3);    // 'm6' es la transpuesta de m3
```
* Sobrecarga de operadores:
    * Operaciones entre matrices:
    ```
    Matriz2D m7 = m3 + m4;    // Suma de matrices
    Matriz2D m8 = m3 - m4;    // Resta de matrices
    Matriz2D m9 = m3 * m4;    // Multiplicación de matrices
    ```
    * Operaciones entre una matriz y un escalar:
    ```
    Matriz2D m7 = m3 + 3;    
    Matriz2D m8 = m3 - 1.2;    
    Matriz2D m9 = m3 * 5;    
    Matriz2D m10 = m3 / 7;    
    ```
    * Sobrecarga al operador <tt><<</tt>:
    ```
    cout << m3;    
    ```
    Resultado:
    ```
    0.12 0.11 0.22
    0.55 0.24 0.98
    0.01 0.05 0.77    
    ```

## Importante
No modificar, por ningún motivo, los archivos en la carpeta <tt>test</tt>.