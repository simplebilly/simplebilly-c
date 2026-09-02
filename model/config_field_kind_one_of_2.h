/*
 * config_field_kind_one_of_2.h
 *
 * 
 */

#ifndef _config_field_kind_one_of_2_H_
#define _config_field_kind_one_of_2_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct config_field_kind_one_of_2_t config_field_kind_one_of_2_t;


// Enum TYPE for config_field_kind_one_of_2

typedef enum  { simplebilly_api_config_field_kind_one_of_2_TYPE_NULL = 0, simplebilly_api_config_field_kind_one_of_2_TYPE_url } simplebilly_api_config_field_kind_one_of_2_TYPE_e;

char* config_field_kind_one_of_2_type_ToString(simplebilly_api_config_field_kind_one_of_2_TYPE_e type);

simplebilly_api_config_field_kind_one_of_2_TYPE_e config_field_kind_one_of_2_type_FromString(char* type);



typedef struct config_field_kind_one_of_2_t {
    simplebilly_api_config_field_kind_one_of_2_TYPE_e type; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} config_field_kind_one_of_2_t;

__attribute__((deprecated)) config_field_kind_one_of_2_t *config_field_kind_one_of_2_create(
    simplebilly_api_config_field_kind_one_of_2_TYPE_e type
);

void config_field_kind_one_of_2_free(config_field_kind_one_of_2_t *config_field_kind_one_of_2);

config_field_kind_one_of_2_t *config_field_kind_one_of_2_parseFromJSON(cJSON *config_field_kind_one_of_2JSON);

cJSON *config_field_kind_one_of_2_convertToJSON(config_field_kind_one_of_2_t *config_field_kind_one_of_2);

#endif /* _config_field_kind_one_of_2_H_ */

