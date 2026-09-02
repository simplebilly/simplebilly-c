/*
 * emissions_report.h
 *
 * 
 */

#ifndef _emissions_report_H_
#define _emissions_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct emissions_report_t emissions_report_t;

#include "category_total.h"
#include "data_quality.h"
#include "scope_total.h"
#include "target_progress.h"
#include "year_total.h"



typedef struct emissions_report_t {
    list_t *by_category; //nonprimitive container
    list_t *by_scope; //nonprimitive container
    list_t *by_year; //nonprimitive container
    struct data_quality_t *data_quality; //model
    double *intensity_per_employee; //numeric
    double *intensity_per_revenue_mio; //numeric
    double *net_revenue; //numeric
    double *spend_based_estimate_tco2e; //numeric
    list_t *targets; //nonprimitive container
    char *total_tco2e; // string

    int _library_owned; // Is the library responsible for freeing this object?
} emissions_report_t;

__attribute__((deprecated)) emissions_report_t *emissions_report_create(
    list_t *by_category,
    list_t *by_scope,
    list_t *by_year,
    data_quality_t *data_quality,
    double *intensity_per_employee,
    double *intensity_per_revenue_mio,
    double *net_revenue,
    double *spend_based_estimate_tco2e,
    list_t *targets,
    char *total_tco2e
);

void emissions_report_free(emissions_report_t *emissions_report);

emissions_report_t *emissions_report_parseFromJSON(cJSON *emissions_reportJSON);

cJSON *emissions_report_convertToJSON(emissions_report_t *emissions_report);

#endif /* _emissions_report_H_ */

