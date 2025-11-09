#include <stdio.h>
#include <stdlib.h>

#define FREE 0
#define ALLOCATED 1

typedef struct MemoryBlock {
    int start_address;
    int size;
    int status;
    struct MemoryBlock *prev;
    struct MemoryBlock *next;
} MemoryBlock;

MemoryBlock *head = NULL;
int total_memory = 0;
int strategy = 1;

void initialize() {
    printf("Enter total memory size (KB): ");
    scanf("%d", &total_memory);
    
    printf("\nSelect allocation strategy:\n");
    printf("1. First Fit\t");
    printf("2. Best Fit\t");
    printf("3. Worst Fit\t");
    printf("\nEnter choice: ");
    scanf("%d", &strategy);
    
    head = (MemoryBlock *)malloc(sizeof(MemoryBlock));
    head->start_address = 0;
    head->size = total_memory;
    head->status = FREE;
    head->prev = NULL;
    head->next = NULL;
    
    printf("\nMemory initialized: %d KB\n", total_memory);
}
int allocate(int size) {
    static int count = 0;
    count++;
    MemoryBlock *current = head;
    MemoryBlock *selected = NULL;
    while (current != NULL) {
        if (current->status == FREE && current->size >= size) {
            if (strategy == 1) {
                selected = current;
                break;
            } else if (strategy == 2) {
                if (selected == NULL || current->size < selected->size) {
                    selected = current;
                }
            } else if (strategy == 3) {
                if (selected == NULL || current->size > selected->size) {
                    selected = current;
                }
            }
        }
        current = current->next;
    }
    
    if (selected == NULL) {
        printf("Allocation failed!\n");
        return -1;
    }
    
    if (selected->size == size) {
        selected->status = ALLOCATED;
    } else {
        MemoryBlock *new_block = (MemoryBlock *)malloc(sizeof(MemoryBlock));
        new_block->start_address = selected->start_address + size;
        new_block->size = selected->size - size;
        new_block->status = FREE;
        new_block->prev = selected;
        new_block->next = selected->next;
        
        if (selected->next != NULL) {
            selected->next->prev = new_block;
        }
        
        selected->next = new_block;
        selected->size = size;
        selected->status = ALLOCATED;
    }
    static int n;
    if (count==1){
        n=total_memory-size;
    }else{
        n=n-size;
    }

    
    printf("Allocated %d KB at address %d\n", size, selected->start_address);
    printf("Remaining memory: %d KB\n", n);

    return selected->start_address;
}
void deallocate(int address) {
    MemoryBlock *current = head;
    
    while (current != NULL) {
        if (current->start_address == address) {
            if (current->status == FREE) {
                printf("Already free!\n");
                return;
            }
            
            current->status = FREE;
            printf("Freed memory at address %d\n", address);
            
            if (current->next != NULL && current->next->status == FREE) {
                MemoryBlock *temp = current->next;
                current->size += temp->size;
                current->next = temp->next;
                if (current->next != NULL) {
                    current->next->prev = current;
                }
                free(temp);
                printf("Merged with next block\n");
            }
            
            if (current->prev != NULL && current->prev->status == FREE) {
                current->prev->size += current->size;
                current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                free(current);
                printf("Merged with previous block\n");
            }
            return;
        }
        current = current->next;
    }
    
    printf("Address not found!\n");
}
void display() {
    MemoryBlock *current = head;
    int block_num = 1;
    
    printf("\n--- Memory Status ---\n");
    while (current != NULL) {
        printf("Block %d: Address=%d, Size=%d KB, Status=%s\n",
               block_num++, current->start_address, current->size,
               current->status == FREE ? "FREE" : "ALLOCATED");
        current = current->next;
    }
    printf("---------------------\n");
}
void garbage_collect() {
    MemoryBlock *current = head;
    int count = 0;
    
    printf("\nRunning garbage collection...\n");
    
    while (current != NULL) {
        if (current->status == FREE && current->next != NULL && current->next->status == FREE) {
            MemoryBlock *temp = current->next;
            current->size += temp->size;
            current->next = temp->next;
            if (current->next != NULL) {
                current->next->prev = current;
            }
            free(temp);
            count++;
        } else {
            current = current->next;
        }
    }
    
    printf("Merged %d blocks\n", count);
}
int main() {
    int choice, size, address;
    
    printf("=== Memory Allocator ===\n\n");
    initialize();
    
    while (1) {
        printf("\n1. Allocate\t");
        printf("2. Deallocate\t");
        printf("3. Display\t");
        printf("4. Garbage Collect\t");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter size (KB): ");
                scanf("%d", &size);
                allocate(size);
                break;
            case 2:
                printf("Enter address: ");
                scanf("%d", &address);
                deallocate(address);
                break;
            case 3:
                display();
                break;
            case 4:
                garbage_collect();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}