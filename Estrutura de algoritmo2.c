#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct Person {
    int id;
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    char date_of_birth[MAX_NAME_LENGTH];
};

int main() {
    printf("Bem-vindo ao programa de lista de pessoas!\n");
    printf("\nSOFTWARE PRODUZIDO POR: Miriua Orlando Alberto!\n");

    int num_people;
    printf("\nAdicionar pessoas\n ");


    // Criando um vetor de ponteiros para struct Person
    struct Person **people = (struct Person **) malloc(num_people * sizeof(struct Person *));

    // Lendo os dados de cada pessoa e armazenando na lista
    for (int i = 0; i < num_people; i++) {
        struct Person *person = (struct Person *) malloc(sizeof(struct Person));

        printf("Digite o ID da pessoa %d: ", i+1);
        scanf("%d", &(person->id));

        printf("Digite o primeiro nome da pessoa %d: ", i+1);
        scanf("%s", person->first_name);

        printf("Digite o sobrenome da pessoa %d: ", i+1);
        scanf("%s", person->last_name);

        printf("Digite a data de nascimento da pessoa %d (dd/mm/aaaa): ", i+1);
        scanf("%s", person->date_of_birth);

        people[i] = person;
    }

    // Imprimindo a lista de pessoas
    printf("\nLista de pessoas:\n");
    for (int i = 0; i < num_people; i++) {
        struct Person *person = people[i];
        printf("%d - %s %s, nascido em %s\n", person->id, person->first_name, person->last_name, person->date_of_birth);
    }

    // Liberando a memória alocada para cada pessoa e para o vetor de ponteiros
    for (int i = 0; i < num_people; i++) {
        free(people[i]);
    }
    free(people);

    return 0;
}
