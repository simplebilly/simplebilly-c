/*
 * gdpr_refresh_token.h
 *
 * 
 */

#ifndef _gdpr_refresh_token_H_
#define _gdpr_refresh_token_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gdpr_refresh_token_t gdpr_refresh_token_t;




typedef struct gdpr_refresh_token_t {
    char *created_at; //date time
    char *expires_at; //date time
    char *id; // string
    char *revoked_at; //date time
    char *tenant_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gdpr_refresh_token_t;

__attribute__((deprecated)) gdpr_refresh_token_t *gdpr_refresh_token_create(
    char *created_at,
    char *expires_at,
    char *id,
    char *revoked_at,
    char *tenant_id
);

void gdpr_refresh_token_free(gdpr_refresh_token_t *gdpr_refresh_token);

gdpr_refresh_token_t *gdpr_refresh_token_parseFromJSON(cJSON *gdpr_refresh_tokenJSON);

cJSON *gdpr_refresh_token_convertToJSON(gdpr_refresh_token_t *gdpr_refresh_token);

#endif /* _gdpr_refresh_token_H_ */

