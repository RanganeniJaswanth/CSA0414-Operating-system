#include <stdio.h>

#define MAX_PARTITIONS 10

int main() {
    int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int num_partitions = 6; 
    int processes[] = {115, 500, 358, 200, 375}; 
    int num_processes = 5; 
    int i, j;


    printf("Initial state of memory:\n");
    for (i = 0; i < num_partitions; i++) {
        printf("Partition %d: %d KB\n", i + 1, partitions[i]);
    }
    printf("\n");


    for (i = 0; i < num_processes; i++) {
        for (j = 0; j < num_partitions; j++) {
            if (processes[i] <= partitions[j]) {
                printf("Process %d (%d KB) is placed in Partition %d (%d KB)\n", i + 1, processes[i], j + 1, partitions[j]);
                partitions[j] -= processes[i]; 
                break;
            }
        }
        if (j == num_partitions) {
            printf("Process %d (%d KB) cannot be placed in memory\n", i + 1, processes[i]);
        }
    }


    printf("\nFinal state of memory:\n");
    for (i = 0; i < num_partitions; i++) {
        printf("Partition %d: %d KB\n", i + 1, partitions[i]);
    }

    return 0;
}