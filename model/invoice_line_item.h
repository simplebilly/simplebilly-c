/*
 * invoice_line_item.h
 *
 * 
 */

#ifndef _invoice_line_item_H_
#define _invoice_line_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invoice_line_item_t invoice_line_item_t;

#include "any_type.h"



typedef struct invoice_line_item_t {
    char *article_number; // string
    char *description; // string
    char *discount_amount; // string
    char *discount_percentage; // string
    int *input_vat_deductible; //boolean
    char *input_vat_rate; // string
    int *is_intra_community_acquisition; //boolean
    int *is_margin_25a; //boolean
    char *ledger_account; // string
    char *line_total; // string
    char *line_total_gross; // string
    char *margin_25a_purchase_price; // string
    char *meter_point_id; // string
    long *position; //numeric
    any_type_t *price_components; // custom
    char *product_id; // string
    char *product_sku; // string
    char *quantity; // string
    char *supplier_article_number; // string
    char *tax_rate; // string
    any_type_t *unit; // custom
    char *unit_price; // string
    char *usage_data_id; // string
    char *vat_rate_nominal; // string
    char *vat_special_case; // string

    int _library_owned; // Is the library responsible for freeing this object?
} invoice_line_item_t;

__attribute__((deprecated)) invoice_line_item_t *invoice_line_item_create(
    char *article_number,
    char *description,
    char *discount_amount,
    char *discount_percentage,
    int *input_vat_deductible,
    char *input_vat_rate,
    int *is_intra_community_acquisition,
    int *is_margin_25a,
    char *ledger_account,
    char *line_total,
    char *line_total_gross,
    char *margin_25a_purchase_price,
    char *meter_point_id,
    long *position,
    any_type_t *price_components,
    char *product_id,
    char *product_sku,
    char *quantity,
    char *supplier_article_number,
    char *tax_rate,
    any_type_t *unit,
    char *unit_price,
    char *usage_data_id,
    char *vat_rate_nominal,
    char *vat_special_case
);

void invoice_line_item_free(invoice_line_item_t *invoice_line_item);

invoice_line_item_t *invoice_line_item_parseFromJSON(cJSON *invoice_line_itemJSON);

cJSON *invoice_line_item_convertToJSON(invoice_line_item_t *invoice_line_item);

#endif /* _invoice_line_item_H_ */

