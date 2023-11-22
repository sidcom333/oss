#include <stdio.h>

struct sjfs
{
    char pname[10];
    int btime;
} proc[10], a;

void main()
{
    int n, i, j;
    int temp = 0, temp1 = 0, temp2;
    char name[20];
    float tt, awt;

    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the process name:\n");
        scanf("%s", &proc[i].pname);
        printf("Enter the Burst time:\n");
        scanf("%d", &proc[i].btime);
    }

    // Sorting processes based on burst time using SJF algorithm
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (proc[i].btime < proc[j].btime)
            {
                a = proc[i];
                proc[i] = proc[j];
                proc[j] = a;
            }
        }
    }

    printf("-------------------- CPU SCHEDULING ALGORITHM - SJFS ---\n");
    printf("\n\tprocess name \tBurst time \twaiting time \tturnaround time\n");
    temp = 0;

    for (i = 0; i < n; i++)
    {
        temp = temp1 + temp + proc[i].btime;
        temp1 = temp1 + proc[i].btime;
        temp2 = temp1 - proc[i].btime;

        printf("\n\t%s \t%d ms \t%d ms \t%d ms\n", proc[i].pname, proc[i].btime, temp2, temp1);
    }

    printf("\n");
    awt = (temp - temp1) / n;
    tt = temp / n;

    printf("The Average Waiting time is %4.2f milliseconds\n", awt);
    printf("The Average Turnaround time is %4.2f milliseconds\n", tt);
}
