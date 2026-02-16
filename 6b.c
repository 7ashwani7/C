//Collision resoultion using linear probing
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

// Hash table structure
struct HashTable {
    int keys[TABLE_SIZE];
    char values[TABLE_SIZE][50];
};

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Initialize hash table
void initializeTable(struct HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->keys[i] = EMPTY;
        strcpy(table->values[i], "");
    }
}

// Insert with linear probing
void insert(struct HashTable *table, int key, char *value) {
    int index = hash(key);
    int i = 0;
    
    // Linear probing: find next available slot
    while (i < TABLE_SIZE) {
        int pos = (index + i) % TABLE_SIZE;
        
        if (table->keys[pos] == EMPTY || table->keys[pos] == DELETED) {
            table->keys[pos] = key;
            strcpy(table->values[pos], value);
            printf("Inserted key %d at index %d\n", key, pos);
            return;
        }
        i++;
    }
    
    printf("Table is full! Cannot insert key %d\n", key);
}

// Search with linear probing
int search(struct HashTable *table, int key) {
    int index = hash(key);
    int i = 0;
    
    // Linear probing: search for the key
    while (i < TABLE_SIZE) {
        int pos = (index + i) % TABLE_SIZE;
        
        if (table->keys[pos] == EMPTY) {
            return -1; // Key not found
        }
        
        if (table->keys[pos] == key) {
            return pos; // Key found
        }
        
        i++;
    }
    
    return -1; // Key not found
}

// Delete with linear probing
void delete(struct HashTable *table, int key) {
    int index = search(table, key);
    
    if (index == -1) {
        printf("Key %d not found!\n", key);
        return;
    }
    
    table->keys[index] = DELETED;
    strcpy(table->values[index], "");
    printf("Deleted key %d from index %d\n", key, index);
}

// Display hash table
void display(struct HashTable *table) {
    printf("\n=== Hash Table (Linear Probing) ===\n");
    printf("Index\tKey\tValue\n");
    printf("-----\t---\t-----\n");
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->keys[i] == EMPTY) {
            printf("%d\tEMPTY\t-\n", i);
        } else if (table->keys[i] == DELETED) {
            printf("%d\tDELETED\t-\n", i);
        } else {
            printf("%d\t%d\t%s\n", i, table->keys[i], table->values[i]);
        }
    }
    printf("\n");
}

int main() {
    struct HashTable table;
    initializeTable(&table);
    
    printf("===== COLLISION RESOLUTION: LINEAR PROBING =====\n\n");
    
    // Insert elements
    printf("--- Inserting Elements ---\n");
    insert(&table, 15, "Apple");
    insert(&table, 25, "Ball");
    insert(&table, 35, "Cat");
    insert(&table, 45, "Dog");
    insert(&table, 55, "Egg");
    
    display(&table);
    
    // Search elements
    printf("--- Searching Elements ---\n");
    int pos = search(&table, 25);
    if (pos != -1) {
        printf("Key 25 found at index %d with value: %s\n", pos, table.values[pos]);
    } else {
        printf("Key 25 not found!\n");
    }
    
    pos = search(&table, 50);
    if (pos != -1) {
        printf("Key 50 found at index %d with value: %s\n", pos, table.values[pos]);
    } else {
        printf("Key 50 not found!\n");
    }
    
    // Delete element
    printf("\n--- Deleting Element ---\n");
    delete(&table, 25);
    
    display(&table);
    
    return 0;
}
