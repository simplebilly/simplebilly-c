/*
 * api_response_gdpr_export_data.h
 *
 * 
 */

#ifndef _api_response_gdpr_export_data_H_
#define _api_response_gdpr_export_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_response_gdpr_export_data_t api_response_gdpr_export_data_t;

#include "gdpr_activity.h"
#include "gdpr_api_key.h"
#include "gdpr_billing_info.h"
#include "gdpr_notification.h"
#include "gdpr_refresh_token.h"
#include "gdpr_tenant.h"
#include "gdpr_usage_event.h"
#include "gdpr_user.h"



typedef struct api_response_gdpr_export_data_t {
    list_t *activity_log; //nonprimitive container
    list_t *api_keys; //nonprimitive container
    list_t *billing; //nonprimitive container
    char *exported_at; //date time
    int *generated_by_ai; //boolean
    list_t *notifications; //nonprimitive container
    list_t *refresh_tokens; //nonprimitive container
    list_t *tenants; //nonprimitive container
    list_t *usage_events; //nonprimitive container
    struct gdpr_user_t *user; //model

    int _library_owned; // Is the library responsible for freeing this object?
} api_response_gdpr_export_data_t;

__attribute__((deprecated)) api_response_gdpr_export_data_t *api_response_gdpr_export_data_create(
    list_t *activity_log,
    list_t *api_keys,
    list_t *billing,
    char *exported_at,
    int *generated_by_ai,
    list_t *notifications,
    list_t *refresh_tokens,
    list_t *tenants,
    list_t *usage_events,
    gdpr_user_t *user
);

void api_response_gdpr_export_data_free(api_response_gdpr_export_data_t *api_response_gdpr_export_data);

api_response_gdpr_export_data_t *api_response_gdpr_export_data_parseFromJSON(cJSON *api_response_gdpr_export_dataJSON);

cJSON *api_response_gdpr_export_data_convertToJSON(api_response_gdpr_export_data_t *api_response_gdpr_export_data);

#endif /* _api_response_gdpr_export_data_H_ */

