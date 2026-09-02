/*
 * plausibility_summary.h
 *
 * 
 */

#ifndef _plausibility_summary_H_
#define _plausibility_summary_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plausibility_summary_t plausibility_summary_t;

#include "check_status.h"



typedef struct plausibility_summary_t {
    int *errors; //numeric
    simplebilly_api_check_status__e overall_status; //referenced enum
    int *passed; //numeric
    int *total_checks; //numeric
    int *warnings; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} plausibility_summary_t;

__attribute__((deprecated)) plausibility_summary_t *plausibility_summary_create(
    int *errors,
    simplebilly_api_check_status__e overall_status,
    int *passed,
    int *total_checks,
    int *warnings
);

void plausibility_summary_free(plausibility_summary_t *plausibility_summary);

plausibility_summary_t *plausibility_summary_parseFromJSON(cJSON *plausibility_summaryJSON);

cJSON *plausibility_summary_convertToJSON(plausibility_summary_t *plausibility_summary);

#endif /* _plausibility_summary_H_ */

