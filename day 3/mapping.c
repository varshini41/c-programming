#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* digitToLetters[] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void generateCombinations(char* digits, int index, char* current, char** result, int* resultSize) {
    
    if (digits[index] == '\0') {
        result[*resultSize] = strdup(current);
        (*resultSize)++;
        return;
    }

    const char* letters = digitToLetters[digits[index] - '0'];

    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        generateCombinations(digits, index + 1, current, result, resultSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    
    if (digits == NULL || digits[0] == '\0') {
        *returnSize = 0;
        return NULL;
    }

    
    int numCombinations = 1;
    for (int i = 0; digits[i] != '\0'; i++) {
        numCombinations *= strlen(digitToLetters[digits[i] - '0']);
    }

    char** result = (char**)malloc(numCombinations * sizeof(char*));
    *returnSize = 0;

    
    char* current = (char*)malloc(strlen(digits) + 1);

    
    generateCombinations(digits, 0, current, result, returnSize);

    
    free(current);

    return result;
}

int main() {
    
    char digits[] = "23";
    int size;
    char** result = letterCombinations(digits, &size);

    printf("Example: Letter Combinations for %s:\n", digits);
    for (int i = 0; i < size; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }

    free(result);

    return 0;
}



