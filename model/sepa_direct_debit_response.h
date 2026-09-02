/*
 * sepa_direct_debit_response.h
 *
 * 
 */

#ifndef _sepa_direct_debit_response_H_
#define _sepa_direct_debit_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sepa_direct_debit_response_t sepa_direct_debit_response_t;




typedef struct sepa_direct_debit_response_t {
    char *content_type; // string
    char *filename; // string
    char *xml_content; // string

    int _library_owned; // Is the library responsible for freeing this object?
} sepa_direct_debit_response_t;

__attribute__((deprecated)) sepa_direct_debit_response_t *sepa_direct_debit_response_create(
    char *content_type,
    char *filename,
    char *xml_content
);

void sepa_direct_debit_response_free(sepa_direct_debit_response_t *sepa_direct_debit_response);

sepa_direct_debit_response_t *sepa_direct_debit_response_parseFromJSON(cJSON *sepa_direct_debit_responseJSON);

cJSON *sepa_direct_debit_response_convertToJSON(sepa_direct_debit_response_t *sepa_direct_debit_response);

#endif /* _sepa_direct_debit_response_H_ */

