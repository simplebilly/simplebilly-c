/*
 * attachment_version.h
 *
 * 
 */

#ifndef _attachment_version_H_
#define _attachment_version_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct attachment_version_t attachment_version_t;




typedef struct attachment_version_t {
    char *attachment_id; // string
    char *file_name; // string
    long *file_size; //numeric
    char *mime_type; // string
    char *original_name; // string
    char *sha256_hash; // string
    char *uploaded_by; // string
    int *version_number; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} attachment_version_t;

__attribute__((deprecated)) attachment_version_t *attachment_version_create(
    char *attachment_id,
    char *file_name,
    long *file_size,
    char *mime_type,
    char *original_name,
    char *sha256_hash,
    char *uploaded_by,
    int *version_number
);

void attachment_version_free(attachment_version_t *attachment_version);

attachment_version_t *attachment_version_parseFromJSON(cJSON *attachment_versionJSON);

cJSON *attachment_version_convertToJSON(attachment_version_t *attachment_version);

#endif /* _attachment_version_H_ */

