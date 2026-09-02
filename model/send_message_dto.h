/*
 * send_message_dto.h
 *
 * 
 */

#ifndef _send_message_dto_H_
#define _send_message_dto_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_message_dto_t send_message_dto_t;




typedef struct send_message_dto_t {
    char *body; // string
    int *is_internal; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} send_message_dto_t;

__attribute__((deprecated)) send_message_dto_t *send_message_dto_create(
    char *body,
    int *is_internal
);

void send_message_dto_free(send_message_dto_t *send_message_dto);

send_message_dto_t *send_message_dto_parseFromJSON(cJSON *send_message_dtoJSON);

cJSON *send_message_dto_convertToJSON(send_message_dto_t *send_message_dto);

#endif /* _send_message_dto_H_ */

