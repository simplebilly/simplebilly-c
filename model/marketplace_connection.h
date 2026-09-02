/*
 * marketplace_connection.h
 *
 * 
 */

#ifndef _marketplace_connection_H_
#define _marketplace_connection_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct marketplace_connection_t marketplace_connection_t;

#include "any_type.h"
#include "connector_type.h"



typedef struct marketplace_connection_t {
    any_type_t *config; // custom
    char *connection_id; // string
    simplebilly_api_connector_type__e connector_type; //referenced enum
    char *created_at; //date time
    int *is_active; //boolean
    char *label; // string
    char *last_sync_at; //date time
    char *platform; // string
    char *platform_user_id; // string
    char *scopes; // string
    char *shop_domain; // string
    char *shop_name; // string
    char *sync_status; // string
    char *tenant_id; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} marketplace_connection_t;

__attribute__((deprecated)) marketplace_connection_t *marketplace_connection_create(
    any_type_t *config,
    char *connection_id,
    simplebilly_api_connector_type__e connector_type,
    char *created_at,
    int *is_active,
    char *label,
    char *last_sync_at,
    char *platform,
    char *platform_user_id,
    char *scopes,
    char *shop_domain,
    char *shop_name,
    char *sync_status,
    char *tenant_id,
    char *updated_at
);

void marketplace_connection_free(marketplace_connection_t *marketplace_connection);

marketplace_connection_t *marketplace_connection_parseFromJSON(cJSON *marketplace_connectionJSON);

cJSON *marketplace_connection_convertToJSON(marketplace_connection_t *marketplace_connection);

#endif /* _marketplace_connection_H_ */

