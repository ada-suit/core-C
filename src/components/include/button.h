#ifndef BUTTON_h
#define BUTTON_h

#include "../include/unit.h"

Unit* buttons_gen();
short buttons_update(const uint *counter);
void  buttons_free();

#endif
