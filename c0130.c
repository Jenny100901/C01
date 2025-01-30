#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *smash(const char *words[], size_t count) {
    if (count == 0) return calloc(1, 1);  // Return empty string if no words

    // Calculate required memory (total length of all words + spaces + null terminator)
    size_t total_length = 1;  // Null terminator
    for (size_t i = 0; i < count; i++) {
        total_length += strlen(words[i]) + (i < count - 1 ? 1 : 0);
    }

    // Allocate memory on heap
    char *result = (char *)malloc(total_length);
    if (!result) return NULL;  // Memory allocation failed

    // Construct the sentence
    result[0] = '\0';  // Ensure it's an empty string initially
    for (size_t i = 0; i < count; i++) {
        strcat(result, words[i]);  // Append word
        if (i < count - 1) strcat(result, " ");  // Add space if not last word
    }

    return result;
}

int main() {
    const char *words[] = {"hello", "world", "this", "is", "great"};
    size_t count = sizeof(words) / sizeof(words[0]);

    char *sentence = smash(words, count);
    if (sentence) {
        printf("%s\n", sentence);  // Output: "hello world this is great"
        free(sentence);  // Free allocated memory
    }

    return 0;
}
