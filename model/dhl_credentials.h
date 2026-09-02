/*
 * dhl_credentials.h
 *
 * 
 */

#ifndef _dhl_credentials_H_
#define _dhl_credentials_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct dhl_credentials_t dhl_credentials_t;




typedef struct dhl_credentials_t {
    char *api_key; // string
    char *client_id; // string
    char *client_secret; // string

    int _library_owned; // Is the library responsible for freeing this object?
} dhl_credentials_t;

__attribute__((deprecated)) dhl_credentials_t *dhl_credentials_create(
    char *api_key,
    char *client_id,
    char *client_secret
);

void dhl_credentials_free(dhl_credentials_t *dhl_credentials);

dhl_credentials_t *dhl_credentials_parseFromJSON(cJSON *dhl_credentialsJSON);

cJSON *dhl_credentials_convertToJSON(dhl_credentials_t *dhl_credentials);

#endif /* _dhl_credentials_H_ */

