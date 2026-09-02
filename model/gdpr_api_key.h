/*
 * gdpr_api_key.h
 *
 * 
 */

#ifndef _gdpr_api_key_H_
#define _gdpr_api_key_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gdpr_api_key_t gdpr_api_key_t;




typedef struct gdpr_api_key_t {
    char *created_at; //date time
    char *expires_at; //date time
    char *id; // string
    char *key_id; // string
    char *name; // string
    int *revoked; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} gdpr_api_key_t;

__attribute__((deprecated)) gdpr_api_key_t *gdpr_api_key_create(
    char *created_at,
    char *expires_at,
    char *id,
    char *key_id,
    char *name,
    int *revoked
);

void gdpr_api_key_free(gdpr_api_key_t *gdpr_api_key);

gdpr_api_key_t *gdpr_api_key_parseFromJSON(cJSON *gdpr_api_keyJSON);

cJSON *gdpr_api_key_convertToJSON(gdpr_api_key_t *gdpr_api_key);

#endif /* _gdpr_api_key_H_ */

