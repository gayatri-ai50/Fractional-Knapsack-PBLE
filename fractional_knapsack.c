#include <stdio.h>

int n = 0;
float value[50], weight[50], ratio[50], selected[50];
float capacity;

void enterDetails()
{
    int i;

    printf("Enter number of packages: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter value and weight of package %d: ", i + 1);
        scanf("%f %f", &value[i], &weight[i]);
        ratio[i] = 0;
        selected[i] = 0;
    }

    printf("Enter capacity: ");
    scanf("%f", &capacity);
}

void displayDetails()
{
    int i;

    printf("\nPackage\tValue\tWeight\tRatio\n");

    for(i = 0; i < n; i++)
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               i + 1, value[i], weight[i], ratio[i]);
}

void calculateRatio()
{
    int i;

    for(i = 0; i < n; i++)
        ratio[i] = value[i] / weight[i];

    printf("\nValue/Weight ratios calculated.\n");
}

void sortPackages()
{
    int i, j;
    float t;

    for(i = 0; i < n - 1; i++)
        for(j = 0; j < n - i - 1; j++)
            if(ratio[j] < ratio[j + 1])
            {
                t = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = t;

                t = value[j];
                value[j] = value[j + 1];
                value[j + 1] = t;

                t = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = t;
            }

    printf("\nPackages sorted by decreasing ratio.\n");
}

void findMaximumValue()
{
    int i;
    float remaining = capacity, total = 0;

    for(i = 0; i < n; i++)
        selected[i] = 0;

    for(i = 0; i < n && remaining > 0; i++)
    {
        if(weight[i] <= remaining)
        {
            selected[i] = 1;
            remaining -= weight[i];
            total += value[i];
        }
        else
        {
            selected[i] = remaining / weight[i];
            total += value[i] * selected[i];
            remaining = 0;
        }
    }

    printf("\nMaximum Value = %.2f\n", total);
}

void displaySelected()
{
    int i;
    float totalWeight = 0;

    printf("\nPackage\tFraction\tWeight Used\tValue\n");

    for(i = 0; i < n; i++)
    {
        if(selected[i] > 0)
        {
            printf("%d\t%.2f\t\t%.2f\t\t%.2f\n",
                   i + 1,
                   selected[i],
                   weight[i] * selected[i],
                   value[i] * selected[i]);

            totalWeight += weight[i] * selected[i];
        }
    }

    printf("\nTotal Weight Used = %.2f\n", totalWeight);
}

int main()
{
    int choice;

    do
    {
        printf("\n--- FRACTIONAL KNAPSACK ---\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: enterDetails(); break;
            case 2: displayDetails(); break;
            case 3: calculateRatio(); break;
            case 4: sortPackages(); break;
            case 5: findMaximumValue(); break;
            case 6: displaySelected(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while(choice != 7);

    return 0;
}