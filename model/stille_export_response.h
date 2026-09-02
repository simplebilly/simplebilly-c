/*
 * stille_export_response.h
 *
 * 
 */

#ifndef _stille_export_response_H_
#define _stille_export_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stille_export_response_t stille_export_response_t;




typedef struct stille_export_response_t {
    char *csv_content; // string
    char *filename; // string

    int _library_owned; // Is the library responsible for freeing this object?
} stille_export_response_t;

__attribute__((deprecated)) stille_export_response_t *stille_export_response_create(
    char *csv_content,
    char *filename
);

void stille_export_response_free(stille_export_response_t *stille_export_response);

stille_export_response_t *stille_export_response_parseFromJSON(cJSON *stille_export_responseJSON);

cJSON *stille_export_response_convertToJSON(stille_export_response_t *stille_export_response);

#endif /* _stille_export_response_H_ */

