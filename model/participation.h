/*
 * participation.h
 *
 * 
 */

#ifndef _participation_H_
#define _participation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct participation_t participation_t;




typedef struct participation_t {
    char *acquired_at; //date
    int *board_appointment; //boolean
    char *company_name; // string
    int *control_agreement; //boolean
    char *legal_form; // string
    char *ownership_pct; // string
    int *purpose_vehicle; //boolean
    int *voting_majority; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} participation_t;

__attribute__((deprecated)) participation_t *participation_create(
    char *acquired_at,
    int *board_appointment,
    char *company_name,
    int *control_agreement,
    char *legal_form,
    char *ownership_pct,
    int *purpose_vehicle,
    int *voting_majority
);

void participation_free(participation_t *participation);

participation_t *participation_parseFromJSON(cJSON *participationJSON);

cJSON *participation_convertToJSON(participation_t *participation);

#endif /* _participation_H_ */

