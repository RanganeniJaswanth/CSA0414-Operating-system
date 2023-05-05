#include <stdio.h>

#define MAX_PROCESSES 10

int main() 
{
    int arrival_time[MAX_PROCESSES] = {0, 1, 2, 4}; 
    int burst_time[MAX_PROCESSES] = {5, 3, 3, 1}; 
    int remaining_time[MAX_PROCESSES]; 
    int completion_time[MAX_PROCESSES]; 
    int waiting_time[MAX_PROCESSES]; 
    int turnaround_time[MAX_PROCESSES]; 
    int num_processes = 4; 
    int i, j, t, min_remaining_time, shortest_job_index;
    float avg_waiting_time = 0, avg_turnaround_time = 0;


    for (i = 0; i < num_processes; i++) {
        remaining_time[i] = burst_time[i];
        completion_time[i] = 0;
    }


    int num_completed_processes = 0;
    for (t = 0; num_completed_processes < num_processes; t++) {

        min_remaining_time = 99999; 
        shortest_job_index = -1;
        for (i = 0; i < num_processes; i++) {
            if (arrival_time[i] <= t && remaining_time[i] < min_remaining_time && remaining_time[i] > 0) {
                min_remaining_time = remaining_time[i];
                shortest_job_index = i;
            }
        }


        remaining_time[shortest_job_index]--;
        if (remaining_time[shortest_job_index] == 0) 
		{
            completion_time[shortest_job_index] = t + 1;
            num_completed_processes++;
        }


        for (i = 0; i < num_processes; i++) {
            if (arrival_time[i] <= t && i != shortest_job_index && remaining_time[i] > 0) {
                waiting_time[i]++;
            }
            turnaround_time[i] = completion_time[i] - arrival_time[i];
        }
    }


    for (i = 0; i < num_processes; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;


    printf("Process\t Arrival Time\t Burst Time\t Completion Time\t Waiting Time\t Turnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("P%d\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %.2f ms\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f ms\n", avg_turnaround_time);

    return 0;
}