/*
 * time_entry_clock_in.h
 *
 * 
 */

#ifndef _time_entry_clock_in_H_
#define _time_entry_clock_in_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct time_entry_clock_in_t time_entry_clock_in_t;




typedef struct time_entry_clock_in_t {
    char *notes; // string

    int _library_owned; // Is the library responsible for freeing this object?
} time_entry_clock_in_t;

__attribute__((deprecated)) time_entry_clock_in_t *time_entry_clock_in_create(
    char *notes
);

void time_entry_clock_in_free(time_entry_clock_in_t *time_entry_clock_in);

time_entry_clock_in_t *time_entry_clock_in_parseFromJSON(cJSON *time_entry_clock_inJSON);

cJSON *time_entry_clock_in_convertToJSON(time_entry_clock_in_t *time_entry_clock_in);

#endif /* _time_entry_clock_in_H_ */

