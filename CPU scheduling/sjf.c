#include<stdio.h>
#include<limits.h>

int main(){
    int i, n;
    printf("\n Enter the number of processes:");
    scanf("%d",&n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];
    int completed[n];   // keeps track of completed processes

    int count = 0;      // number of completed processes
    int time = 0;       // current time

    float sumwt = 0;
    float sumtat = 0;

    // input arrival times
    for(i=0;i<n;i++){
        pid[i] = i+1;
        completed[i] = 0;
        printf("\n Enter arrival time of process %d:",pid[i]);
        scanf("%d",&at[i]);
    }

    // input burst times
    for(i=0;i<n;i++){
        printf("\n Enter burst time of process %d:",pid[i]);
        scanf("%d",&bt[i]);
        ct[i] = 0;
    }

    // main SJF algorithm
    while(count < n){
        int smallest = -1;
        int min = INT_MAX;

        // find process with shortest burst time among arrived processes
        for(i=0;i<n;i++){
            if(at[i] <= time && completed[i] == 0 && bt[i] < min){
                min = bt[i];
                smallest = i;
            }
        }

        // CPU idle condition
        if(smallest == -1){
            time++;
            continue;
        }

        // execute selected process completely (NON-PREEMPTIVE)
        time += bt[smallest];
        ct[smallest] = time;
        tat[smallest] = ct[smallest] - at[smallest];
        wt[smallest] = tat[smallest] - bt[smallest];

        sumwt += wt[smallest];
        sumtat += tat[smallest];

        completed[smallest] = 1;
        count++;
    }

    // display output
    printf("\n ProcessId\tArrivalTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitingTime");
    for(i=0;i<n;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\n Average Waiting time : %f", sumwt/n);
    printf("\n Average Turn Around time : %f", sumtat/n);

    return 0;
}
