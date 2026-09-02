/*
 * email_template_create.h
 *
 * 
 */

#ifndef _email_template_create_H_
#define _email_template_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct email_template_create_t email_template_create_t;

#include "any_type.h"
#include "email_template_status.h"



typedef struct email_template_create_t {
    char *body; // string
    char *name; // string
    email_template_status_t *status; // custom
    char *subject; // string
    any_type_t *variables; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} email_template_create_t;

__attribute__((deprecated)) email_template_create_t *email_template_create_create(
    char *body,
    char *name,
    email_template_status_t *status,
    char *subject,
    any_type_t *variables
);

void email_template_create_free(email_template_create_t *email_template_create);

email_template_create_t *email_template_create_parseFromJSON(cJSON *email_template_createJSON);

cJSON *email_template_create_convertToJSON(email_template_create_t *email_template_create);

#endif /* _email_template_create_H_ */

