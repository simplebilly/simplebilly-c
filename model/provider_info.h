/*
 * provider_info.h
 *
 * 
 */

#ifndef _provider_info_H_
#define _provider_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct provider_info_t provider_info_t;




typedef struct provider_info_t {
    char *display_name; // string
    char *name; // string
    int *requires_api_key; //boolean
    list_t *services; //primitive container
    int *supports_label_creation; //boolean
    int *supports_rate_estimation; //boolean
    int *supports_tracking; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} provider_info_t;

__attribute__((deprecated)) provider_info_t *provider_info_create(
    char *display_name,
    char *name,
    int *requires_api_key,
    list_t *services,
    int *supports_label_creation,
    int *supports_rate_estimation,
    int *supports_tracking
);

void provider_info_free(provider_info_t *provider_info);

provider_info_t *provider_info_parseFromJSON(cJSON *provider_infoJSON);

cJSON *provider_info_convertToJSON(provider_info_t *provider_info);

#endif /* _provider_info_H_ */

