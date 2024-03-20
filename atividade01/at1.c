#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1;
    }

    int x = argc - 1;
    int *num = (int *)malloc(x * sizeof(int));

    for (int i = 1; i < argc; i++) {
        num[i - 1] = atoi(argv[i]);
    }

    int soma = 0, menor = num[0], maior = num[0];

    for (int i = 0; i < x; i++) {
        soma += num[i];

        if (num[i] > maior) {
            maior = num[i];
        }

        if (num[i] < menor) {
            menor = num[i];
        }
    }

    for (int i = 0; i < x - 1; i++) {
        for (int j = 0; j < x - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }

    printf("A quantidade de numeros digitados foi: %d\n", x);
    printf("Numero maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("Media: %.2f\n", (float)soma / x);
    printf("Numeros em ordem crescente: ");
    for (int i = 0; i < x; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}
