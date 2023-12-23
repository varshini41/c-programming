#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    
    if (strsSize == 0) {
        char* result = (char*)malloc(1);
        result[0] = '\0';
        return result;
    }

    for (int i = 0; strs[0][i] != '\0'; i++) {
        
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i] || strs[j][i] == '\0') {
                
                char* result = (char*)malloc(i + 1);
                strncpy(result, strs[0], i);
                result[i] = '\0';
                return result;
            }
        }
    }

    return strdup(strs[0]);
}

int main() {
    
    char* strs1[] = {"flower", "flow", "flight"};
    int size1 = sizeof(strs1) / sizeof(strs1[0]);
    printf("Example 1: %s\n", longestCommonPrefix(strs1, size1));

    char* strs2[] = {"dog", "racecar", "car"};
    int size2 = sizeof(strs2) / sizeof(strs2[0]);
    printf("Example 2: %s\n", longestCommonPrefix(strs2, size2));

    return 0;
}


