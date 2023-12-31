#ifndef ERRORS_H
#define ERRORS_H

#include <stdbool.h>

#define SEVERE 1
#define NOTSEVERE 0

void printe(int code, const char identifier[16], bool severe);

#endif
