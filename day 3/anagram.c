#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    
    if (strlen(s) != strlen(t)) {
        return false;
    }

    int charCount[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        charCount[s[i] - 'a']++;
    }

    for (int i = 0; t[i] != '\0'; i++) {
        charCount[t[i] - 'a']--;

        if (charCount[t[i] - 'a'] < 0) {
            return false;
        }
    }

    return true;
}

int main() {
    
    char s1[] = "anagram";
    char t1[] = "nagaram";
    printf("Example 1: %s\n", isAnagram(s1, t1) ? "true" : "false");

    char s2[] = "rat";
    char t2[] = "car";
    printf("Example 2: %s\n", isAnagram(s2, t2) ? "true" : "false");

    return 0;
}

