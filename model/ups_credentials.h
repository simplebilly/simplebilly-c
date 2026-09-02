/*
 * ups_credentials.h
 *
 * 
 */

#ifndef _ups_credentials_H_
#define _ups_credentials_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ups_credentials_t ups_credentials_t;




typedef struct ups_credentials_t {
    char *client_id; // string
    char *client_secret; // string
    char *shipper_number; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ups_credentials_t;

__attribute__((deprecated)) ups_credentials_t *ups_credentials_create(
    char *client_id,
    char *client_secret,
    char *shipper_number
);

void ups_credentials_free(ups_credentials_t *ups_credentials);

ups_credentials_t *ups_credentials_parseFromJSON(cJSON *ups_credentialsJSON);

cJSON *ups_credentials_convertToJSON(ups_credentials_t *ups_credentials);

#endif /* _ups_credentials_H_ */

