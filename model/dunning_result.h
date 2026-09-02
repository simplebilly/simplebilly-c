/*
 * dunning_result.h
 *
 * 
 */

#ifndef _dunning_result_H_
#define _dunning_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct dunning_result_t dunning_result_t;




typedef struct dunning_result_t {
    int *invoices_processed; //numeric
    char *message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} dunning_result_t;

__attribute__((deprecated)) dunning_result_t *dunning_result_create(
    int *invoices_processed,
    char *message
);

void dunning_result_free(dunning_result_t *dunning_result);

dunning_result_t *dunning_result_parseFromJSON(cJSON *dunning_resultJSON);

cJSON *dunning_result_convertToJSON(dunning_result_t *dunning_result);

#endif /* _dunning_result_H_ */

