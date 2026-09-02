/*
 * time_entry_clock_out.h
 *
 * 
 */

#ifndef _time_entry_clock_out_H_
#define _time_entry_clock_out_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct time_entry_clock_out_t time_entry_clock_out_t;




typedef struct time_entry_clock_out_t {
    char *clock_out; //date time
    char *hours; // string

    int _library_owned; // Is the library responsible for freeing this object?
} time_entry_clock_out_t;

__attribute__((deprecated)) time_entry_clock_out_t *time_entry_clock_out_create(
    char *clock_out,
    char *hours
);

void time_entry_clock_out_free(time_entry_clock_out_t *time_entry_clock_out);

time_entry_clock_out_t *time_entry_clock_out_parseFromJSON(cJSON *time_entry_clock_outJSON);

cJSON *time_entry_clock_out_convertToJSON(time_entry_clock_out_t *time_entry_clock_out);

#endif /* _time_entry_clock_out_H_ */

