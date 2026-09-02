/*
 * absence_create.h
 *
 * 
 */

#ifndef _absence_create_H_
#define _absence_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct absence_create_t absence_create_t;

#include "absence_status.h"
#include "absence_type.h"



typedef struct absence_create_t {
    absence_type_t *absence_type; // custom
    char *approved_at; //date time
    char *approved_by; // string
    char *employee_id; // string
    char *end_date; //date
    char *notes; // string
    char *start_date; //date
    absence_status_t *status; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} absence_create_t;

__attribute__((deprecated)) absence_create_t *absence_create_create(
    absence_type_t *absence_type,
    char *approved_at,
    char *approved_by,
    char *employee_id,
    char *end_date,
    char *notes,
    char *start_date,
    absence_status_t *status
);

void absence_create_free(absence_create_t *absence_create);

absence_create_t *absence_create_parseFromJSON(cJSON *absence_createJSON);

cJSON *absence_create_convertToJSON(absence_create_t *absence_create);

#endif /* _absence_create_H_ */

