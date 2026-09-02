/*
 * gewinnverwendungs_export_response.h
 *
 * 
 */

#ifndef _gewinnverwendungs_export_response_H_
#define _gewinnverwendungs_export_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gewinnverwendungs_export_response_t gewinnverwendungs_export_response_t;




typedef struct gewinnverwendungs_export_response_t {
    char *csv_content; // string
    char *filename; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gewinnverwendungs_export_response_t;

__attribute__((deprecated)) gewinnverwendungs_export_response_t *gewinnverwendungs_export_response_create(
    char *csv_content,
    char *filename
);

void gewinnverwendungs_export_response_free(gewinnverwendungs_export_response_t *gewinnverwendungs_export_response);

gewinnverwendungs_export_response_t *gewinnverwendungs_export_response_parseFromJSON(cJSON *gewinnverwendungs_export_responseJSON);

cJSON *gewinnverwendungs_export_response_convertToJSON(gewinnverwendungs_export_response_t *gewinnverwendungs_export_response);

#endif /* _gewinnverwendungs_export_response_H_ */

