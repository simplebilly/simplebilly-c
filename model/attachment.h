/*
 * attachment.h
 *
 * 
 */

#ifndef _attachment_H_
#define _attachment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct attachment_t attachment_t;




typedef struct attachment_t {
    char *contact_id; // string
    char *file_name; // string
    long *file_size; //numeric
    char *mime_type; // string
    char *ocr_text; // string
    char *original_name; // string
    char *pdfa_path; // string
    char *sha256_hash; // string
    char *uploaded_by; // string

    int _library_owned; // Is the library responsible for freeing this object?
} attachment_t;

__attribute__((deprecated)) attachment_t *attachment_create(
    char *contact_id,
    char *file_name,
    long *file_size,
    char *mime_type,
    char *ocr_text,
    char *original_name,
    char *pdfa_path,
    char *sha256_hash,
    char *uploaded_by
);

void attachment_free(attachment_t *attachment);

attachment_t *attachment_parseFromJSON(cJSON *attachmentJSON);

cJSON *attachment_convertToJSON(attachment_t *attachment);

#endif /* _attachment_H_ */

