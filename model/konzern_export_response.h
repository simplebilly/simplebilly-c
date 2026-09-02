/*
 * konzern_export_response.h
 *
 * 
 */

#ifndef _konzern_export_response_H_
#define _konzern_export_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct konzern_export_response_t konzern_export_response_t;




typedef struct konzern_export_response_t {
    char *csv_content; // string
    char *filename; // string

    int _library_owned; // Is the library responsible for freeing this object?
} konzern_export_response_t;

__attribute__((deprecated)) konzern_export_response_t *konzern_export_response_create(
    char *csv_content,
    char *filename
);

void konzern_export_response_free(konzern_export_response_t *konzern_export_response);

konzern_export_response_t *konzern_export_response_parseFromJSON(cJSON *konzern_export_responseJSON);

cJSON *konzern_export_response_convertToJSON(konzern_export_response_t *konzern_export_response);

#endif /* _konzern_export_response_H_ */

