#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, x1, x2;

    printf("Ingresa el valor de a: ");
    scanf("%lf", &a);

    printf("Ingresa el valor de b: ");
    scanf("%lf", &b);

    printf("Ingresa el valor de c: ");
    scanf("%lf", &c);

    // Evaluar si los valores son válidos
    if (a == 0) {
        printf("El valor de a no puede ser 0\n");
    } else {
        // Calcular el discriminante
        double discriminante = pow(b, 2) - 4 * a * c;

        // Verificar si el discriminante es negativo
        if (discriminante < 0) {
            printf("El discriminante es negativo, no hay raíces reales.\n");
        } else {
            // Calcular las raíces
            x1 = (-b + sqrt(discriminante)) / (2 * a);
            x2 = (-b - sqrt(discriminante)) / (2 * a);

            printf("Las raíces son: x1 = %.2lf y x2 = %.2lf\n", x1, x2);
        }
    }

    return 0;
}
