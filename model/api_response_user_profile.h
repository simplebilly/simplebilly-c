/*
 * api_response_user_profile.h
 *
 * 
 */

#ifndef _api_response_user_profile_H_
#define _api_response_user_profile_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_response_user_profile_t api_response_user_profile_t;

#include "api_response_user_profile_data.h"



typedef struct api_response_user_profile_t {
    struct api_response_user_profile_data_t *data; //model
    char *error; // string
    char *message; // string
    int *success; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} api_response_user_profile_t;

__attribute__((deprecated)) api_response_user_profile_t *api_response_user_profile_create(
    api_response_user_profile_data_t *data,
    char *error,
    char *message,
    int *success
);

void api_response_user_profile_free(api_response_user_profile_t *api_response_user_profile);

api_response_user_profile_t *api_response_user_profile_parseFromJSON(cJSON *api_response_user_profileJSON);

cJSON *api_response_user_profile_convertToJSON(api_response_user_profile_t *api_response_user_profile);

#endif /* _api_response_user_profile_H_ */

