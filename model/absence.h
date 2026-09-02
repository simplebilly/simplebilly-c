/*
 * absence.h
 *
 * 
 */

#ifndef _absence_H_
#define _absence_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct absence_t absence_t;

#include "absence_status.h"
#include "absence_type.h"



typedef struct absence_t {
    absence_type_t *absence_type; // custom
    char *approved_at; //date time
    char *approved_by; // string
    char *created_at; //date time
    char *deleted_at; //date time
    char *employee_id; // string
    char *end_date; //date
    char *id; // string
    char *notes; // string
    char *start_date; //date
    absence_status_t *status; // custom
    char *tenant_id; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} absence_t;

__attribute__((deprecated)) absence_t *absence_create(
    absence_type_t *absence_type,
    char *approved_at,
    char *approved_by,
    char *created_at,
    char *deleted_at,
    char *employee_id,
    char *end_date,
    char *id,
    char *notes,
    char *start_date,
    absence_status_t *status,
    char *tenant_id,
    char *updated_at
);

void absence_free(absence_t *absence);

absence_t *absence_parseFromJSON(cJSON *absenceJSON);

cJSON *absence_convertToJSON(absence_t *absence);

#endif /* _absence_H_ */

