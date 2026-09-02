/*
 * oss_report.h
 *
 * 
 */

#ifndef _oss_report_H_
#define _oss_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct oss_report_t oss_report_t;

#include "oss_dependency.h"



typedef struct oss_report_t {
    list_t *dependencies; //nonprimitive container
    int *total_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} oss_report_t;

__attribute__((deprecated)) oss_report_t *oss_report_create(
    list_t *dependencies,
    int *total_count
);

void oss_report_free(oss_report_t *oss_report);

oss_report_t *oss_report_parseFromJSON(cJSON *oss_reportJSON);

cJSON *oss_report_convertToJSON(oss_report_t *oss_report);

#endif /* _oss_report_H_ */

