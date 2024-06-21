#include <stdio.h>
#include <stdlib.h>

struct WashingMachine {
    int machineID;
    int timeRemaining;
    struct WashingMachine* next;
    struct WashingMachine* prev;
};

struct WashingMachine* createMachine(int id) {
    struct WashingMachine* newMachine = (struct WashingMachine*)malloc(sizeof(struct WashingMachine));
    if (newMachine) {
        newMachine->machineID = id;
        newMachine->timeRemaining = 0;
        newMachine->next = NULL;
        newMachine->prev = NULL;
    }
    return newMachine;
}

void initializeMachines(struct WashingMachine** head, int numMachines) {
    if (numMachines <= 0) {
        *head = NULL;
        return;
    }

    struct WashingMachine* current = createMachine(1);
    *head = current;

    for (int i = 2; i <= numMachines; i++) {
        struct WashingMachine* newMachine = createMachine(i);
        newMachine->prev = current;
        current->next = newMachine;
        current = newMachine;
    }

    // Close the circular loop
    current->next = *head;
    (*head)->prev = current;
}

void bookMachine(struct WashingMachine* head, int machineID, int duration) {
    struct WashingMachine* current = head;

    do {
        if (current->machineID == machineID) {
            current->timeRemaining = duration;
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Machine with ID %d not found.\n", machineID);
}

void updateMachines(struct WashingMachine* head) {
    struct WashingMachine* current = head;

    do {
        if (current->timeRemaining > 0) {
            current->timeRemaining-=10;

            if (current->timeRemaining == 0) {
                printf("Machine %d is available.\n", current->machineID);
            }
        }

        current = current->next;
    } while (current != head);
}

int main() {
    int numMachines = 5;  // Adjust the number of machines as needed
    struct WashingMachine* machineList = NULL;
    initializeMachines(&machineList, numMachines);

    int choice;
    int machineID, duration;

    while (1) {
        printf("\nWashing Machine Rental System:\n");
        printf("1. Book a machine\n");
        printf("2. Update machines\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter machine ID and duration (e.g., 1 60 for Machine 1 and 60 minutes): ");
                scanf("%d %d", &machineID, &duration);
                bookMachine(machineList, machineID, duration);
                break;
            case 2:
                updateMachines(machineList);
                break;
            case 3:
                free(machineList);  // Free allocated memory
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
