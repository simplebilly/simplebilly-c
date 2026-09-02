/*
 * pay_gap_export_response.h
 *
 * 
 */

#ifndef _pay_gap_export_response_H_
#define _pay_gap_export_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pay_gap_export_response_t pay_gap_export_response_t;




typedef struct pay_gap_export_response_t {
    char *csv_content; // string
    char *filename; // string

    int _library_owned; // Is the library responsible for freeing this object?
} pay_gap_export_response_t;

__attribute__((deprecated)) pay_gap_export_response_t *pay_gap_export_response_create(
    char *csv_content,
    char *filename
);

void pay_gap_export_response_free(pay_gap_export_response_t *pay_gap_export_response);

pay_gap_export_response_t *pay_gap_export_response_parseFromJSON(cJSON *pay_gap_export_responseJSON);

cJSON *pay_gap_export_response_convertToJSON(pay_gap_export_response_t *pay_gap_export_response);

#endif /* _pay_gap_export_response_H_ */

