#include <stdio.h>

struct Process {
    int pid; 
    int burst_time; 
    int waiting_time; 
    int turnaround_time; 
};

void sort(struct Process p[], int n) {

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (p[i].burst_time > p[j].burst_time) {

                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void calculate_time(struct Process p[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;

    for (int i = 1; i < n; i++) {

        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }


    float avg_waiting_time = (float) total_waiting_time / n;
    float avg_turnaround_time = (float) total_turnaround_time / n;
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {

    struct Process p[] = {
        {1, 6, 0, 0},
        {2, 8, 0, 0},
        {3, 7, 0, 0},
        {4, 3, 0, 0},
    };
    int n = sizeof(p) / sizeof(p[0]);

    sort(p, n);


    calculate_time(p, n);

    return 0;
}