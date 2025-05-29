#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for a process
typedef struct {
    int process_id;        // Unique ID for the process
    int arrival_time;      // Time at which the process arrives
    int burst_time;        // Total time the process requires on CPU
    int remaining_time;    // Time left for the process to complete
    int waiting_time;      // Total time process has waited in the ready queue
    int turnaround_time;   // Total time from arrival to completion
    int is_completed;      // Flag to check if the process is finished
} Process;

int n; // Number of processes

// find the index of the process with the shortest remaining time that is ready to execute
int findNextProcess(Process proc[], int current_time) {
    int idx = -1;
    int min_remaining_time = INT_MAX;

    // Loop through all processes to find the shortest ready one
    for (int i = 0; i < n; i++) {
        if (proc[i].arrival_time <= current_time &&
            proc[i].remaining_time > 0 &&
            proc[i].remaining_time < min_remaining_time) {
            min_remaining_time = proc[i].remaining_time;
            idx = i;
        }
    }
    return idx; // Index of the selected process
}

// simulate Shortest Remaining Time First (SRTF) scheduling
void srtf(Process proc[]) {
    int completed = 0;     // Number of processes completed
    int current_time = 0;  // Current time in the simulation

    // Initialize remaining times and completion flags for each process
    for (int i = 0; i < n; i++) {
        proc[i].remaining_time = proc[i].burst_time;
        proc[i].is_completed = 0;
    }

    printf("Execution Order: ");

    // Continue until all processes are completed
    while (completed < n) {
        int idx = findNextProcess(proc, current_time);

        // If a valid process is found
        if (idx != -1) {
            printf("P%d ", proc[idx].process_id);
            proc[idx].remaining_time--;  // Execute the process for 1 time unit

            // If the process finishes now
            if (proc[idx].remaining_time == 0) {
                proc[idx].is_completed = 1;
                completed++;
                int finish_time = current_time + 1;
                proc[idx].turnaround_time = finish_time - proc[idx].arrival_time;
                proc[idx].waiting_time = proc[idx].turnaround_time - proc[idx].burst_time;
            }
        } else {
            // No process is ready; CPU is idle
            printf("Idle ");
        }

        current_time++; // Move to next time unit
    }

    printf("\n");
}

// Display process information and performance metrics
void printProcesses(Process proc[]) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].process_id, proc[i].arrival_time, proc[i].burst_time,
               proc[i].waiting_time, proc[i].turnaround_time);
    }

    // Calculate and print averages
    float total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    // Initialize an array of processes with arrival and burst times
    Process proc[] = {
        {1, 0, 8},
        {2, 1, 4},
        {3, 2, 9},
        {4, 3, 5}
    };

    // Determine number of processes
    n = sizeof(proc) / sizeof(proc[0]);

    // Run the SRTF scheduling simulation
    srtf(proc);

    // Display the results
    printProcesses(proc);

    return 0;
}
