/*
 * bwa_report.h
 *
 * 
 */

#ifndef _bwa_report_H_
#define _bwa_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bwa_report_t bwa_report_t;

#include "bwa_expenses.h"
#include "bwa_revenue.h"
#include "bwa_summary.h"



typedef struct bwa_report_t {
    struct bwa_expenses_t *expenses; //model
    char *generated_at; // string
    char *period; // string
    struct bwa_revenue_t *revenue; //model
    struct bwa_summary_t *summary; //model

    int _library_owned; // Is the library responsible for freeing this object?
} bwa_report_t;

__attribute__((deprecated)) bwa_report_t *bwa_report_create(
    bwa_expenses_t *expenses,
    char *generated_at,
    char *period,
    bwa_revenue_t *revenue,
    bwa_summary_t *summary
);

void bwa_report_free(bwa_report_t *bwa_report);

bwa_report_t *bwa_report_parseFromJSON(cJSON *bwa_reportJSON);

cJSON *bwa_report_convertToJSON(bwa_report_t *bwa_report);

#endif /* _bwa_report_H_ */

