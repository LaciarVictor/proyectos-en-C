#include <stdio.h>
#include <math.h>

// Función para calcular el tiempo de encuentro entre dos móviles
double calcularTiempoEncuentro(double v1, double v2, double a1, double a2, double s1, double s2) {
    double t;

    // Caso de MRU
    if (a1 == 0 && a2 == 0) {
        t = (s2 - s1) / (v1 - v2);
    }
    // Caso de MRUV
    else {
        double a = 0.5 * (a1 - a2);
        double b = v1 - v2;
        double c = s1 - s2;

        double discriminante = b * b - 4 * a * c;

        // Comprobamos si hay solución real
        if (discriminante < 0) {
            printf("No hay solucion real para el tiempo de encuentro.\n");
            return -1;
        }

        // Fórmula cuadrática para encontrar el tiempo de encuentro
        t = (-b + sqrt(discriminante)) / (2 * a);
    }

    return t;
}

int main() {
    // Variables para almacenar los datos de los móviles
    double v1, v2, a1, a2, s1, s2;

    // Solicitar datos al usuario
    printf("Ingrese la velocidad inicial del móvil 1 (v1): ");
    scanf("%lf", &v1);

    printf("Ingrese la velocidad inicial del móvil 2 (v2): ");
    scanf("%lf", &v2);

    printf("Ingrese la aceleración del móvil 1 (a1): ");
    scanf("%lf", &a1);

    printf("Ingrese la aceleración del móvil 2 (a2): ");
    scanf("%lf", &a2);

    printf("Ingrese la posición inicial del móvil 1 (s1): ");
    scanf("%lf", &s1);

    printf("Ingrese la posición inicial del móvil 2 (s2): ");
    scanf("%lf", &s2);

    // Calcular el tiempo de encuentro
    double tiempoEncuentro = calcularTiempoEncuentro(v1, v2, a1, a2, s1, s2);

    // Mostrar el resultado
    if (tiempoEncuentro >= 0) {
        // Calcular la distancia recorrida y la velocidad final para cada móvil
        double distanciaRecorrida1 = v1 * tiempoEncuentro + 0.5 * a1 * tiempoEncuentro * tiempoEncuentro;
        double velocidadFinal1 = v1 + a1 * tiempoEncuentro;

        double distanciaRecorrida2 = v2 * tiempoEncuentro + 0.5 * a2 * tiempoEncuentro * tiempoEncuentro;
        double velocidadFinal2 = v2 + a2 * tiempoEncuentro;

        printf("Los móviles se encontrarán en t = %.4lf segundos.\n", tiempoEncuentro);
        printf("Móvil 1 recorrerá %.4lf metros con velocidad final %.4lf m/s.\n", distanciaRecorrida1, velocidadFinal1);
        printf("Móvil 2 recorrerá %.4lf metros con velocidad final %.4lf m/s.\n", distanciaRecorrida2, velocidadFinal2);
    }

    return 0;
}
