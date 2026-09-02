/*
 * category_total.h
 *
 * 
 */

#ifndef _category_total_H_
#define _category_total_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct category_total_t category_total_t;




typedef struct category_total_t {
    char *category_id; // string
    double *share_pct; //numeric
    char *tco2e; // string

    int _library_owned; // Is the library responsible for freeing this object?
} category_total_t;

__attribute__((deprecated)) category_total_t *category_total_create(
    char *category_id,
    double *share_pct,
    char *tco2e
);

void category_total_free(category_total_t *category_total);

category_total_t *category_total_parseFromJSON(cJSON *category_totalJSON);

cJSON *category_total_convertToJSON(category_total_t *category_total);

#endif /* _category_total_H_ */

