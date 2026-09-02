/*
 * gdpr_notification.h
 *
 * 
 */

#ifndef _gdpr_notification_H_
#define _gdpr_notification_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gdpr_notification_t gdpr_notification_t;




typedef struct gdpr_notification_t {
    char *created_at; //date time
    char *id; // string
    int *is_read; //boolean
    char *message; // string
    char *tenant_id; // string
    char *title; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gdpr_notification_t;

__attribute__((deprecated)) gdpr_notification_t *gdpr_notification_create(
    char *created_at,
    char *id,
    int *is_read,
    char *message,
    char *tenant_id,
    char *title
);

void gdpr_notification_free(gdpr_notification_t *gdpr_notification);

gdpr_notification_t *gdpr_notification_parseFromJSON(cJSON *gdpr_notificationJSON);

cJSON *gdpr_notification_convertToJSON(gdpr_notification_t *gdpr_notification);

#endif /* _gdpr_notification_H_ */

