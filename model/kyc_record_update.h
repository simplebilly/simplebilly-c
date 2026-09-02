/*
 * kyc_record_update.h
 *
 * 
 */

#ifndef _kyc_record_update_H_
#define _kyc_record_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct kyc_record_update_t kyc_record_update_t;




typedef struct kyc_record_update_t {
    char *customer_id; // string
    char *customer_name; // string
    char *kyc_date; //date
    char *notes; // string
    char *retention_until; //date
    char *risk_assessment; // string

    int _library_owned; // Is the library responsible for freeing this object?
} kyc_record_update_t;

__attribute__((deprecated)) kyc_record_update_t *kyc_record_update_create(
    char *customer_id,
    char *customer_name,
    char *kyc_date,
    char *notes,
    char *retention_until,
    char *risk_assessment
);

void kyc_record_update_free(kyc_record_update_t *kyc_record_update);

kyc_record_update_t *kyc_record_update_parseFromJSON(cJSON *kyc_record_updateJSON);

cJSON *kyc_record_update_convertToJSON(kyc_record_update_t *kyc_record_update);

#endif /* _kyc_record_update_H_ */

