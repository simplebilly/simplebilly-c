/*
 * time_entry_dto.h
 *
 * API shape returned to the frontend (matches &#x60;frontend/src/types/time-entry.ts&#x60;).
 */

#ifndef _time_entry_dto_H_
#define _time_entry_dto_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct time_entry_dto_t time_entry_dto_t;




typedef struct time_entry_dto_t {
    char *clock_in; //date time
    char *clock_out; //date time
    char *created_at; //date time
    char *date; //date
    char *employee_id; // string
    char *hours; // string
    char *notes; // string
    char *time_entry_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} time_entry_dto_t;

__attribute__((deprecated)) time_entry_dto_t *time_entry_dto_create(
    char *clock_in,
    char *clock_out,
    char *created_at,
    char *date,
    char *employee_id,
    char *hours,
    char *notes,
    char *time_entry_id
);

void time_entry_dto_free(time_entry_dto_t *time_entry_dto);

time_entry_dto_t *time_entry_dto_parseFromJSON(cJSON *time_entry_dtoJSON);

cJSON *time_entry_dto_convertToJSON(time_entry_dto_t *time_entry_dto);

#endif /* _time_entry_dto_H_ */

