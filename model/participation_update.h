/*
 * participation_update.h
 *
 * 
 */

#ifndef _participation_update_H_
#define _participation_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct participation_update_t participation_update_t;




typedef struct participation_update_t {
    char *acquired_at; //date
    int *board_appointment; //boolean
    char *company_name; // string
    int *control_agreement; //boolean
    char *legal_form; // string
    char *ownership_pct; // string
    int *purpose_vehicle; //boolean
    int *voting_majority; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} participation_update_t;

__attribute__((deprecated)) participation_update_t *participation_update_create(
    char *acquired_at,
    int *board_appointment,
    char *company_name,
    int *control_agreement,
    char *legal_form,
    char *ownership_pct,
    int *purpose_vehicle,
    int *voting_majority
);

void participation_update_free(participation_update_t *participation_update);

participation_update_t *participation_update_parseFromJSON(cJSON *participation_updateJSON);

cJSON *participation_update_convertToJSON(participation_update_t *participation_update);

#endif /* _participation_update_H_ */

