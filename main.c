#include <stdlib.h>
#include <stdio.h>

typedef struct element Element;
struct element {
    int value;
    Element *suivant;
};

typedef struct pile Pile;
struct pile {
    Element *premier;
};

typedef struct file File;
struct file {
    Element *premier;
};

File *initialiserFile() {
    File *file = malloc(sizeof(*file));

    if(file == NULL) {
        exit(EXIT_FAILURE);
    }

    file->premier = NULL;
    return file;
}

void enfiler(File *file, int nvNombre) {
    Element *nouveau = malloc(sizeof(*nouveau));

    if(file == NULL || nouveau == NULL) {
        exit(EXIT_FAILURE);
    }

    nouveau->value = nvNombre;
    nouveau->suivant = NULL;
    
    if(file->premier != NULL) {
        Element *elementActuelle = file->premier;
        while(elementActuelle->suivant != NULL) {
            elementActuelle = elementActuelle->suivant;
        }
        elementActuelle->suivant = nouveau;
    }
    else {
        file->premier = nouveau;
    }
}

int defiler(File *file) {
    if(file == NULL) {
        exit(EXIT_FAILURE);
    }

    int nombreDefiler = 0;

    if(file->premier != NULL) {
        Element *elementDefiler = file->premier;

        nombreDefiler = elementDefiler->value;
        file->premier = elementDefiler->suivant;
        free(elementDefiler);
    }

    return nombreDefiler;
}

void afficherFile(File *file) {
    if(file == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *elementActuelle = file->premier;

    while(elementActuelle != NULL) {
        printf("%d\n", elementActuelle->value);
        elementActuelle = elementActuelle->suivant;
    }

    printf("\n");
}

Pile *initialiserPile() {
    Pile *pile = malloc(sizeof(*pile));

    if(pile == NULL) {
        exit(EXIT_FAILURE);
    }

    pile->premier = NULL;

    return pile;
}

void empiler(Pile *pile, int nvNombre) {
    Element *nouveau = malloc(sizeof(*nouveau));

    if(pile == NULL || nouveau == NULL) {
        exit(EXIT_FAILURE);
    }
    
    nouveau->value = nvNombre;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}

int depiler(Pile *pile) {
    if(pile == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *elementDepiler = pile->premier;
    int nombreDepiler = elementDepiler->value;

    if(pile != NULL && pile->premier != NULL) {
        pile->premier = elementDepiler->suivant;
        free(elementDepiler);
    }

    return nombreDepiler;
}

void afficherPile(Pile *pile) {
    if(pile == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *elementActuelle = pile->premier;

    while(elementActuelle != NULL) {
        printf("%d\n", elementActuelle->value);
        elementActuelle = elementActuelle->suivant;
    }
    printf("\n");
}

int main() {

    Pile *maPile = initialiserPile();

    empiler(maPile, 4);
    empiler(maPile, 8);
    empiler(maPile, 15);
    empiler(maPile, 16);
    empiler(maPile, 23);
    empiler(maPile, 42);

    printf("\nEtat de la pile :\n");
    afficherPile(maPile);

    printf("Je depile %d\n", depiler(maPile));
    printf("Je depile %d\n", depiler(maPile));

    printf("\nEtat de la pile :\n");
    afficherPile(maPile);




    File *maFile = initialiserFile();

    enfiler(maFile, 4);
    enfiler(maFile, 8);
    enfiler(maFile, 15);
    enfiler(maFile, 16);
    enfiler(maFile, 23);
    enfiler(maFile, 42);

    printf("\nEtat de la file :\n");
    afficherFile(maFile);

    printf("Je defile %d\n", defiler(maFile));
    printf("Je defile %d\n", defiler(maFile));

    printf("\nEtat de la file :\n");
    afficherFile(maFile);

    return 0;
}