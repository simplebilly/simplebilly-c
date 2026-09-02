/*
 * bwa_summary.h
 *
 * 
 */

#ifndef _bwa_summary_H_
#define _bwa_summary_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bwa_summary_t bwa_summary_t;




typedef struct bwa_summary_t {
    char *gross_profit; // string
    char *net_profit; // string
    long *open_invoices_count; //numeric
    char *open_invoices_total; // string
    long *overdue_invoices_count; //numeric
    char *overdue_invoices_total; // string
    double *profit_margin; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} bwa_summary_t;

__attribute__((deprecated)) bwa_summary_t *bwa_summary_create(
    char *gross_profit,
    char *net_profit,
    long *open_invoices_count,
    char *open_invoices_total,
    long *overdue_invoices_count,
    char *overdue_invoices_total,
    double *profit_margin
);

void bwa_summary_free(bwa_summary_t *bwa_summary);

bwa_summary_t *bwa_summary_parseFromJSON(cJSON *bwa_summaryJSON);

cJSON *bwa_summary_convertToJSON(bwa_summary_t *bwa_summary);

#endif /* _bwa_summary_H_ */

