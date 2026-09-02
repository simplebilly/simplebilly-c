/*
 * bwa_revenue.h
 *
 * 
 */

#ifndef _bwa_revenue_H_
#define _bwa_revenue_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bwa_revenue_t bwa_revenue_t;

#include "revenue_item.h"



typedef struct bwa_revenue_t {
    list_t *revenue_breakdown; //nonprimitive container
    char *total_revenue; // string

    int _library_owned; // Is the library responsible for freeing this object?
} bwa_revenue_t;

__attribute__((deprecated)) bwa_revenue_t *bwa_revenue_create(
    list_t *revenue_breakdown,
    char *total_revenue
);

void bwa_revenue_free(bwa_revenue_t *bwa_revenue);

bwa_revenue_t *bwa_revenue_parseFromJSON(cJSON *bwa_revenueJSON);

cJSON *bwa_revenue_convertToJSON(bwa_revenue_t *bwa_revenue);

#endif /* _bwa_revenue_H_ */

