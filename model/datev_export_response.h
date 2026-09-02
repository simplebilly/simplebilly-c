/*
 * datev_export_response.h
 *
 * 
 */

#ifndef _datev_export_response_H_
#define _datev_export_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct datev_export_response_t datev_export_response_t;




typedef struct datev_export_response_t {
    int *booking_count; //numeric
    char *csv_content; // string
    char *filename; // string

    int _library_owned; // Is the library responsible for freeing this object?
} datev_export_response_t;

__attribute__((deprecated)) datev_export_response_t *datev_export_response_create(
    int *booking_count,
    char *csv_content,
    char *filename
);

void datev_export_response_free(datev_export_response_t *datev_export_response);

datev_export_response_t *datev_export_response_parseFromJSON(cJSON *datev_export_responseJSON);

cJSON *datev_export_response_convertToJSON(datev_export_response_t *datev_export_response);

#endif /* _datev_export_response_H_ */

