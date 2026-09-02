/*
 * sales_volume_report.h
 *
 * 
 */

#ifndef _sales_volume_report_H_
#define _sales_volume_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sales_volume_report_t sales_volume_report_t;

#include "sales_volume_item.h"



typedef struct sales_volume_report_t {
    char *grand_total; // string
    list_t *items; //nonprimitive container
    long *total_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} sales_volume_report_t;

__attribute__((deprecated)) sales_volume_report_t *sales_volume_report_create(
    char *grand_total,
    list_t *items,
    long *total_count
);

void sales_volume_report_free(sales_volume_report_t *sales_volume_report);

sales_volume_report_t *sales_volume_report_parseFromJSON(cJSON *sales_volume_reportJSON);

cJSON *sales_volume_report_convertToJSON(sales_volume_report_t *sales_volume_report);

#endif /* _sales_volume_report_H_ */

