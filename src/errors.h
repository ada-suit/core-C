#ifndef ERRORS_H
#define ERRORS_H

#define SEVERE 1
#define NOTSEVERE 0

typedef __int8_t intb; // byte int

void printe(const int code, const char identifier[16], const intb severe);

#endif
