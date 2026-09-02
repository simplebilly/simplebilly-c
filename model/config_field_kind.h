/*
 * config_field_kind.h
 *
 * 
 */

#ifndef _config_field_kind_H_
#define _config_field_kind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct config_field_kind_t config_field_kind_t;

#include "config_field_kind_one_of.h"
#include "config_field_kind_one_of_1.h"
#include "config_field_kind_one_of_2.h"
#include "config_field_kind_one_of_3.h"
#include "config_field_kind_one_of_4.h"

// Enum TYPE for config_field_kind

typedef enum  { simplebilly_api_config_field_kind_TYPE_NULL = 0, simplebilly_api_config_field_kind_TYPE_text, simplebilly_api_config_field_kind_TYPE_secret, simplebilly_api_config_field_kind_TYPE_url, simplebilly_api_config_field_kind_TYPE_select, simplebilly_api_config_field_kind_TYPE__bool } simplebilly_api_config_field_kind_TYPE_e;

char* config_field_kind_type_ToString(simplebilly_api_config_field_kind_TYPE_e type);

simplebilly_api_config_field_kind_TYPE_e config_field_kind_type_FromString(char* type);



typedef struct config_field_kind_t {
    simplebilly_api_config_field_kind_TYPE_e type; //enum
    list_t *options; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} config_field_kind_t;

__attribute__((deprecated)) config_field_kind_t *config_field_kind_create(
    simplebilly_api_config_field_kind_TYPE_e type,
    list_t *options
);

void config_field_kind_free(config_field_kind_t *config_field_kind);

config_field_kind_t *config_field_kind_parseFromJSON(cJSON *config_field_kindJSON);

cJSON *config_field_kind_convertToJSON(config_field_kind_t *config_field_kind);

#endif /* _config_field_kind_H_ */

