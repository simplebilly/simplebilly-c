/*
 * shipping_credentials.h
 *
 * Per-tenant credentials for real shipping provider APIs (stored in the &#x60;shipping&#x60; key of the settings JSON blob). Auth is either OAuth client credentials (UPS) or a user-supplied API key (DHL).
 */

#ifndef _shipping_credentials_H_
#define _shipping_credentials_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shipping_credentials_t shipping_credentials_t;

#include "dhl_credentials.h"
#include "ups_credentials.h"



typedef struct shipping_credentials_t {
    struct dhl_credentials_t *dhl; //model
    struct ups_credentials_t *ups; //model

    int _library_owned; // Is the library responsible for freeing this object?
} shipping_credentials_t;

__attribute__((deprecated)) shipping_credentials_t *shipping_credentials_create(
    dhl_credentials_t *dhl,
    ups_credentials_t *ups
);

void shipping_credentials_free(shipping_credentials_t *shipping_credentials);

shipping_credentials_t *shipping_credentials_parseFromJSON(cJSON *shipping_credentialsJSON);

cJSON *shipping_credentials_convertToJSON(shipping_credentials_t *shipping_credentials);

#endif /* _shipping_credentials_H_ */

