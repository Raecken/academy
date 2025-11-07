#include "paroot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <errno.h>

#define BUFFER_SIZE 1024

// Type definitions (should match header)
typedef char* string;

/**
 * Helper function to read a line from stdin
 */
static char *read_line(void) {
    char *line = NULL;
    size_t capacity = 0;
    size_t size = 0;
    
    while (1) {
        // Grow buffer if needed
        if (size + 1 >= capacity) {
            capacity = (capacity == 0) ? BUFFER_SIZE : capacity * 2;
            char *temp = realloc(line, capacity);
            if (temp == NULL) {
                free(line);
                return NULL;
            }
            line = temp;
        }
        
        // Read one character
        int c = fgetc(stdin);
        
        // Check for end of file or newline
        if (c == EOF || c == '\n') {
            line[size] = '\0';
            return line;
        }
        
        // Add character to buffer
        line[size++] = c;
    }
}

/**
 * Prompts user for a line of text from stdin and returns it as a char
 * Retries if input is not a single character
 */
char get_char(const char *prompt) {
    if (prompt != NULL) {
        printf("%s", prompt);
    }
    
    while (1) {
        char *line = read_line();
        if (line == NULL) {
            printf("Error reading input. Try again.\n");
            if (prompt != NULL) {
                printf("%s", prompt);
            }
            continue;
        }
        
        // Check if input is exactly one character
        if (strlen(line) == 1) {
            char c = line[0];
            free(line);
            return c;
        }
        
        free(line);
        printf("Retry: ");
    }
}

/**
 * Prompts user for a line of text from stdin and returns it as a double
 * Retries if input is not a valid double
 */
double get_double(const char *prompt) {
    if (prompt != NULL) {
        printf("%s", prompt);
    }
    
    while (1) {
        char *line = read_line();
        if (line == NULL) {
            printf("Error reading input. Try again.\n");
            if (prompt != NULL) {
                printf("%s", prompt);
            }
            continue;
        }
        
        // Check for empty input
        if (strlen(line) == 0) {
            free(line);
            printf("Retry: ");
            continue;
        }
        
        char *endptr;
        errno = 0;
        double value = strtod(line, &endptr);
        
        // Check if conversion was successful
        if (errno == 0 && *endptr == '\0' && endptr != line) {
            free(line);
            return value;
        }
        
        free(line);
        printf("Retry: ");
    }
}

/**
 * Prompts user for a line of text from stdin and returns it as a float
 * Retries if input is not a valid float
 */
float get_float(const char *prompt) {
    if (prompt != NULL) {
        printf("%s", prompt);
    }
    
    while (1) {
        char *line = read_line();
        if (line == NULL) {
            printf("Error reading input. Try again.\n");
            if (prompt != NULL) {
                printf("%s", prompt);
            }
            continue;
        }
        
        // Check for empty input
        if (strlen(line) == 0) {
            free(line);
            printf("Retry: ");
            continue;
        }
        
        char *endptr;
        errno = 0;
        float value = strtof(line, &endptr);
        
        // Check if conversion was successful
        if (errno == 0 && *endptr == '\0' && endptr != line) {
            free(line);
            return value;
        }
        
        free(line);
        printf("Retry: ");
    }
}

/**
 * Prompts user for a line of text from stdin and returns it as an int
 * Retries if input is not a valid int
 */
int get_int(const char *prompt) {
    if (prompt != NULL) {
        printf("%s", prompt);
    }
    
    while (1) {
        char *line = read_line();
        if (line == NULL) {
            printf("Error reading input. Try again.\n");
            if (prompt != NULL) {
                printf("%s", prompt);
            }
            continue;
        }
        
        // Check for empty input
        if (strlen(line) == 0) {
            free(line);
            printf("Retry: ");
            continue;
        }
        
        char *endptr;
        errno = 0;
        long value = strtol(line, &endptr, 10);
        
        // Check if conversion was successful and within int range
        if (errno == 0 && *endptr == '\0' && endptr != line && 
            value >= INT_MIN && value <= INT_MAX) {
            free(line);
            return (int)value;
        }
        
        free(line);
        printf("Retry: ");
    }
}

/**
 * Prompts user for a line of text from stdin and returns it as a long
 * Retries if input is not a valid long
 */
long get_long(const char *prompt) {
    if (prompt != NULL) {
        printf("%s", prompt);
    }
    
    while (1) {
        char *line = read_line();
        if (line == NULL) {
            printf("Error reading input. Try again.\n");
            if (prompt != NULL) {
                printf("%s", prompt);
            }
            continue;
        }
        
        // Check for empty input
        if (strlen(line) == 0) {
            free(line);
            printf("Retry: ");
            continue;
        }
        
        char *endptr;
        errno = 0;
        long value = strtol(line, &endptr, 10);
        
        // Check if conversion was successful
        if (errno == 0 && *endptr == '\0' && endptr != line) {
            free(line);
            return value;
        }
        
        free(line);
        printf("Retry: ");
    }
}

/**
 * Prompts user for a line of text from stdin and returns it as a string
 * Returns NULL on error
 */
string get_string(const char *prompt) {
    if (prompt != NULL) {
        printf("%s", prompt);
    }
    
    return read_line();
}

/**
 * Prints an array of integers
 */
void print_array_int(int arr[], size_t length) {
    printf("[");
    for (size_t i = 0; i < length; i++) {
        printf("%d", arr[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * Prints an array of floats
 */
void print_array_float(float arr[], size_t length) {
    printf("[");
    for (size_t i = 0; i < length; i++) {
        printf("%.2f", arr[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * Prints an array of doubles
 */
void print_array_double(double arr[], size_t length) {
    printf("[");
    for (size_t i = 0; i < length; i++) {
        printf("%.2f", arr[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}
