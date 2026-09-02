/*
 * config_field_kind_one_of_1.h
 *
 * 
 */

#ifndef _config_field_kind_one_of_1_H_
#define _config_field_kind_one_of_1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct config_field_kind_one_of_1_t config_field_kind_one_of_1_t;


// Enum TYPE for config_field_kind_one_of_1

typedef enum  { simplebilly_api_config_field_kind_one_of_1_TYPE_NULL = 0, simplebilly_api_config_field_kind_one_of_1_TYPE_secret } simplebilly_api_config_field_kind_one_of_1_TYPE_e;

char* config_field_kind_one_of_1_type_ToString(simplebilly_api_config_field_kind_one_of_1_TYPE_e type);

simplebilly_api_config_field_kind_one_of_1_TYPE_e config_field_kind_one_of_1_type_FromString(char* type);



typedef struct config_field_kind_one_of_1_t {
    simplebilly_api_config_field_kind_one_of_1_TYPE_e type; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} config_field_kind_one_of_1_t;

__attribute__((deprecated)) config_field_kind_one_of_1_t *config_field_kind_one_of_1_create(
    simplebilly_api_config_field_kind_one_of_1_TYPE_e type
);

void config_field_kind_one_of_1_free(config_field_kind_one_of_1_t *config_field_kind_one_of_1);

config_field_kind_one_of_1_t *config_field_kind_one_of_1_parseFromJSON(cJSON *config_field_kind_one_of_1JSON);

cJSON *config_field_kind_one_of_1_convertToJSON(config_field_kind_one_of_1_t *config_field_kind_one_of_1);

#endif /* _config_field_kind_one_of_1_H_ */

