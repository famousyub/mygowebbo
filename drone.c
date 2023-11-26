#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<math.h>
#include<stdarg.h>


typedef struct Delta Delta;
typedef struct Droneconfig Droneconfig;
typedef struct Drone Drone;
typedef unsigned char unchar;



typedef struct  Dronef  Dronef;


struct  Dronef{

     int id ;
     char fname[1024];
     char lname[1024];
     FILE *file ;
};

struct Delta {
    int _sizer;
    char fg_drone[1024];
    char deltaname[1024];
    char droneconf_actif[20];
    int droneIdbyte;
    char droneId[512];
};

struct Droneconfig {
    Delta dela;
    char config_beta[1024];
    int droneElice;
    char portNum[20];
    int urlFetch[1024];
    char filelog[1024];
};

struct Drone {
    Droneconfig droneconfig;
    int drones_fg;
    int dronebyte;
    char droneName[50];
    char linenName[1024];
    int lines;
    int user_id;
    int isUsed;
    FILE* readdrone;
};

typedef struct node node;

struct node {
    int valdrone;
    char dronenode[100];
    Drone drone;
    node* next;
};

// Function to add a new node to the linked list
node* addNode(node* head, Drone drone) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->valdrone = drone.dronebyte; // Assuming dronebyte is unique, adjust accordingly
    strcpy(newNode->dronenode, drone.droneName);
    newNode->drone = drone;
    newNode->next = head;
    return newNode;
}

// Function to store drones in a linked list and write to a file using fprintf
int storeDronesAndWriteToFile(const char* filename, node* head) {
    node* temp = head;
    FILE* saver;

    saver = fopen(filename, "w");
    if (!saver) {
        perror("error opening file");
        return -1;
    }

    while (temp != NULL) {
        fprintf(saver, "%d,%s,%d,%s\n", temp->valdrone, temp->dronenode, temp->drone.dronebyte, temp->drone.droneName);
        temp = temp->next;
    }

    printf("List stored in file successfully\n");
    fclose(saver);

    return 0;
}





void _saveDroneF(Dronef dronef, const char *filename ,  int flags_)
{
    FILE *output = fopen(filename, "a+");

    if(!output){
        fprintf(stdout , "error  open file");
        exit(-1);
    }

    fprintf(output, "data  {flags _ }   \t >> :  { %d  }  << >>  \t\n" , flags_);

    int flag_ = 0;
    flag_ = fwrite(&dronef , sizeof(Dronef),1, output);

    if(flag_){
           printf("succesfully  added data");

    }else printf("error  saving data");

    fclose(output);


    


}


int main() {
    // Create a sample Drone
    Drone sampleDrone1;
    sampleDrone1.dronebyte = 1;
    strcpy(sampleDrone1.droneName, "SampleDrone1");

    // Create another sample Drone
    Drone sampleDrone2;
    sampleDrone2.dronebyte = 2;
    strcpy(sampleDrone2.droneName, "SampleDrone2");

    // Add the sample drones to the linked list
    node* head = addNode(NULL, sampleDrone1);
    head = addNode(head, sampleDrone2);

    // Store drones in the linked list and write to file using fprintf
    storeDronesAndWriteToFile("drones.txt", head);

    return 0;
}
