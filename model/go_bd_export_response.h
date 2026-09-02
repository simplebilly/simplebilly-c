/*
 * go_bd_export_response.h
 *
 * 
 */

#ifndef _go_bd_export_response_H_
#define _go_bd_export_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct go_bd_export_response_t go_bd_export_response_t;




typedef struct go_bd_export_response_t {
    int *booking_count; //numeric
    char *csv_content; // string
    char *filename; // string

    int _library_owned; // Is the library responsible for freeing this object?
} go_bd_export_response_t;

__attribute__((deprecated)) go_bd_export_response_t *go_bd_export_response_create(
    int *booking_count,
    char *csv_content,
    char *filename
);

void go_bd_export_response_free(go_bd_export_response_t *go_bd_export_response);

go_bd_export_response_t *go_bd_export_response_parseFromJSON(cJSON *go_bd_export_responseJSON);

cJSON *go_bd_export_response_convertToJSON(go_bd_export_response_t *go_bd_export_response);

#endif /* _go_bd_export_response_H_ */

