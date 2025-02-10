#include <stdio.h>
#include <stdlib.h>

// Creating a user-defined data type to represent a process in the system.

struct Process{
    int pid;
    int BT;
    int WT;
};

void readProcesses(char *filename, struct Process processes[], int num_of_processes) {
    
    //Opening the file for reading

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file.");
        exit(1);
    }

    //Reading process data from the file

    for (int i = 0; i < num_of_processes; i++) {
        if (fscanf(fp, "%d %d", &processes[i].pid, &processes[i].BT) != 2) {        //checks whether fscanf reads two integers or not.
            fprintf(stderr, "Error reading from file\n");
            exit(1);
        }
    }

    //Closing the file

    fclose(fp);
}


void agingAlgo(struct Process processes[], int num_of_processes, int quantum) {
    int time = 0;

    int copy_of_BT[num_of_processes];

    for(int i=0;i<num_of_processes;i++){
        copy_of_BT[i]=processes[i].BT;
    }

    while (1) {
        int completed = 0;                                                  //Flag to deteermine whether a process is completed or not. 
        for (int i = 0; i < num_of_processes; i++) {
            if (copy_of_BT[i] > 0) {                                        //Checking whether there is any process left for execution, if yes
                completed = 1;                                              // then setting the flag to 1.



                if (copy_of_BT[i] > quantum) {                              //Checking if the Burst time is greater than the time quantum.
                    time += quantum;
                    copy_of_BT[i] -= quantum;                               //Updating the processes required burst time.
                    processes[i].WT += quantum;                             //Updating the processes waiting time.
                } else {
                    time += copy_of_BT[i];
                    processes[i].WT += time - processes[i].WT;              //Updating the processes waiting time.
                    copy_of_BT[i] = 0;                                      //Marking the processes as finished.

                }
            }
        }

        if (!completed)                                                     //If flag is set to 0, exit the loop.
            break;
    }
}


int main(){

    int num_of_processes;
    printf("Enter the number of processes you wish to schedule: ");
    scanf("%d",&num_of_processes);

    int quantum;
    printf("Enter the time quantum for Round Robin CPU Scheduling: ");
    scanf("%d",&quantum);

    struct Process processes[num_of_processes];                             //Creating an array of type Process to store the requirements of each process.

    readProcesses("processes.txt", processes, num_of_processes);
    agingAlgo(processes, num_of_processes, quantum);

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    int total_WT=0, total_TAT = 0;                               //Initially total waiting time and total turnaround time are zero, since no process is waiting or executing.

    for (int i = 0; i < num_of_processes; i++) {
        total_WT+=processes[i].WT;
        int TAT = processes[i].WT + processes[i].BT;                        //Turnaround time(TAT) = Burst time(BT) + Waiting time(WT)
        total_TAT += TAT;
        printf("     %d\t\t    %d\t\t      %d\t       %d\n", processes[i].pid,processes[i].BT, processes[i].WT, TAT);
    }

    double avg_WT = (double)total_WT / num_of_processes;                           //Calculates average waiting time for the system.
    double avg_TAT = (double)total_TAT / num_of_processes;                         //Calculates avergae turnaround time for the system.

    printf("\nAverage Waiting Time: %.2f\n", avg_WT);
    printf("Average Turnaround Time: %.2f\n\n", avg_TAT);

    return 0;
}
