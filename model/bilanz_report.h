/*
 * bilanz_report.h
 *
 * 
 */

#ifndef _bilanz_report_H_
#define _bilanz_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bilanz_report_t bilanz_report_t;

#include "bilanz_item.h"



typedef struct bilanz_report_t {
    list_t *aktiva; //nonprimitive container
    int *balanced; //boolean
    char *generated_at; // string
    list_t *passiva; //nonprimitive container
    char *period; // string
    char *total_aktiva; // string
    char *total_passiva; // string

    int _library_owned; // Is the library responsible for freeing this object?
} bilanz_report_t;

__attribute__((deprecated)) bilanz_report_t *bilanz_report_create(
    list_t *aktiva,
    int *balanced,
    char *generated_at,
    list_t *passiva,
    char *period,
    char *total_aktiva,
    char *total_passiva
);

void bilanz_report_free(bilanz_report_t *bilanz_report);

bilanz_report_t *bilanz_report_parseFromJSON(cJSON *bilanz_reportJSON);

cJSON *bilanz_report_convertToJSON(bilanz_report_t *bilanz_report);

#endif /* _bilanz_report_H_ */

