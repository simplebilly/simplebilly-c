/*
 * gu_v_report.h
 *
 * 
 */

#ifndef _gu_v_report_H_
#define _gu_v_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gu_v_report_t gu_v_report_t;

#include "gu_v_item.h"



typedef struct gu_v_report_t {
    list_t *expenses; //nonprimitive container
    char *generated_at; // string
    char *net_income; // string
    char *period; // string
    list_t *revenue; //nonprimitive container
    char *total_expenses; // string
    char *total_revenue; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gu_v_report_t;

__attribute__((deprecated)) gu_v_report_t *gu_v_report_create(
    list_t *expenses,
    char *generated_at,
    char *net_income,
    char *period,
    list_t *revenue,
    char *total_expenses,
    char *total_revenue
);

void gu_v_report_free(gu_v_report_t *gu_v_report);

gu_v_report_t *gu_v_report_parseFromJSON(cJSON *gu_v_reportJSON);

cJSON *gu_v_report_convertToJSON(gu_v_report_t *gu_v_report);

#endif /* _gu_v_report_H_ */

