//Write a C/C++ program to calculate AWT, ATT & ART for CPU Scheduling with FCFS
#include<stdio.h>

struct process {
    char name[10];
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
};

void calculateTimes(struct process p[], int n) {
    int i;


    p[0].waiting_time = 0;
    p[0].response_time = 0;

    // Calculating waiting time, turnaround time, and response time for the rest of the processes
    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
        p[i].response_time = p[i].waiting_time - p[i].arrival_time;

        if (p[i].response_time < 0)
            p[i].response_time = 0;
    }

    // Calculating turnaround time for all processes
    for (i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
    }
}

void displayTimes(struct process p[], int n) {
    int i;
    float awt = 0, att = 0, art = 0;

    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tResponse Time\n");

    for (i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].name, p[i].burst_time, p[i].arrival_time,
               p[i].waiting_time, p[i].turnaround_time, p[i].response_time);

        awt += p[i].waiting_time;
        att += p[i].turnaround_time;
        art += p[i].response_time;
    }

    awt /= n;
    att /= n;
    art /= n;

    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", att);
    printf("Average Response Time: %.2f\n", art);
}

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    // Reading process details
    for (i = 0; i < n; i++) {
        printf("\nEnter the details of process %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", p[i].name);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
    }

    calculateTimes(p, n);
    displayTimes(p, n);

    return 0;
}
