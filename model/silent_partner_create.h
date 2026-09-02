/*
 * silent_partner_create.h
 *
 * 
 */

#ifndef _silent_partner_create_H_
#define _silent_partner_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct silent_partner_create_t silent_partner_create_t;

#include "instrument_type.h"



typedef struct silent_partner_create_t {
    char *contract_date; //date
    char *einlage; // string
    char *gewinnquote_pct; // string
    char *gewinnvortrag; // string
    instrument_type_t *instrument_type; // custom
    int *kest_pflichtig; //boolean
    char *name; // string
    char *notes; // string
    char *verlust_verrechnungskonto; // string
    int *verlustbeteiligung; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} silent_partner_create_t;

__attribute__((deprecated)) silent_partner_create_t *silent_partner_create_create(
    char *contract_date,
    char *einlage,
    char *gewinnquote_pct,
    char *gewinnvortrag,
    instrument_type_t *instrument_type,
    int *kest_pflichtig,
    char *name,
    char *notes,
    char *verlust_verrechnungskonto,
    int *verlustbeteiligung
);

void silent_partner_create_free(silent_partner_create_t *silent_partner_create);

silent_partner_create_t *silent_partner_create_parseFromJSON(cJSON *silent_partner_createJSON);

cJSON *silent_partner_create_convertToJSON(silent_partner_create_t *silent_partner_create);

#endif /* _silent_partner_create_H_ */

