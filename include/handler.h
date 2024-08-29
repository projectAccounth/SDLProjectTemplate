#pragma once

// Include guard
#ifndef HANDLER_H
#define HANDLER_H

#include "mainHeader.h"

// Program controls, called in the processEvent() function
void programControls();

// The function responsible for the main loop
bool processEvent();

#endif /* HANDLER_H */