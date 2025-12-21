#include<stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];
    
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
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }
    
    ct[0] = at[0] + bt[0];
    
    for (int i = 1; i < n; i++)
    {
        if (at[i] > ct[i - 1])
        {
            ct[i] = at[i] + bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    
    float sumwt = 0, sumtat = 0, avgwt = 0, avgtat = 0;
    
    for (int i = 0; i < n; i++)
    {
        sumwt += wt[i];
        sumtat[i] += tat[i];
    }
    
    avgtat = sumtat / n;
    avgwt = sumwt / n;
    
    printf("Avg TAT: ", &avgtat);
    printf("Avg WT: ", &avgwt);
    
    return 0;
}
