/*
 * year_total.h
 *
 * 
 */

#ifndef _year_total_H_
#define _year_total_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct year_total_t year_total_t;




typedef struct year_total_t {
    char *tco2e; // string
    int *year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} year_total_t;

__attribute__((deprecated)) year_total_t *year_total_create(
    char *tco2e,
    int *year
);

void year_total_free(year_total_t *year_total);

year_total_t *year_total_parseFromJSON(cJSON *year_totalJSON);

cJSON *year_total_convertToJSON(year_total_t *year_total);

#endif /* _year_total_H_ */

