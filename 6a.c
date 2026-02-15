// Basic Hash Functions in C
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 7

// 1. Division Hash Function
int divisionHash(int key) {
    return key % TABLE_SIZE;
}

// 2. Folding Hash Function
int foldingHash(int key) {
    int sum = 0;
    while (key > 0) {
        sum += key % 10;
        key /= 10;
    }
    return sum % TABLE_SIZE;
}

// 3. String Hash Function
int stringHash(char *str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash += str[i];
    }
    return hash % TABLE_SIZE;
}

int main() {
    printf("===== BASIC HASH FUNCTIONS =====\n\n");
    
    // Division Hash
    printf("1. Division Hash (key %% TABLE_SIZE):\n");
    int keys[] = {10, 15, 23, 28, 35};
    for (int i = 0; i < 5; i++) {
        printf("   Key %d -> Hash %d\n", keys[i], divisionHash(keys[i]));
    }
    
    // Folding Hash
    printf("\n2. Folding Hash (sum of digits):\n");
    for (int i = 0; i < 5; i++) {
        printf("   Key %d -> Hash %d\n", keys[i], foldingHash(keys[i]));
    }
    
    // String Hash
    printf("\n3. String Hash (sum of ASCII values):\n");
    char *strings[] = {"apple", "ball", "cat", "dog", "egg"};
    for (int i = 0; i < 5; i++) {
        printf("   \"%s\" -> Hash %d\n", strings[i], stringHash(strings[i]));
    }
    
    return 0;
}
