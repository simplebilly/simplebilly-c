/*
 * tracking_info.h
 *
 * 
 */

#ifndef _tracking_info_H_
#define _tracking_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct tracking_info_t tracking_info_t;

#include "any_type.h"
#include "tracking_event.h"



typedef struct tracking_info_t {
    char *carrier; // string
    char *estimated_delivery; // string
    list_t *events; //nonprimitive container
    any_type_t *raw_response; // custom
    char *status; // string
    char *tracking_number; // string

    int _library_owned; // Is the library responsible for freeing this object?
} tracking_info_t;

__attribute__((deprecated)) tracking_info_t *tracking_info_create(
    char *carrier,
    char *estimated_delivery,
    list_t *events,
    any_type_t *raw_response,
    char *status,
    char *tracking_number
);

void tracking_info_free(tracking_info_t *tracking_info);

tracking_info_t *tracking_info_parseFromJSON(cJSON *tracking_infoJSON);

cJSON *tracking_info_convertToJSON(tracking_info_t *tracking_info);

#endif /* _tracking_info_H_ */

