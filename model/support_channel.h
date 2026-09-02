/*
 * support_channel.h
 *
 * 
 */

#ifndef _support_channel_H_
#define _support_channel_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct support_channel_t support_channel_t;

#include "any_type.h"
#include "support_channel_type.h"



typedef struct support_channel_t {
    simplebilly_api_support_channel_type__e channel_type; //referenced enum
    any_type_t *config; // custom
    char *created_at; //date time
    int *is_active; //boolean
    char *name; // string
    char *tenant_id; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} support_channel_t;

__attribute__((deprecated)) support_channel_t *support_channel_create(
    simplebilly_api_support_channel_type__e channel_type,
    any_type_t *config,
    char *created_at,
    int *is_active,
    char *name,
    char *tenant_id,
    char *updated_at
);

void support_channel_free(support_channel_t *support_channel);

support_channel_t *support_channel_parseFromJSON(cJSON *support_channelJSON);

cJSON *support_channel_convertToJSON(support_channel_t *support_channel);

#endif /* _support_channel_H_ */

