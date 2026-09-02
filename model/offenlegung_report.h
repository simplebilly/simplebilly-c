/*
 * offenlegung_report.h
 *
 * 
 */

#ifndef _offenlegung_report_H_
#define _offenlegung_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct offenlegung_report_t offenlegung_report_t;

#include "offenlegung_item.h"



typedef struct offenlegung_report_t {
    char *deadline; //date
    int *deadline_months; //numeric
    list_t *items; //nonprimitive container
    int *kapitalmarktorientiert; //boolean
    char *note; // string
    int *year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} offenlegung_report_t;

__attribute__((deprecated)) offenlegung_report_t *offenlegung_report_create(
    char *deadline,
    int *deadline_months,
    list_t *items,
    int *kapitalmarktorientiert,
    char *note,
    int *year
);

void offenlegung_report_free(offenlegung_report_t *offenlegung_report);

offenlegung_report_t *offenlegung_report_parseFromJSON(cJSON *offenlegung_reportJSON);

cJSON *offenlegung_report_convertToJSON(offenlegung_report_t *offenlegung_report);

#endif /* _offenlegung_report_H_ */

