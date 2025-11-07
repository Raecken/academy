#ifndef PAROOT_H
#define PAROOT_H

#include <stddef.h>
#include <stdbool.h>

/**
 * Paroot Library for C
 * Simple functions to help students learn C programming
 */

// Type definitions
typedef char* string;

// Input functions
char get_char(const char *prompt);
double get_double(const char *prompt);
float get_float(const char *prompt);
int get_int(const char *prompt);
long get_long(const char *prompt);
string get_string(const char *prompt);

// String helper functions
string trim_string(const char *str);

// Utility functions
void print_array_int(int arr[], size_t length);
void print_array_float(float arr[], size_t length);
void print_array_double(double arr[], size_t length);

#endif
