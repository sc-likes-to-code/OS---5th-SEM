#include<stdio.h>

int main()
{
    int n, qt;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    printf("\n Enter the quantam time:");
    scanf("%d",&qt);
    
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
        int executed = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0)
            {
                executed = 1;
                if (rt[i] > qt)
                {
                    rt[i] -= qt;
                    time += qt;
                }
                else
                {
                    time += rt[i];
                    rt[i] = 0;
                    
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    
                    sumwt += wt[i];
                    sumtat += tat[i];
                    
                    count++;
                }
            }
        }
        
        if (executed == 0)
        {
            time++;
        }
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
