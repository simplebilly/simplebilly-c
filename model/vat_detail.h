/*
 * vat_detail.h
 *
 * 
 */

#ifndef _vat_detail_H_
#define _vat_detail_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct vat_detail_t vat_detail_t;




typedef struct vat_detail_t {
    long *count; //numeric
    char *net_amount; // string
    char *tax_amount; // string
    char *tax_rate; // string

    int _library_owned; // Is the library responsible for freeing this object?
} vat_detail_t;

__attribute__((deprecated)) vat_detail_t *vat_detail_create(
    long *count,
    char *net_amount,
    char *tax_amount,
    char *tax_rate
);

void vat_detail_free(vat_detail_t *vat_detail);

vat_detail_t *vat_detail_parseFromJSON(cJSON *vat_detailJSON);

cJSON *vat_detail_convertToJSON(vat_detail_t *vat_detail);

#endif /* _vat_detail_H_ */

