#include <stdio.h>
#include <math.h>
#define MPI 3.14159265358979323846

double factorial(int n);

double gradosARadianes(double grados);

double calcularSeno(double x);


int main() {
    double angulo;

    // Escanea el ángulo en grados
    printf("Ingresa un ángulo en grados: ");
    scanf("%lf", &angulo);


    // Convierte el ángulo a radianes
    double anguloRadianes = gradosARadianes(angulo);

    //printf("El angulo en radianes es: %.6lf\n", anguloRadianes);

    // Calcula el seno y muestra el resultado
    double resultadoSeno = calcularSeno(anguloRadianes);
    printf("El seno de %.0lfº es aproximadamente: %.6lf\n", angulo, resultadoSeno);

    return 0;
}


// Función para calcular el factorial de un número
double factorial(int n) {
    if (n <= 1) {
        return 1.0;
    } else {
        return n * factorial(n - 1);
    }
}

// Función para convertir grados a radianes
double gradosARadianes(double grados) {
    return grados * MPI / 180.0;
}

// Función para calcular el seno utilizando la serie de Maclaurin
double calcularSeno(double x) {
    double resultado = 0.0;
    int k;
    
    for (k = 0; k < 10; k++) {  // Puedes ajustar el número de términos de la serie aquí
        double termino = pow(-1, k) * pow(x, 2 * k + 1) / factorial(2 * k + 1);
        resultado += termino;
    }

    return resultado;
}