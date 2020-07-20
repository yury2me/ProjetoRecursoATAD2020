/**
 * @file mapElem.c
 * @brief Implements operations for types MapKey and MapValue.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "mapElem.h"
#include <stdio.h>
#include <string.h>
#include "rating.h"

void mapKeyPrint(MapKey key) {
	printf("%s", key.key);
}

void mapValuePrint(MapValue value) {
	printRating(value);
}

bool mapKeyEquals(MapKey key1, MapKey key2) {
	// in case of string keys:
	return strcmp(key1.key, key2.key) == 0;
}