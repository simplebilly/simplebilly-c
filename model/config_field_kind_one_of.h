/*
 * config_field_kind_one_of.h
 *
 * 
 */

#ifndef _config_field_kind_one_of_H_
#define _config_field_kind_one_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct config_field_kind_one_of_t config_field_kind_one_of_t;


// Enum TYPE for config_field_kind_one_of

typedef enum  { simplebilly_api_config_field_kind_one_of_TYPE_NULL = 0, simplebilly_api_config_field_kind_one_of_TYPE_text } simplebilly_api_config_field_kind_one_of_TYPE_e;

char* config_field_kind_one_of_type_ToString(simplebilly_api_config_field_kind_one_of_TYPE_e type);

simplebilly_api_config_field_kind_one_of_TYPE_e config_field_kind_one_of_type_FromString(char* type);



typedef struct config_field_kind_one_of_t {
    simplebilly_api_config_field_kind_one_of_TYPE_e type; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} config_field_kind_one_of_t;

__attribute__((deprecated)) config_field_kind_one_of_t *config_field_kind_one_of_create(
    simplebilly_api_config_field_kind_one_of_TYPE_e type
);

void config_field_kind_one_of_free(config_field_kind_one_of_t *config_field_kind_one_of);

config_field_kind_one_of_t *config_field_kind_one_of_parseFromJSON(cJSON *config_field_kind_one_ofJSON);

cJSON *config_field_kind_one_of_convertToJSON(config_field_kind_one_of_t *config_field_kind_one_of);

#endif /* _config_field_kind_one_of_H_ */

