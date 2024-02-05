#include <stdio.h>
#include <math.h>

int main () {

printf("ingrese su peso en kilogramos: ");
float peso;
scanf("%f", &peso);

printf ("ingrese su altura en metros: ");
float altura;
scanf("%f", &altura);

float imc = peso / (altura * altura);

printf("su imc es: %.2f\n", imc);


if (imc < 18.5) {
    printf("Usted está demasiado delgado, considere una alimentación adecuada.");
}else if (imc >= 18.5 && imc <= 24.9) {

        printf("Su peso está en el rango de la normalidad.");

}else if (imc >= 25.0 && imc <= 29.9) {

        printf("Usted tiene sobrepeso.");
    }
    else
    {
        printf("usted tiene obesidad mórbida, debe empezar una dieta urgente.");
    }


    return 0;
}