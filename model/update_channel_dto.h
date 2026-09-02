/*
 * update_channel_dto.h
 *
 * 
 */

#ifndef _update_channel_dto_H_
#define _update_channel_dto_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_channel_dto_t update_channel_dto_t;

#include "any_type.h"



typedef struct update_channel_dto_t {
    any_type_t *config; // custom
    int *is_active; //boolean
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} update_channel_dto_t;

__attribute__((deprecated)) update_channel_dto_t *update_channel_dto_create(
    any_type_t *config,
    int *is_active,
    char *name
);

void update_channel_dto_free(update_channel_dto_t *update_channel_dto);

update_channel_dto_t *update_channel_dto_parseFromJSON(cJSON *update_channel_dtoJSON);

cJSON *update_channel_dto_convertToJSON(update_channel_dto_t *update_channel_dto);

#endif /* _update_channel_dto_H_ */

