/* ============================================================
 * Mini Project: Fractional Knapsack Algorithm
 * Algorithm   : Greedy Method
 * Description : Finds maximum profit using Fractional Knapsack
 * ============================================================ */

#include <stdio.h>
#include <stdlib.h>

struct Item {
    int profit;
    int weight;
    float ratio;
};

void sortItems(struct Item items[], int n) {

    int i, j;
    struct Item temp;

    for(i = 0; i < n - 1; i++) {

        for(j = i + 1; j < n; j++) {

            if(items[i].ratio < items[j].ratio) {

                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

float fractionalKnapsack(struct Item items[],
                         int n,
                         int capacity) {

    int i;
    float totalProfit = 0.0;

    sortItems(items, n);

    for(i = 0; i < n; i++) {

        if(items[i].weight <= capacity) {

            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }

        else {

            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    return totalProfit;
}

int main() {

    int n, i, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for(i = 0; i < n; i++) {

        printf("Enter profit and weight of item %d: ", i + 1);

        scanf("%d %d",
              &items[i].profit,
              &items[i].weight);

        items[i].ratio =
        (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Maximum Profit = %.2f\n",
           fractionalKnapsack(items,
                              n,
                              capacity));

    return 0;
}
