/*
 * new_version_request.h
 *
 * Body for uploading a new version. Bytes must already be stored under &#x60;file_name&#x60; via the object storage API.
 */

#ifndef _new_version_request_H_
#define _new_version_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct new_version_request_t new_version_request_t;




typedef struct new_version_request_t {
    char *file_name; // string
    long *file_size; //numeric
    char *mime_type; // string
    char *original_name; // string
    char *sha256_hash; // string

    int _library_owned; // Is the library responsible for freeing this object?
} new_version_request_t;

__attribute__((deprecated)) new_version_request_t *new_version_request_create(
    char *file_name,
    long *file_size,
    char *mime_type,
    char *original_name,
    char *sha256_hash
);

void new_version_request_free(new_version_request_t *new_version_request);

new_version_request_t *new_version_request_parseFromJSON(cJSON *new_version_requestJSON);

cJSON *new_version_request_convertToJSON(new_version_request_t *new_version_request);

#endif /* _new_version_request_H_ */

