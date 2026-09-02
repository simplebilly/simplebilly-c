/*
 * api_response_subscription_overview.h
 *
 * 
 */

#ifndef _api_response_subscription_overview_H_
#define _api_response_subscription_overview_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_response_subscription_overview_t api_response_subscription_overview_t;

#include "api_response_subscription_overview_data.h"



typedef struct api_response_subscription_overview_t {
    struct api_response_subscription_overview_data_t *data; //model
    char *error; // string
    char *message; // string
    int *success; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} api_response_subscription_overview_t;

__attribute__((deprecated)) api_response_subscription_overview_t *api_response_subscription_overview_create(
    api_response_subscription_overview_data_t *data,
    char *error,
    char *message,
    int *success
);

void api_response_subscription_overview_free(api_response_subscription_overview_t *api_response_subscription_overview);

api_response_subscription_overview_t *api_response_subscription_overview_parseFromJSON(cJSON *api_response_subscription_overviewJSON);

cJSON *api_response_subscription_overview_convertToJSON(api_response_subscription_overview_t *api_response_subscription_overview);

#endif /* _api_response_subscription_overview_H_ */

