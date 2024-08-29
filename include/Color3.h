#pragma once

// Include guard
#ifndef COLOR3_H
#define COLOR3_H
// Required for uint8_t
#include <cstdint>

// Basically the Color3 struct with an alpha channel
typedef struct Color3 {
	uint8_t r, g, b, a;
} Color3;

#endif /* COLOR3_H */
