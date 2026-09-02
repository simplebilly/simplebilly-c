/*
 * config_field_kind_one_of_3.h
 *
 * 
 */

#ifndef _config_field_kind_one_of_3_H_
#define _config_field_kind_one_of_3_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct config_field_kind_one_of_3_t config_field_kind_one_of_3_t;


// Enum TYPE for config_field_kind_one_of_3

typedef enum  { simplebilly_api_config_field_kind_one_of_3_TYPE_NULL = 0, simplebilly_api_config_field_kind_one_of_3_TYPE_select } simplebilly_api_config_field_kind_one_of_3_TYPE_e;

char* config_field_kind_one_of_3_type_ToString(simplebilly_api_config_field_kind_one_of_3_TYPE_e type);

simplebilly_api_config_field_kind_one_of_3_TYPE_e config_field_kind_one_of_3_type_FromString(char* type);



typedef struct config_field_kind_one_of_3_t {
    list_t *options; //primitive container
    simplebilly_api_config_field_kind_one_of_3_TYPE_e type; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} config_field_kind_one_of_3_t;

__attribute__((deprecated)) config_field_kind_one_of_3_t *config_field_kind_one_of_3_create(
    list_t *options,
    simplebilly_api_config_field_kind_one_of_3_TYPE_e type
);

void config_field_kind_one_of_3_free(config_field_kind_one_of_3_t *config_field_kind_one_of_3);

config_field_kind_one_of_3_t *config_field_kind_one_of_3_parseFromJSON(cJSON *config_field_kind_one_of_3JSON);

cJSON *config_field_kind_one_of_3_convertToJSON(config_field_kind_one_of_3_t *config_field_kind_one_of_3);

#endif /* _config_field_kind_one_of_3_H_ */

