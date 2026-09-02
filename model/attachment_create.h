/*
 * attachment_create.h
 *
 * 
 */

#ifndef _attachment_create_H_
#define _attachment_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct attachment_create_t attachment_create_t;




typedef struct attachment_create_t {
    char *contact_id; // string
    char *file_name; // string
    long *file_size; //numeric
    char *mime_type; // string
    char *original_name; // string
    char *pdfa_path; // string
    char *sha256_hash; // string
    char *uploaded_by; // string

    int _library_owned; // Is the library responsible for freeing this object?
} attachment_create_t;

__attribute__((deprecated)) attachment_create_t *attachment_create_create(
    char *contact_id,
    char *file_name,
    long *file_size,
    char *mime_type,
    char *original_name,
    char *pdfa_path,
    char *sha256_hash,
    char *uploaded_by
);

void attachment_create_free(attachment_create_t *attachment_create);

attachment_create_t *attachment_create_parseFromJSON(cJSON *attachment_createJSON);

cJSON *attachment_create_convertToJSON(attachment_create_t *attachment_create);

#endif /* _attachment_create_H_ */

