/*
 * api_response_user_profile_data.h
 *
 * 
 */

#ifndef _api_response_user_profile_data_H_
#define _api_response_user_profile_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_response_user_profile_data_t api_response_user_profile_data_t;




typedef struct api_response_user_profile_data_t {
    char *created_at; //date time
    char *email; // string
    int *email_verified; //boolean
    char *first_name; // string
    char *full_name; // string
    char *id; // string
    char *last_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} api_response_user_profile_data_t;

__attribute__((deprecated)) api_response_user_profile_data_t *api_response_user_profile_data_create(
    char *created_at,
    char *email,
    int *email_verified,
    char *first_name,
    char *full_name,
    char *id,
    char *last_name
);

void api_response_user_profile_data_free(api_response_user_profile_data_t *api_response_user_profile_data);

api_response_user_profile_data_t *api_response_user_profile_data_parseFromJSON(cJSON *api_response_user_profile_dataJSON);

cJSON *api_response_user_profile_data_convertToJSON(api_response_user_profile_data_t *api_response_user_profile_data);

#endif /* _api_response_user_profile_data_H_ */

