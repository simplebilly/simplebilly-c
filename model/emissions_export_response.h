/*
 * emissions_export_response.h
 *
 * 
 */

#ifndef _emissions_export_response_H_
#define _emissions_export_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct emissions_export_response_t emissions_export_response_t;




typedef struct emissions_export_response_t {
    char *csv_content; // string
    char *filename; // string

    int _library_owned; // Is the library responsible for freeing this object?
} emissions_export_response_t;

__attribute__((deprecated)) emissions_export_response_t *emissions_export_response_create(
    char *csv_content,
    char *filename
);

void emissions_export_response_free(emissions_export_response_t *emissions_export_response);

emissions_export_response_t *emissions_export_response_parseFromJSON(cJSON *emissions_export_responseJSON);

cJSON *emissions_export_response_convertToJSON(emissions_export_response_t *emissions_export_response);

#endif /* _emissions_export_response_H_ */

