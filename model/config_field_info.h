/*
 * config_field_info.h
 *
 * Owned, API-safe copy of a [&#x60;ConfigField&#x60;] for DTOs / OpenAPI ([&#x60;ConfigField&#x60;] borrows &#x60;&amp;&#39;static str&#x60;, which cannot round-trip &#x60;Deserialize&#x60;).
 */

#ifndef _config_field_info_H_
#define _config_field_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct config_field_info_t config_field_info_t;

#include "config_field_kind.h"



typedef struct config_field_info_t {
    struct config_field_kind_t *kind; //model
    char *label; // string
    char *name; // string
    char *placeholder; // string
    int *required; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} config_field_info_t;

__attribute__((deprecated)) config_field_info_t *config_field_info_create(
    config_field_kind_t *kind,
    char *label,
    char *name,
    char *placeholder,
    int *required
);

void config_field_info_free(config_field_info_t *config_field_info);

config_field_info_t *config_field_info_parseFromJSON(cJSON *config_field_infoJSON);

cJSON *config_field_info_convertToJSON(config_field_info_t *config_field_info);

#endif /* _config_field_info_H_ */

