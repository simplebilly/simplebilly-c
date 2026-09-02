/*
 * kyc_record_create.h
 *
 * 
 */

#ifndef _kyc_record_create_H_
#define _kyc_record_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct kyc_record_create_t kyc_record_create_t;




typedef struct kyc_record_create_t {
    char *customer_id; // string
    char *customer_name; // string
    char *kyc_date; //date
    char *notes; // string
    char *retention_until; //date
    char *risk_assessment; // string

    int _library_owned; // Is the library responsible for freeing this object?
} kyc_record_create_t;

__attribute__((deprecated)) kyc_record_create_t *kyc_record_create_create(
    char *customer_id,
    char *customer_name,
    char *kyc_date,
    char *notes,
    char *retention_until,
    char *risk_assessment
);

void kyc_record_create_free(kyc_record_create_t *kyc_record_create);

kyc_record_create_t *kyc_record_create_parseFromJSON(cJSON *kyc_record_createJSON);

cJSON *kyc_record_create_convertToJSON(kyc_record_create_t *kyc_record_create);

#endif /* _kyc_record_create_H_ */

