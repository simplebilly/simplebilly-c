/*
 * application_filter.h
 *
 * 
 */

#ifndef _application_filter_H_
#define _application_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct application_filter_t application_filter_t;




typedef struct application_filter_t {
    int *page; //numeric
    int *page_size; //numeric
    char *posting_id; // string
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} application_filter_t;

__attribute__((deprecated)) application_filter_t *application_filter_create(
    int *page,
    int *page_size,
    char *posting_id,
    char *status
);

void application_filter_free(application_filter_t *application_filter);

application_filter_t *application_filter_parseFromJSON(cJSON *application_filterJSON);

cJSON *application_filter_convertToJSON(application_filter_t *application_filter);

#endif /* _application_filter_H_ */

