/*
 * participation_create.h
 *
 * 
 */

#ifndef _participation_create_H_
#define _participation_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct participation_create_t participation_create_t;




typedef struct participation_create_t {
    char *acquired_at; //date
    int *board_appointment; //boolean
    char *company_name; // string
    int *control_agreement; //boolean
    char *legal_form; // string
    char *ownership_pct; // string
    int *purpose_vehicle; //boolean
    int *voting_majority; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} participation_create_t;

__attribute__((deprecated)) participation_create_t *participation_create_create(
    char *acquired_at,
    int *board_appointment,
    char *company_name,
    int *control_agreement,
    char *legal_form,
    char *ownership_pct,
    int *purpose_vehicle,
    int *voting_majority
);

void participation_create_free(participation_create_t *participation_create);

participation_create_t *participation_create_parseFromJSON(cJSON *participation_createJSON);

cJSON *participation_create_convertToJSON(participation_create_t *participation_create);

#endif /* _participation_create_H_ */

