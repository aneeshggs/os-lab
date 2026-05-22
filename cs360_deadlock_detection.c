// Deadlock Detection Algorithm (Simple Version)

#include <stdio.h>

int main()
{
    int p, r, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &p);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    int alloc[p][r], req[p][r], avail[r];
    int finish[p], deadlock = 0;

    // Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    // Request Matrix
    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &req[i][j]);

    // Available Resources
    printf("\nEnter Available Resources:\n");
    for(j = 0; j < r; j++)
        scanf("%d", &avail[j]);

    // Initialize finish array
    for(i = 0; i < p; i++)
        finish[i] = 0;

    // Deadlock Detection
    for(i = 0; i < p; i++)
    {
        int possible = 1;

        for(j = 0; j < r; j++)
        {
            if(req[i][j] > avail[j])
            {
                possible = 0;
                break;
            }
        }

        if(possible)
        {
            finish[i] = 1;

            for(j = 0; j < r; j++)
                avail[j] += alloc[i][j];
        }
    }

    // Check Deadlock
    printf("\nProcesses in Deadlock:\n");

    for(i = 0; i < p; i++)
    {
        if(finish[i] == 0)
        {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
        printf("No Deadlock");

    return 0;
}
