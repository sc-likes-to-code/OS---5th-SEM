#include<stdio.h>
#include<limits.h>
int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int count = 0, time = 0;
    
    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], rt[n];
    float sumwt = 0.0, sumtat = 0.0, avgtat = 0.0, avgwt = 0.0;
    
    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter AT of proc %d", pid[i]);
        scanf("%d", &at[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter BT of proc %d", pid[i]);
        scanf("%d", &bt[i]);
        
        ct[i] = 0;
        rt[i] = bt[i];
    }
    
    while (count < n)
    {
        int smallest = -1;
        int min = INT_MAX;
        
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0 && rt[i] < min)
            {
                min = rt[i];
                smallest = i;
            }
        }
        
        if (smallest == -1)
        {
            time++;
            continue;
        }
        
        rt[smallest]--;
        
        if (rt[smallest] == 0)
        {
            ct[smallest] = time + 1;
            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];
            sumtat += tat[smallest];
            sumwt += wt[smallest];
            count++;
        }
        time++;
    }
    
    printf("\n ProcessId\tArrivalTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitingTime");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    
    avgtat = sumtat / n;
    avgwt = sumwt / n;
    
    printf("Avg TAT: ", &avgtat);
    printf("Avg WT: ", &avgwt);
    
    return 0;
}
