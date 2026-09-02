/*
 * smtp_config.h
 *
 * 
 */

#ifndef _smtp_config_H_
#define _smtp_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct smtp_config_t smtp_config_t;

#include "smtp_encryption.h"



typedef struct smtp_config_t {
    simplebilly_api_smtp_encryption__e encryption; //referenced enum
    char *from_address; // string
    char *from_name; // string
    char *host; // string
    char *password; // string
    int *port; //numeric
    long *timeout_seconds; //numeric
    char *username; // string

    int _library_owned; // Is the library responsible for freeing this object?
} smtp_config_t;

__attribute__((deprecated)) smtp_config_t *smtp_config_create(
    simplebilly_api_smtp_encryption__e encryption,
    char *from_address,
    char *from_name,
    char *host,
    char *password,
    int *port,
    long *timeout_seconds,
    char *username
);

void smtp_config_free(smtp_config_t *smtp_config);

smtp_config_t *smtp_config_parseFromJSON(cJSON *smtp_configJSON);

cJSON *smtp_config_convertToJSON(smtp_config_t *smtp_config);

#endif /* _smtp_config_H_ */

