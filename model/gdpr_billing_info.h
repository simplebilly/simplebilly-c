/*
 * gdpr_billing_info.h
 *
 * 
 */

#ifndef _gdpr_billing_info_H_
#define _gdpr_billing_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gdpr_billing_info_t gdpr_billing_info_t;




typedef struct gdpr_billing_info_t {
    char *current_period_end; //date time
    char *current_period_start; //date time
    char *plan; // string
    char *status; // string
    char *tenant_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gdpr_billing_info_t;

__attribute__((deprecated)) gdpr_billing_info_t *gdpr_billing_info_create(
    char *current_period_end,
    char *current_period_start,
    char *plan,
    char *status,
    char *tenant_id
);

void gdpr_billing_info_free(gdpr_billing_info_t *gdpr_billing_info);

gdpr_billing_info_t *gdpr_billing_info_parseFromJSON(cJSON *gdpr_billing_infoJSON);

cJSON *gdpr_billing_info_convertToJSON(gdpr_billing_info_t *gdpr_billing_info);

#endif /* _gdpr_billing_info_H_ */

