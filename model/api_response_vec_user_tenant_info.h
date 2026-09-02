/*
 * api_response_vec_user_tenant_info.h
 *
 * 
 */

#ifndef _api_response_vec_user_tenant_info_H_
#define _api_response_vec_user_tenant_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_response_vec_user_tenant_info_t api_response_vec_user_tenant_info_t;

#include "api_response_vec_user_tenant_info_data_inner.h"



typedef struct api_response_vec_user_tenant_info_t {
    list_t *data; //nonprimitive container
    char *error; // string
    char *message; // string
    int *success; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} api_response_vec_user_tenant_info_t;

__attribute__((deprecated)) api_response_vec_user_tenant_info_t *api_response_vec_user_tenant_info_create(
    list_t *data,
    char *error,
    char *message,
    int *success
);

void api_response_vec_user_tenant_info_free(api_response_vec_user_tenant_info_t *api_response_vec_user_tenant_info);

api_response_vec_user_tenant_info_t *api_response_vec_user_tenant_info_parseFromJSON(cJSON *api_response_vec_user_tenant_infoJSON);

cJSON *api_response_vec_user_tenant_info_convertToJSON(api_response_vec_user_tenant_info_t *api_response_vec_user_tenant_info);

#endif /* _api_response_vec_user_tenant_info_H_ */

