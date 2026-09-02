/*
 * create_channel_dto.h
 *
 * 
 */

#ifndef _create_channel_dto_H_
#define _create_channel_dto_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_channel_dto_t create_channel_dto_t;

#include "any_type.h"



typedef struct create_channel_dto_t {
    char *channel_type; // string
    any_type_t *config; // custom
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_channel_dto_t;

__attribute__((deprecated)) create_channel_dto_t *create_channel_dto_create(
    char *channel_type,
    any_type_t *config,
    char *name
);

void create_channel_dto_free(create_channel_dto_t *create_channel_dto);

create_channel_dto_t *create_channel_dto_parseFromJSON(cJSON *create_channel_dtoJSON);

cJSON *create_channel_dto_convertToJSON(create_channel_dto_t *create_channel_dto);

#endif /* _create_channel_dto_H_ */

