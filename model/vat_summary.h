/*
 * vat_summary.h
 *
 * 
 */

#ifndef _vat_summary_H_
#define _vat_summary_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct vat_summary_t vat_summary_t;

#include "vat_item.h"



typedef struct vat_summary_t {
    list_t *input_tax_items; //nonprimitive container
    list_t *output_tax_items; //nonprimitive container
    char *total_input_tax; // string
    char *total_output_tax; // string
    char *vat_due; // string

    int _library_owned; // Is the library responsible for freeing this object?
} vat_summary_t;

__attribute__((deprecated)) vat_summary_t *vat_summary_create(
    list_t *input_tax_items,
    list_t *output_tax_items,
    char *total_input_tax,
    char *total_output_tax,
    char *vat_due
);

void vat_summary_free(vat_summary_t *vat_summary);

vat_summary_t *vat_summary_parseFromJSON(cJSON *vat_summaryJSON);

cJSON *vat_summary_convertToJSON(vat_summary_t *vat_summary);

#endif /* _vat_summary_H_ */

