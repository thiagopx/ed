// Hand-written versions of four functions of string.h, split into their own module.

#ifndef _MY_STRING_H
#define _MY_STRING_H

// Returns the length of str, not counting the '\0' (analogous to strlen).
// Cost: O(n).
int my_strlen(const char *str);

// Copies src, '\0' included, into dest (analogous to strcpy).
// Requires: dest has room for my_strlen(src) + 1 characters.
// Cost: O(n).
void my_strcpy(char *dest, const char *src);

// Appends src to the end of dest (analogous to strcat).
// Requires: dest has room for my_strlen(dest) + my_strlen(src) + 1 characters.
// Cost: O(n).
void my_strcat(char *dest, const char *src);

// Compares str1 and str2; returns 0 if equal, a negative value if str1 comes first, a positive
//   value otherwise (analogous to strcmp).
// Cost: O(n).
int my_strcmp(const char *str1, const char *str2);

#endif // _MY_STRING_H
