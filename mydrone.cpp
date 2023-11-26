#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

struct Node {
    int valdrone;
    char dronenode[100];
    Drone drone;
    Node* next;
};

// Function to add a new node to the linked list
Node* addNode(Node* head, Drone drone) {
    Node* newNode = new Node;
    newNode->valdrone = drone.dronebyte;
    strcpy(newNode->dronenode, drone.droneName);
    newNode->drone = drone;
    newNode->next = head;
    return newNode;
}

// Function to store drones in a linked list and write to a file using fprintf
int storeDronesAndWriteToFile(const char* filename, Node* head) {
    Node* temp = head;
    ofstream saver(filename);
    if (!saver.is_open()) {
        cerr << "Error opening file" << endl;
        return -1;
    }

    while (temp != nullptr) {
        saver << temp->valdrone << "," << temp->dronenode << "," << temp->drone.dronebyte << "," << temp->drone.droneName << endl;
        temp = temp->next;
    }

    cout << "List stored in file successfully" << endl;
    saver.close();

    return 0;
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
    Node* head = addNode(nullptr, sampleDrone1);
    head = addNode(head, sampleDrone2);

    // Store drones in the linked list and write to file using fprintf
    storeDronesAndWriteToFile("drones.txt", head);

    return 0;
}
