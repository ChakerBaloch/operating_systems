#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int process_id;         // Process ID
    int arrival_time;       // Time process arrives
    int burst_time;         // Time needed to complete
    int remaining_time;     // Time left to finish
    int waiting_time;       // Total wait time
    int turnaround_time;    // Total turnaround time
} Process;

// Calculate waiting time and print execution order
void calculateWaitingTimeAndExecutionOrder(Process proc[], int n, int quantum) {
    int current_time = 0, completed = 0, i, all_done;

    for (int j = 0; j < n; j++) {
        proc[j].remaining_time = proc[j].burst_time;
        proc[j].waiting_time = 0;
    }

    printf("Execution Order: ");

    while (completed < n) {
        all_done = 1;

        for (i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0 && proc[i].arrival_time <= current_time) {
                all_done = 0;
                printf("P%d ", proc[i].process_id);

                if (proc[i].remaining_time > quantum) {
                    current_time += quantum;
                    proc[i].remaining_time -= quantum;
                } else {
                    current_time += proc[i].remaining_time;
                    proc[i].waiting_time = current_time - proc[i].burst_time - proc[i].arrival_time;
                    proc[i].remaining_time = 0;
                    completed++;
                }
            }
        }

        if (all_done) current_time++;
    }

    printf("\n");
}

// Calculate turnaround time
void calculateTurnaroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }
}

// Run RR scheduler
void roundRobin(Process proc[], int n, int quantum) {
    calculateWaitingTimeAndExecutionOrder(proc, n, quantum);
    calculateTurnaroundTime(proc, n);
}

// Display results
void printProcesses(Process proc[], int n) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].process_id, proc[i].arrival_time, proc[i].burst_time,
               proc[i].waiting_time, proc[i].turnaround_time);
    }

    float total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    Process proc[] = {{1, 0, 24}, {2, 0, 3}, {3, 0, 3}};
    int n = sizeof(proc) / sizeof(proc[0]);
    int quantum = 4;

    // Error: no processes
    if (n <= 0) {
        fprintf(stderr, "Error: No processes to schedule.\n");
        return 1;
    }

    // Error: invalid quantum
    if (quantum <= 0) {
        fprintf(stderr, "Error: Invalid quantum value. Must be > 0.\n");
        return 1;
    }

    // Error: invalid process data
    for (int i = 0; i < n; i++) {
        if (proc[i].arrival_time < 0 || proc[i].burst_time <= 0) {
            fprintf(stderr, "Error: Invalid data for process %d (arrival: %d, burst: %d).\n",
                    proc[i].process_id, proc[i].arrival_time, proc[i].burst_time);
            return 1;
        }
    }

    roundRobin(proc, n, quantum);
    printProcesses(proc, n);

    return 0;
}
