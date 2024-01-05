#ifndef ERRORS_H
#define ERRORS_H

#define SEVERE 1
#define NOTSEVERE 0

#include <stdbool.h>

void printe(const int code, const char identifier[16], const bool severe);

#endif
