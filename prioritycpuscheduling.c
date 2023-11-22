#include<stdio.h>
#include<malloc.h>

void line(int i) {
    int j;
    for (j = 1; j <= i; j++)
        printf("-");
    printf("\n");
}

struct process {
    int p_id, priority;
    int etime, wtime, tatime;
};

struct process *p, temp;

int i, j, k, l, n;
float awtime = 0, atatime = 0;

int main() {
    printf("Priority Scheduling\n");
    line(29);
    printf("Enter the no of processes : ");
    scanf("%d", &n);
    p = (struct process *)calloc(n + 1, sizeof(struct process));
    p[0].wtime = 0;
    p[0].tatime = 0;

    for (i = 1; i <= n; i++) {
        printf("Enter the execution time of process %d:", i - 1);
        scanf("%d", &p[i].etime);
        printf("Enter the priority of process %d:", i - 1);
        scanf("%d", &p[i].priority);
        p[i].p_id = i;
    }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n - i; j++)
            if (p[j].priority > p[j + 1].priority) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }

    for (i = 1; i <= n; i++) {
        p[i].wtime = p[i - 1].tatime;
        p[i].tatime = p[i - 1].tatime + p[i].etime;
        awtime += p[i].wtime;
        atatime += p[i].tatime;
    }

    awtime = awtime / n;
    atatime = atatime / n;

    printf("\nSchedule\n");
    line(60);
    printf("Process\t\texection\twait\t\tturnaround\n");
    printf("Id No\t\t time\t\ttime\t\ttime\n");
    line(60);

    for (i = 1; i <= n; i++)
        printf("%7d\t%14d\t%8d\t%14d\n", p[i].p_id, p[i].etime, p[i].wtime, p[i].tatime);

    line(60);
    printf("Avg waiting time:\t %2f\n", awtime);
    printf("Avg turnaround time:\t %2f\n", atatime);
    line(60);

    return (0);
}
