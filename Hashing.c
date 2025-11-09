#include <stdio.h>

int main() {
    int SIZE, n;
    printf("Enter the size of hash table: ");
    scanf("%d", &SIZE);

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n > SIZE) {
        printf("Number of elements exceeds hash table size. Exiting.\n");
        return 1;
    }

    int elements[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]);
    }

    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    for (int i = 0; i < n; i++) {
        int key = elements[i];
        int h1 = key % SIZE;
        int h2 = 7 - (key % 7);
        int h = h1;
        int c = 0;
        int inserted = 0;

        while (hashTable[h] != -1 && c < SIZE) {
            c++;
            h = (h1 + c * h2) % SIZE;
        }

        if (c < SIZE && hashTable[h] == -1) {
            hashTable[h] = key;
            inserted = 1;
        }

        // fallback using linear probing
        if (!inserted) {
            for (int j = 0; j < SIZE; j++) {
                if (hashTable[j] == -1) {
                    hashTable[j] = key;
                    inserted = 1;
                    printf("Inserted %d using linear probing fallback.\n", key);
                    break;
                }
            }
        }

        if (!inserted) {
            printf("Table full, cannot insert %d\n", key);
        }
    }

    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d -> %d\n", i, hashTable[i]);
    }

    return 0;
}
