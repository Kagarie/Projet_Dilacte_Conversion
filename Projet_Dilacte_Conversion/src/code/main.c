#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <assert.h>

#include "./main.h"


void static use() {
    puts("The program is used as follows\n./main {--dialect , number}\n");
    puts("You can also convert a date.\n./main --date 01/01/1970\n");
    puts("But also the Roman numerals.\n./main {--Romain,number}\n");
    puts("You can use the following options.\n-c -commande to see available orders.");
    puts("-d -dilacte to see the available dialects.\n");
    puts("Our converter works for numbers between 0 and 1000.");
    puts("If the result is null then your number could not be converted.");
}

void dialect_show() {
    struct dirent *dir;
    DIR *d = opendir("yaml/");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (mystrcmp(dir->d_name, ".") && mystrcmp(dir->d_name, "..")) {
                fprintf(stdout, " Dialect : %s\n", dir->d_name);
            }
        }
        closedir(d);
    }

}

int puissance(int x, int n) {
    int y = 1;
    unsigned int m = 1;
    while (m <= n) {
        y *= x;
        m++;
    }
    return y;
}

void yaml(Array *array, char *dilacte) {
    char *str = (char *) calloc(20, 1);
    my_strcat(str, "yaml/");
    my_strcat(str, dilacte);
    my_strcat(str, ".yaml");

    FILE *file = fopen(str, "rb");
    assert(file);

    if (file == NULL) {
        fputs("Yaml open error!\n", stderr);
        exit(EXIT_FAILURE);
    }

    yaml_parser_t parser;
    yaml_document_t document;
    yaml_node_t *node;
    int i = 1;

    char *word = NULL;
    char *number = NULL;

    assert(yaml_parser_initialize(&parser));

    yaml_parser_set_input_file(&parser, file);

    if (!yaml_parser_load(&parser, &document)) {
        goto done;
    }

    while (1) {
        node = yaml_document_get_node(&document, i);
        i++;
        if (!node) break;
        node->type;
        if (node->type == YAML_SCALAR_NODE) {
            if (strcmp(node->data.scalar.value, dilacte)) {
                if (node->data.scalar.style == 1) {
                    number = node->data.scalar.value;
                }
                if (node->data.scalar.style == 3) {
                    word = node->data.scalar.value;
                }
                if (i % 2 == 0) {
                    array_insertion(array, atoi(number), word);
                }
            }
        }
    }
    array_insertion(array, -1, NULL);
    done:
    yaml_parser_delete(&parser);
    assert(!fclose(file));
}

char *conversion_reference(char *research) {
    Array *arrayReference = array_initialisation();
    yaml(arrayReference, "FR_fr");
    char *res = malloc(sizeof(char));
    res[0] = '\0';


    int i = strlen(research);
    int k = 0;
    int power = i;
    while (i > 0) {
        power = i;
        if (k == strlen(research) - 1 && atoi(&research[k]) == 0) {
            break;
        }

        if (research[k] == '1' && k != 2) {
            NumberToLetter *ref = array_get_first(arrayReference);
            while (ref != NULL) {
                if (puissance(10, i - 1) == numberToLetter_get_number(ref)) {
                    strcat(res, numberToLetter_get_word(ref));
                    strcat(res, " ");
                }
                ref = numberToLetter_get_next(ref);
            }
        } else {
            NumberToLetter *ref = array_get_first(arrayReference);
            while (ref != NULL) {
                if (i == 2) {
                    if (atoi(&research[k]) == numberToLetter_get_number(ref) &&
                        research[k + 1] == '0') {
                        int dizaine = atoi(&research[k]) + atoi(&research[k + 1]);
                        int trouve = 0;
                        puts(" ");
                        if (dizaine == numberToLetter_get_number(ref)) {
                            strcat(res, numberToLetter_get_word(ref));
                            strcat(res, " ");
                            trouve = 1;
                            break;
                        }
                    }
                } else if (atoi(&research[k]) / puissance(10, i - 1) == numberToLetter_get_number(ref) &&
                           research[k] != '0') {
                    strcat(res, numberToLetter_get_word(ref));
                    strcat(res, " ");
                    if (power == 4) {
                        strcat(res, "milles ");
                    }
                    if (power == 3) {
                        strcat(res, "cents ");
                    }
                }

                ref = numberToLetter_get_next(ref);
            }
        }
        i -= 1;
        k += 1;
    }
    array_destroy(arrayReference);
    return res;
}

char *conversion(char *dialect, char *number) {
    Array *arrayDialecte = array_initialisation();

    yaml(arrayDialecte, dialect);

    char *res = malloc(sizeof(char));
    res[0] = '\0';

    if (atoi(number) == 0) {
        return "zero";
    }

    int trouve = 0;
    NumberToLetter *d = array_get_first(arrayDialecte);
    while (d != NULL) {
        if (atoi(number) == numberToLetter_get_number(d)) {
            strcat(res, numberToLetter_get_word(d));
            strcat(res, " ");
            trouve = 1;
            break;
        }
        d = numberToLetter_get_next(d);
    }
    if (trouve == 0) {
        strcat(res, conversion_reference(number));
    }

    array_destroy(arrayDialecte);
    return res;
}

char *conversion_date(char *date) {
    Array *arrayJour = array_initialisation();
    Array *arrayMois = array_initialisation();
    yaml(arrayJour, "Date_day");
    yaml(arrayMois, "Date_month");

    char *res = malloc(sizeof(char));
    res[0] = '\0';
    char *jour;
    char *mois;
    char *annees;

    for (int i = 0; i < 3; i += 1) {
        switch (i) {
            case 0:
                jour = strtok(date, "/");
                break;
            case 1:
                mois = strtok(NULL, "/");
                break;
            case 2:
                annees = strtok(NULL, " ");
                break;
            default:
                puts("Error in converting date");
                exit(EXIT_FAILURE);
        }
    }
    if (atoi(jour) < 0 || atoi(jour) > 31 || atoi(mois) < 0 || atoi(mois) > 12 || atoi(annees) < 0) {
        printf("Error in the date entered\n");
        exit(EXIT_FAILURE);
    }
    //day
    int find = 0;
    NumberToLetter *j = array_get_first(arrayJour);
    while (j != NULL) {
        if (atoi(jour) == numberToLetter_get_number(j)) {
            strcat(res, numberToLetter_get_word(j));
            strcat(res, " ");
            find = 1;
            break;
        }
        j = numberToLetter_get_next(j);
    }

    if (find == 0) {
        strcat(res, conversion_reference(jour));
    }

    //month
    NumberToLetter *m = array_get_first(arrayMois);
    while (m != NULL) {
        if (atoi(mois) == numberToLetter_get_number(m)) {
            strcat(res, numberToLetter_get_word(m));
            strcat(res, " ");
            break;
        }
        m = numberToLetter_get_next(m);
    }
    //year
    char *a = conversion_reference(annees);
    res = realloc(res, strlen(res) + strlen(a));
    strcat(res, a);


    array_destroy(arrayJour);
    array_destroy(arrayMois);
    return res;
}

char *conversion_romain(char *word) {

    Array *arrayRomain = array_initialisation();
    yaml(arrayRomain, "romain");
    char *res = malloc(sizeof(char));
    res[0] = '\0';

    if (strlen(word) == 1 || strlen(word) == 2 && atoi(word) <= 16) {

        int find = 0;
        NumberToLetter *romain = array_get_first(arrayRomain);
        while (romain != NULL) {
            if (atoi(word) == numberToLetter_get_number(romain)) {
                strcat(res, numberToLetter_get_word(romain));
                strcat(res, " ");
                find = 1;
                break;
            }
            romain = numberToLetter_get_next(romain);
        }
        if (find == 0) {
            puts("Erreur rencontré lors la conversion");
            exit(EXIT_FAILURE);
        }

        array_destroy(arrayRomain);
        return res;

    } else if (strlen(word) == 2 && word[1] != 0) {
        char *premier = malloc(sizeof(char));
        premier[0] = word[0] * 10;
        printf("%s\n", word);
        char *premiernb = conversion_romain(premier);
        char *deuxiemenb = conversion_romain(&word[1]);
        char *res = malloc(sizeof(char));
        res[0] = *premiernb;
        strcat(res, deuxiemenb);
        array_destroy(arrayRomain);
        return res;


    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        use();
        exit(EXIT_FAILURE);
    }
    if (mystrcmp(argv[1], "-c") == 0 || mystrcmp(argv[1], "-commande") == 0) {
        use();
        exit(EXIT_SUCCESS);
    }
    if (mystrcmp(argv[1], "-d") == 0 || mystrcmp(argv[1], "-dilacte") == 0) {
        dialect_show();
        exit(EXIT_SUCCESS);
    }

    if (argc != 3) {
        use();
        exit(EXIT_FAILURE);
    }

    if (strtol(argv[2], NULL, 0) < 0) {
        printf("expected integer\n");
        exit(EXIT_FAILURE);
    }
    char *dilact;
    dilact = strtok(argv[1], "--");
    char *number = argv[2];
    if (atoi(number) > 1000) {
        puts("We do not accept numbers greater than 1 000");
        exit(EXIT_FAILURE);
    }


    if (mystrcmp(dilact, "date") == 0) {
        printf("date : %s\n", conversion_date(number));
    } else if (mystrcmp(dilact, "romain") == 0) {
        printf("Number of starts: %s conversion: %s\n", number, conversion_romain(number));
    } else {
        printf("Number of starts: %s conversion: %s\n", number, conversion(dilact, number));
    }
    return EXIT_SUCCESS;
}