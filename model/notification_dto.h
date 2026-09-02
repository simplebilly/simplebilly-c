/*
 * notification_dto.h
 *
 * Wire shape of a notification row (mirrors frontend Notification type).
 */

#ifndef _notification_dto_H_
#define _notification_dto_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct notification_dto_t notification_dto_t;




typedef struct notification_dto_t {
    char *created_at; //date time
    char *id; // string
    int *is_read; //boolean
    char *message; // string
    int *sent_via_email; //boolean
    char *tenant_id; // string
    char *title; // string
    char *user_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} notification_dto_t;

__attribute__((deprecated)) notification_dto_t *notification_dto_create(
    char *created_at,
    char *id,
    int *is_read,
    char *message,
    int *sent_via_email,
    char *tenant_id,
    char *title,
    char *user_id
);

void notification_dto_free(notification_dto_t *notification_dto);

notification_dto_t *notification_dto_parseFromJSON(cJSON *notification_dtoJSON);

cJSON *notification_dto_convertToJSON(notification_dto_t *notification_dto);

#endif /* _notification_dto_H_ */

