/*
 * plausibility_report.h
 *
 * 
 */

#ifndef _plausibility_report_H_
#define _plausibility_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plausibility_report_t plausibility_report_t;

#include "plausibility_check.h"
#include "plausibility_summary.h"



typedef struct plausibility_report_t {
    list_t *checks; //nonprimitive container
    char *generated_at; // string
    struct plausibility_summary_t *summary; //model

    int _library_owned; // Is the library responsible for freeing this object?
} plausibility_report_t;

__attribute__((deprecated)) plausibility_report_t *plausibility_report_create(
    list_t *checks,
    char *generated_at,
    plausibility_summary_t *summary
);

void plausibility_report_free(plausibility_report_t *plausibility_report);

plausibility_report_t *plausibility_report_parseFromJSON(cJSON *plausibility_reportJSON);

cJSON *plausibility_report_convertToJSON(plausibility_report_t *plausibility_report);

#endif /* _plausibility_report_H_ */

