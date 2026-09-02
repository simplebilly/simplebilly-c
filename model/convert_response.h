/*
 * convert_response.h
 *
 * Response of the proforma → invoice conversion.
 */

#ifndef _convert_response_H_
#define _convert_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct convert_response_t convert_response_t;




typedef struct convert_response_t {
    char *invoice_id; // string
    char *invoice_number; // string
    char *proforma_id; // string
    char *proforma_number; // string

    int _library_owned; // Is the library responsible for freeing this object?
} convert_response_t;

__attribute__((deprecated)) convert_response_t *convert_response_create(
    char *invoice_id,
    char *invoice_number,
    char *proforma_id,
    char *proforma_number
);

void convert_response_free(convert_response_t *convert_response);

convert_response_t *convert_response_parseFromJSON(cJSON *convert_responseJSON);

cJSON *convert_response_convertToJSON(convert_response_t *convert_response);

#endif /* _convert_response_H_ */

