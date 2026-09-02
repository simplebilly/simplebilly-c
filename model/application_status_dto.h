/*
 * application_status_dto.h
 *
 * 
 */

#ifndef _application_status_dto_H_
#define _application_status_dto_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct application_status_dto_t application_status_dto_t;




typedef struct application_status_dto_t {
    char *posting_id; // string
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} application_status_dto_t;

__attribute__((deprecated)) application_status_dto_t *application_status_dto_create(
    char *posting_id,
    char *status
);

void application_status_dto_free(application_status_dto_t *application_status_dto);

application_status_dto_t *application_status_dto_parseFromJSON(cJSON *application_status_dtoJSON);

cJSON *application_status_dto_convertToJSON(application_status_dto_t *application_status_dto);

#endif /* _application_status_dto_H_ */

