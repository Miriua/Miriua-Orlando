#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

struct Person {
    int id;
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    char date_of_birth[MAX_NAME_LENGTH];
};

void print_person(struct Person *person) {
    printf("%d - %s %s, nascido em %s\n", person->id, person->first_name, person->last_name, person->date_of_birth);
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int max_people = 100;
    int num_people = 0;
    struct Person *people = (struct Person *) malloc(max_people * sizeof(struct Person));
    printf("Bem-vindo ao programa de lista de pessoas!\n");
    printf("\nSOFTWARE PRODUZIDO POR: Miriua Orlando Alberto!\n");


    int choice = 0;
    while (choice != 5) {
        printf("\nSelecione uma opção:\n");
        printf("1 - Adicionar  pessoa\n");
        printf("2 - Excluir  pessoa\n");
        printf("3 - Mostrar a lista de pessoas\n");
        printf("4 - Mostrar a segunda pessoa mais nova da lista\n");
        printf("5 - Verificar se o ID é primo\n");
        printf("6 - Sair do programa\n");

        printf("\nDigite sua escolha: ");


        scanf("%d", &choice);


        switch (choice) {
            case 1: {
                if (num_people >= max_people) {
                    printf("Erro: limite máximo de pessoas atingido!\n");
                    break;
                }

                struct Person person;
                printf("Digite o ID da pessoa: ");
                scanf("%d", &(person.id));

                printf("Digite o primeiro nome da pessoa: ");
                scanf("%s", person.first_name);

                printf("Digite o sobrenome da pessoa: ");
                scanf("%s", person.last_name);

                printf("Digite a data de nascimento da pessoa (dd/mm/aaaa): ");
                scanf("%s", person.date_of_birth);

                people[num_people] = person;
                num_people++;
                printf("Pessoa adicionada com sucesso!\n");
                break;
            }
            case 2: {
                int id_to_delete;
                printf("Digite o ID da pessoa a ser excluída: ");
                scanf("%d", &id_to_delete);

                int found = 0;
                for (int i = 0; i < num_people; i++) {
                    if (people[i].id == id_to_delete) {
                        found = 1;
                        for (int j = i; j < num_people-1; j++) {
                            people[j] = people[j+1];
                        }
                        num_people--;
                        printf("Pessoa excluída com sucesso!\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Erro: pessoa com ID %d não encontrada!\n", id_to_delete);
                }
                break;
            }
            case 3: {
                printf("\nLista de pessoas:\n");
                for (int i = 0; i < num_people; i++) {
                    print_person(&(people[i]));
                }
                break;
            }
            case 4: {
                if (num_people < 2) {
                    printf("Erro: não há pessoas suficientes na lista para retornar a segunda pessoa mais nova!\n");
                break;
            }

            struct Person youngest = people[0];
            struct Person second_youngest = people[0];

            for (int i = 1; i < num_people; i++) {
                if (strcmp(people[i].date_of_birth, youngest.date_of_birth) > 0) {
                    second_youngest = youngest;
                    youngest = people[i];
                } else if (strcmp(people[i].date_of_birth, second_youngest.date_of_birth) > 0) {
                    second_youngest = people[i];
                }
            }

            printf("Segunda pessoa mais nova na lista:\n");
            print_person(&second_youngest);
            break;
        }



        case 6:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida!\n");
    }
}

free(people);

return 0;
}
