#include <stdio.h>
#include <malloc.h>

void line(int i) {
    int j;
    for (j = 1; j <= i; j++)
        printf("-");
    printf("\n");
}

struct process {
    int p_id;
    int etime, wtime, tatime;
};

struct process *p, *tmp;

int i, j, k, l, n, time_slice, ctime;
float awtime = 0, atatime = 0;

int main() {
    printf("Process Scheduling - Round Robin \n");
    line(29);
    printf("Enter the no.of processes : ");
    scanf("%d", &n);
    printf("Enter the time slice : ");
    scanf("%d", &time_slice);
    printf("Enter the context switch time : ");
    scanf("%d", &ctime);
    p = (struct process *)calloc(n + 1, sizeof(struct process));
    tmp = (struct process *)calloc(n + 1, sizeof(struct process));

    for (i = 1; i <= n; i++) {
        printf("Enter the execution time of process %d : ", i - 1);
        scanf("%d", &p[i].etime);
        p[i].wtime = (time_slice + ctime) * i - 1;
        awtime += p[i].wtime;
        p[i].p_id = i - 1;
        tmp[i] = p[i];
    }

    i = 0;
    j = 1;
    k = 0;
    
    while (i < n) {
        for (j = 1; j <= n; j++) {
            if (tmp[j].etime <= time_slice && tmp[j].etime != 0) {
                k = k + tmp[j].etime;
                tmp[j].etime = 0;
                p[j].tatime = k;
                atatime += p[j].tatime;
                k = k + ctime;
                i++;
            }
            if (tmp[j].etime > time_slice && tmp[j].etime != 0) {
                k = k + time_slice + ctime;
                tmp[j].etime -= time_slice;
            }
        }
    }

    awtime = awtime / n;
    atatime = atatime / n;

    printf("\nShedule \n");
    line(60);
    printf("Process\t\tExecution\tWait\t\tTurnaround\n");
    printf("Id No\t\ttime\t\ttime\t\ttime\n");
    line(60);

    for (i = 1; i <= n; i++)
        printf("%7d\t%14d\t%8d\t%14d \n", p[i].p_id, p[i].etime, p[i].wtime, p[i].tatime);

    line(60);
    printf("Avg waiting time :\t%2f \n", awtime);
    printf("Avg turn around time :\t%2f\n", atatime);
    line(60);

    return (0);
}
