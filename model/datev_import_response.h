/*
 * datev_import_response.h
 *
 * 
 */

#ifndef _datev_import_response_H_
#define _datev_import_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct datev_import_response_t datev_import_response_t;

#include "datev_import_row.h"



typedef struct datev_import_response_t {
    int *count; //numeric
    char *filename; // string
    list_t *rows; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} datev_import_response_t;

__attribute__((deprecated)) datev_import_response_t *datev_import_response_create(
    int *count,
    char *filename,
    list_t *rows
);

void datev_import_response_free(datev_import_response_t *datev_import_response);

datev_import_response_t *datev_import_response_parseFromJSON(cJSON *datev_import_responseJSON);

cJSON *datev_import_response_convertToJSON(datev_import_response_t *datev_import_response);

#endif /* _datev_import_response_H_ */

