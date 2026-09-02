/*
 * model.h
 *
 * 
 */

#ifndef _model_H_
#define _model_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_t model_t;




typedef struct model_t {
    list_t *backup_codes; //primitive container
    char *created_at; //date time
    char *deleted_at; //date time
    char *email; // string
    int *email_verified; //boolean
    char *id; // string
    int *is_active; //boolean
    int *is_totp_enabled; //boolean
    char *last_login; //date time
    char *name; // string
    char *oauth_id; // string
    char *oauth_provider; // string
    char *password_changed_at; //date time
    char *password_hash; // string
    char *picture; // string
    char *privacy_accepted_at; //date time
    char *totp_secret; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} model_t;

__attribute__((deprecated)) model_t *model_create(
    list_t *backup_codes,
    char *created_at,
    char *deleted_at,
    char *email,
    int *email_verified,
    char *id,
    int *is_active,
    int *is_totp_enabled,
    char *last_login,
    char *name,
    char *oauth_id,
    char *oauth_provider,
    char *password_changed_at,
    char *password_hash,
    char *picture,
    char *privacy_accepted_at,
    char *totp_secret,
    char *updated_at
);

void model_free(model_t *model);

model_t *model_parseFromJSON(cJSON *modelJSON);

cJSON *model_convertToJSON(model_t *model);

#endif /* _model_H_ */

