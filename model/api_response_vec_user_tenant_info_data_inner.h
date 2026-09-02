/*
 * api_response_vec_user_tenant_info_data_inner.h
 *
 * 
 */

#ifndef _api_response_vec_user_tenant_info_data_inner_H_
#define _api_response_vec_user_tenant_info_data_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_response_vec_user_tenant_info_data_inner_t api_response_vec_user_tenant_info_data_inner_t;




typedef struct api_response_vec_user_tenant_info_data_inner_t {
    char *custom_domain; // string
    char *role; // string
    char *subdomain; // string
    char *tenant_id; // string
    char *tenant_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} api_response_vec_user_tenant_info_data_inner_t;

__attribute__((deprecated)) api_response_vec_user_tenant_info_data_inner_t *api_response_vec_user_tenant_info_data_inner_create(
    char *custom_domain,
    char *role,
    char *subdomain,
    char *tenant_id,
    char *tenant_name
);

void api_response_vec_user_tenant_info_data_inner_free(api_response_vec_user_tenant_info_data_inner_t *api_response_vec_user_tenant_info_data_inner);

api_response_vec_user_tenant_info_data_inner_t *api_response_vec_user_tenant_info_data_inner_parseFromJSON(cJSON *api_response_vec_user_tenant_info_data_innerJSON);

cJSON *api_response_vec_user_tenant_info_data_inner_convertToJSON(api_response_vec_user_tenant_info_data_inner_t *api_response_vec_user_tenant_info_data_inner);

#endif /* _api_response_vec_user_tenant_info_data_inner_H_ */

