/* INF2610 - TP1
/ Matricule 1 : 2206989
/ Matricule 2 : 2211017
*/
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h> 
#include <stdbool.h> 

/* PARTIE 1 - [4 points] */
struct Wheel {
    int id;
    bool isRearWheel;
};

struct Wing {
    int* id;
};

struct Plane {
    char* id;
    char planeType[10];
    bool isAvailable;
    struct Wheel* wheels;
    struct Wing* wings;
};

struct Wheel* createWheels(int id) {
    struct Wheel* wheels = malloc(sizeof(struct Wheel) * 7);
    for (int i = 0; i < 7; i++) {
        //struct Wheel wheel;
        wheels[i].id = id + i;
        wheels[i].isRearWheel = (i >= 3);
        //wheels[i] = wheel;
    }
    return wheels;
}

void populateWingAttributes(struct Wing* wing, int id) {
    const int TAILLE_ENTIER = 9;
    int* idEnTableau = malloc(sizeof(int) * TAILLE_ENTIER);

    for (int i = 0; i < TAILLE_ENTIER; i++)
    {
        idEnTableau[TAILLE_ENTIER - i - 1] = id % 10;
        id /= 10;
    }
    
    wing->id = idEnTableau;
}

struct Wing* createWings(long id) {
    struct Wing* wings = malloc(sizeof(struct Wing) * 2);
    for (int i = 0; i < 2; i++) {
        populateWingAttributes(&wings[i], id + i);
    }
    return wings;
}

void createPlanes(struct Plane* planes, char* id, int numberOfPlanes) {
    for (int i = 0; i < numberOfPlanes; i++) {
        planes[i].id = id;
        planes[i].isAvailable = true;
        planes[i].wheels = createWheels(atoi(id));
        planes[i].wings = createWings(atoi(id));
        //planes[i] = plane;
    }
}

int main(int argc, char** argv) {
    printf("Hello\n");
    /* Remove comment once the code is completed for the given section to test */
    /* NOTICE : There are mistakes that must be corrected to execute the following lines properly. */
    int id = 1;

    /* PARTIE 2 - [10 points] */

    /* Create wheel - [2 points] */
    struct Wheel* wheels = createWheels(id);
    wheels = createWheels(id);  
    for (int i = 0; i < 7; i++)
    {
        printf("Wheel id: %d\n", wheels[i].id);
    }
    

    /* Create wing - [4 points] */
    long longId = 1;
    struct Wing* wings = createWings(longId);
    //wings = createWings(longId);
    for (int i = 0; i < 2; i++)
    {
        printf("Wing id: ");
        for (int j = 0; j < 9; j++)
        {
            printf("%d", wings[i].id[j]);
        }
        printf("\n");
    }
    
   
    /* Create plane - [4 points] */
    int numberOfPlanes = 3;
    struct Plane* planes = malloc(sizeof(struct Plane) * numberOfPlanes);
    char* strId = "123";
    createPlanes(planes, strId, numberOfPlanes);

    for (int i = 0; i < numberOfPlanes; i++)
    {
        printf("Plane id: %s\n", planes[i].id);


        

    }
    /* Create wheel - [2 points] */
    /*
    Wheel[] wheels;
    wheels = createWheels(id);    
    */

    /* Create wing - [4 points] */
    /*
    long longId = 1;
    Wing[] wings;
    wings = createWings(longId);
    */

    /* Create plane - [4 points] */
    /*
    int numberOfPlanes = 3;
    Plane* planes = malloc(sizeof(Plane) * numberOfPlanes);
    createPlanes(planes, *id, 3);
    */

    /* PARTIE 3 - [6 points] */

    /* Set availabilities - [1 point] */
    /*
    Plane plane = planes[0];
    setAvailability(plane, true);
    */

    /* Get available planes - [1 point] */
    /*
    getAvailablePlanes(planes, numberOfPlanes);
    */

    /* Classify planes - [2 points] */
    /*
    Plane plane = planes[1];
    setPlaneType(plane);
    */

    /* Return type specific planes - [2 points] */
    /*
    char planeType[] = "Small";
    getPlanesByType(planes, planeType,numberOfPlanes);
    */
}
