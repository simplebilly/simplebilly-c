#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invoice_line_item.h"



static invoice_line_item_t *invoice_line_item_create_internal(
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
    ) {
    invoice_line_item_t *invoice_line_item_local_var = malloc(sizeof(invoice_line_item_t));
    if (!invoice_line_item_local_var) {
        return NULL;
    }
    memset(invoice_line_item_local_var, 0, sizeof(invoice_line_item_t));
    invoice_line_item_local_var->_library_owned = 1;
    invoice_line_item_local_var->article_number = article_number;
    invoice_line_item_local_var->description = description;
    invoice_line_item_local_var->discount_amount = discount_amount;
    invoice_line_item_local_var->discount_percentage = discount_percentage;
    invoice_line_item_local_var->input_vat_deductible = input_vat_deductible;
    invoice_line_item_local_var->input_vat_rate = input_vat_rate;
    invoice_line_item_local_var->is_intra_community_acquisition = is_intra_community_acquisition;
    invoice_line_item_local_var->is_margin_25a = is_margin_25a;
    invoice_line_item_local_var->ledger_account = ledger_account;
    invoice_line_item_local_var->line_total = line_total;
    invoice_line_item_local_var->line_total_gross = line_total_gross;
    invoice_line_item_local_var->margin_25a_purchase_price = margin_25a_purchase_price;
    invoice_line_item_local_var->meter_point_id = meter_point_id;
    invoice_line_item_local_var->position = position;
    invoice_line_item_local_var->price_components = price_components;
    invoice_line_item_local_var->product_id = product_id;
    invoice_line_item_local_var->product_sku = product_sku;
    invoice_line_item_local_var->quantity = quantity;
    invoice_line_item_local_var->supplier_article_number = supplier_article_number;
    invoice_line_item_local_var->tax_rate = tax_rate;
    invoice_line_item_local_var->unit = unit;
    invoice_line_item_local_var->unit_price = unit_price;
    invoice_line_item_local_var->usage_data_id = usage_data_id;
    invoice_line_item_local_var->vat_rate_nominal = vat_rate_nominal;
    invoice_line_item_local_var->vat_special_case = vat_special_case;
    return invoice_line_item_local_var;
}

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
    ) {
    int *input_vat_deductible_copy = NULL;
    if (input_vat_deductible) {
        input_vat_deductible_copy = malloc(sizeof(int));
        if (input_vat_deductible_copy) *input_vat_deductible_copy = *input_vat_deductible;
    }
    int *is_intra_community_acquisition_copy = NULL;
    if (is_intra_community_acquisition) {
        is_intra_community_acquisition_copy = malloc(sizeof(int));
        if (is_intra_community_acquisition_copy) *is_intra_community_acquisition_copy = *is_intra_community_acquisition;
    }
    int *is_margin_25a_copy = NULL;
    if (is_margin_25a) {
        is_margin_25a_copy = malloc(sizeof(int));
        if (is_margin_25a_copy) *is_margin_25a_copy = *is_margin_25a;
    }
    long *position_copy = NULL;
    if (position) {
        position_copy = malloc(sizeof(long));
        if (position_copy) *position_copy = *position;
    }
    invoice_line_item_t *result = invoice_line_item_create_internal (
        article_number,
        description,
        discount_amount,
        discount_percentage,
        input_vat_deductible_copy,
        input_vat_rate,
        is_intra_community_acquisition_copy,
        is_margin_25a_copy,
        ledger_account,
        line_total,
        line_total_gross,
        margin_25a_purchase_price,
        meter_point_id,
        position_copy,
        price_components,
        product_id,
        product_sku,
        quantity,
        supplier_article_number,
        tax_rate,
        unit,
        unit_price,
        usage_data_id,
        vat_rate_nominal,
        vat_special_case
        );
    if (!result) {
        free(input_vat_deductible_copy);
        free(is_intra_community_acquisition_copy);
        free(is_margin_25a_copy);
        free(position_copy);
    }
    return result;
}

void invoice_line_item_free(invoice_line_item_t *invoice_line_item) {
    if(NULL == invoice_line_item){
        return ;
    }
    if(invoice_line_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invoice_line_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invoice_line_item->article_number) {
        free(invoice_line_item->article_number);
        invoice_line_item->article_number = NULL;
    }
    if (invoice_line_item->description) {
        free(invoice_line_item->description);
        invoice_line_item->description = NULL;
    }
    if (invoice_line_item->discount_amount) {
        free(invoice_line_item->discount_amount);
        invoice_line_item->discount_amount = NULL;
    }
    if (invoice_line_item->discount_percentage) {
        free(invoice_line_item->discount_percentage);
        invoice_line_item->discount_percentage = NULL;
    }
    if (invoice_line_item->input_vat_deductible) {
        free(invoice_line_item->input_vat_deductible);
        invoice_line_item->input_vat_deductible = NULL;
    }
    if (invoice_line_item->input_vat_rate) {
        free(invoice_line_item->input_vat_rate);
        invoice_line_item->input_vat_rate = NULL;
    }
    if (invoice_line_item->is_intra_community_acquisition) {
        free(invoice_line_item->is_intra_community_acquisition);
        invoice_line_item->is_intra_community_acquisition = NULL;
    }
    if (invoice_line_item->is_margin_25a) {
        free(invoice_line_item->is_margin_25a);
        invoice_line_item->is_margin_25a = NULL;
    }
    if (invoice_line_item->ledger_account) {
        free(invoice_line_item->ledger_account);
        invoice_line_item->ledger_account = NULL;
    }
    if (invoice_line_item->line_total) {
        free(invoice_line_item->line_total);
        invoice_line_item->line_total = NULL;
    }
    if (invoice_line_item->line_total_gross) {
        free(invoice_line_item->line_total_gross);
        invoice_line_item->line_total_gross = NULL;
    }
    if (invoice_line_item->margin_25a_purchase_price) {
        free(invoice_line_item->margin_25a_purchase_price);
        invoice_line_item->margin_25a_purchase_price = NULL;
    }
    if (invoice_line_item->meter_point_id) {
        free(invoice_line_item->meter_point_id);
        invoice_line_item->meter_point_id = NULL;
    }
    if (invoice_line_item->position) {
        free(invoice_line_item->position);
        invoice_line_item->position = NULL;
    }
    if (invoice_line_item->price_components) {
        _free(invoice_line_item->price_components);
        invoice_line_item->price_components = NULL;
    }
    if (invoice_line_item->product_id) {
        free(invoice_line_item->product_id);
        invoice_line_item->product_id = NULL;
    }
    if (invoice_line_item->product_sku) {
        free(invoice_line_item->product_sku);
        invoice_line_item->product_sku = NULL;
    }
    if (invoice_line_item->quantity) {
        free(invoice_line_item->quantity);
        invoice_line_item->quantity = NULL;
    }
    if (invoice_line_item->supplier_article_number) {
        free(invoice_line_item->supplier_article_number);
        invoice_line_item->supplier_article_number = NULL;
    }
    if (invoice_line_item->tax_rate) {
        free(invoice_line_item->tax_rate);
        invoice_line_item->tax_rate = NULL;
    }
    if (invoice_line_item->unit) {
        _free(invoice_line_item->unit);
        invoice_line_item->unit = NULL;
    }
    if (invoice_line_item->unit_price) {
        free(invoice_line_item->unit_price);
        invoice_line_item->unit_price = NULL;
    }
    if (invoice_line_item->usage_data_id) {
        free(invoice_line_item->usage_data_id);
        invoice_line_item->usage_data_id = NULL;
    }
    if (invoice_line_item->vat_rate_nominal) {
        free(invoice_line_item->vat_rate_nominal);
        invoice_line_item->vat_rate_nominal = NULL;
    }
    if (invoice_line_item->vat_special_case) {
        free(invoice_line_item->vat_special_case);
        invoice_line_item->vat_special_case = NULL;
    }
    free(invoice_line_item);
}

cJSON *invoice_line_item_convertToJSON(invoice_line_item_t *invoice_line_item) {
    cJSON *item = cJSON_CreateObject();

    // invoice_line_item->article_number
    if(invoice_line_item->article_number) {
    if(cJSON_AddStringToObject(item, "article_number", invoice_line_item->article_number) == NULL) {
    goto fail; //String
    }
    }


    // invoice_line_item->description
    if (!invoice_line_item->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", invoice_line_item->description) == NULL) {
    goto fail; //String
    }


    // invoice_line_item->discount_amount
    if(invoice_line_item->discount_amount) {
    if(cJSON_AddStringToObject(item, "discount_amount", invoice_line_item->discount_amount) == NULL) {
    goto fail; //String
    }
    }


    // invoice_line_item->discount_percentage
    if(invoice_line_item->discount_percentage) {
    if(cJSON_AddStringToObject(item, "discount_percentage", invoice_line_item->discount_percentage) == NULL) {
    goto fail; //String
    }
    }


    // invoice_line_item->input_vat_deductible
    if(invoice_line_item->input_vat_deductible) {
    if(cJSON_AddBoolToObject(item, "input_vat_deductible", *invoice_line_item->input_vat_deductible) == NULL) {
    goto fail; //Bool
    }
    }


    // invoice_line_item->input_vat_rate
    if(invoice_line_item->input_vat_rate) {
    if(cJSON_AddStringToObject(item, "input_vat_rate", invoice_line_item->input_vat_rate) == NULL) {
    goto fail; //String
    }
    }


    // invoice_line_item->is_intra_community_acquisition
    if(invoice_line_item->is_intra_community_acquisition) {
    if(cJSON_AddBoolToObject(item, "is_intra_community_acquisition", *invoice_line_item->is_intra_community_acquisition) == NULL) {
    goto fail; //Bool
    }
    }


    // invoice_line_item->is_margin_25a
    if(invoice_line_item->is_margin_25a) {
    if(cJSON_AddBoolToObject(item, "is_margin_25a", *invoice_line_item->is_margin_25a) == NULL) {
    goto fail; //Bool
    }
    }


    // invoice_line_item->ledger_account
    if(invoice_line_item->ledger_account) {
    if(cJSON_AddStringToObject(item, "ledger_account", invoice_line_item->ledger_account) == NULL) {
    goto fail; //String
    }
    }


    // invoice_line_item->line_total
    if (!invoice_line_item->line_total) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "line_total", invoice_line_item->line_total) == NULL) {
    goto fail; //String
    }


    // invoice_line_item->line_total_gross
    if(invoice_line_item->line_total_gross) {
    if(cJSON_AddStringToObject(item, "line_total_gross", invoice_line_item->line_total_gross) == NULL) {
    goto fail; //String
    }
    }


    // invoice_line_item->margin_25a_purchase_price
    if(invoice_line_item->margin_25a_purchase_price) {
    if(cJSON_AddStringToObject(item, "margin_25a_purchase_price", invoice_line_item->margin_25a_purchase_price) == NULL) {
    goto fail; //String
    }
    }


    // invoice_line_item->meter_point_id
    if(invoice_line_item->meter_point_id) {
    if(cJSON_AddStringToObject(item, "meter_point_id", invoice_line_item->meter_point_id) == NULL) {
    goto fail; //String
    }
    }


    // invoice_line_item->position
    if (!invoice_line_item->position) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "position", *invoice_line_item->position) == NULL) {
    goto fail; //Numeric
    }


    // invoice_line_item->price_components
    if(invoice_line_item->price_components) {
    cJSON *price_components_local_JSON = _convertToJSON(invoice_line_item->price_components);
    if(price_components_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "price_components", price_components_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // invoice_line_item->product_id
    if(invoice_line_item->product_id) {
    if(cJSON_AddStringToObject(item, "product_id", invoice_line_item->product_id) == NULL) {
    goto fail; //String
    }
    }


    // invoice_line_item->product_sku
    if(invoice_line_item->product_sku) {
    if(cJSON_AddStringToObject(item, "product_sku", invoice_line_item->product_sku) == NULL) {
    goto fail; //String
    }
    }


    // invoice_line_item->quantity
    if (!invoice_line_item->quantity) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "quantity", invoice_line_item->quantity) == NULL) {
    goto fail; //String
    }


    // invoice_line_item->supplier_article_number
    if(invoice_line_item->supplier_article_number) {
    if(cJSON_AddStringToObject(item, "supplier_article_number", invoice_line_item->supplier_article_number) == NULL) {
    goto fail; //String
    }
    }


    // invoice_line_item->tax_rate
    if(invoice_line_item->tax_rate) {
    if(cJSON_AddStringToObject(item, "tax_rate", invoice_line_item->tax_rate) == NULL) {
    goto fail; //String
    }
    }


    // invoice_line_item->unit
    if (!invoice_line_item->unit) {
        goto fail;
    }
    cJSON *unit_local_JSON = _convertToJSON(invoice_line_item->unit);
    if(unit_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "unit", unit_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // invoice_line_item->unit_price
    if (!invoice_line_item->unit_price) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "unit_price", invoice_line_item->unit_price) == NULL) {
    goto fail; //String
    }


    // invoice_line_item->usage_data_id
    if(invoice_line_item->usage_data_id) {
    if(cJSON_AddStringToObject(item, "usage_data_id", invoice_line_item->usage_data_id) == NULL) {
    goto fail; //String
    }
    }


    // invoice_line_item->vat_rate_nominal
    if(invoice_line_item->vat_rate_nominal) {
    if(cJSON_AddStringToObject(item, "vat_rate_nominal", invoice_line_item->vat_rate_nominal) == NULL) {
    goto fail; //String
    }
    }


    // invoice_line_item->vat_special_case
    if(invoice_line_item->vat_special_case) {
    if(cJSON_AddStringToObject(item, "vat_special_case", invoice_line_item->vat_special_case) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invoice_line_item_t *invoice_line_item_parseFromJSON(cJSON *invoice_line_itemJSON){

    invoice_line_item_t *invoice_line_item_local_var = NULL;

    char *article_number_local_str = NULL;

    char *description_local_str = NULL;

    char *discount_amount_local_str = NULL;

    char *discount_percentage_local_str = NULL;

    // define the local variable for invoice_line_item->input_vat_deductible
    int *input_vat_deductible_local_var = NULL;

    char *input_vat_rate_local_str = NULL;

    // define the local variable for invoice_line_item->is_intra_community_acquisition
    int *is_intra_community_acquisition_local_var = NULL;

    // define the local variable for invoice_line_item->is_margin_25a
    int *is_margin_25a_local_var = NULL;

    char *ledger_account_local_str = NULL;

    char *line_total_local_str = NULL;

    char *line_total_gross_local_str = NULL;

    char *margin_25a_purchase_price_local_str = NULL;

    char *meter_point_id_local_str = NULL;

    // define the local variable for invoice_line_item->position
    long *position_local_var = NULL;

    // define the local variable for invoice_line_item->price_components
    _t *price_components_local_nonprim = NULL;

    char *product_id_local_str = NULL;

    char *product_sku_local_str = NULL;

    char *quantity_local_str = NULL;

    char *supplier_article_number_local_str = NULL;

    char *tax_rate_local_str = NULL;

    // define the local variable for invoice_line_item->unit
    _t *unit_local_nonprim = NULL;

    char *unit_price_local_str = NULL;

    char *usage_data_id_local_str = NULL;

    char *vat_rate_nominal_local_str = NULL;

    char *vat_special_case_local_str = NULL;

    // invoice_line_item->article_number
    cJSON *article_number = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "article_number");
    if (cJSON_IsNull(article_number)) {
        article_number = NULL;
    }
    if (article_number) { 
    if(!cJSON_IsString(article_number) && !cJSON_IsNull(article_number))
    {
    goto end; //String
    }
    }

    // invoice_line_item->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }

    // invoice_line_item->discount_amount
    cJSON *discount_amount = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "discount_amount");
    if (cJSON_IsNull(discount_amount)) {
        discount_amount = NULL;
    }
    if (discount_amount) { 
    if(!cJSON_IsString(discount_amount) && !cJSON_IsNull(discount_amount))
    {
    goto end; //String
    }
    }

    // invoice_line_item->discount_percentage
    cJSON *discount_percentage = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "discount_percentage");
    if (cJSON_IsNull(discount_percentage)) {
        discount_percentage = NULL;
    }
    if (discount_percentage) { 
    if(!cJSON_IsString(discount_percentage) && !cJSON_IsNull(discount_percentage))
    {
    goto end; //String
    }
    }

    // invoice_line_item->input_vat_deductible
    cJSON *input_vat_deductible = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "input_vat_deductible");
    if (cJSON_IsNull(input_vat_deductible)) {
        input_vat_deductible = NULL;
    }
    if (input_vat_deductible) { 
    if(!cJSON_IsBool(input_vat_deductible))
    {
    goto end; //Bool
    }
    input_vat_deductible_local_var = malloc(sizeof(int));
    if(!input_vat_deductible_local_var)
    {
        goto end;
    }
    *input_vat_deductible_local_var = input_vat_deductible->valueint;
    }

    // invoice_line_item->input_vat_rate
    cJSON *input_vat_rate = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "input_vat_rate");
    if (cJSON_IsNull(input_vat_rate)) {
        input_vat_rate = NULL;
    }
    if (input_vat_rate) { 
    if(!cJSON_IsString(input_vat_rate) && !cJSON_IsNull(input_vat_rate))
    {
    goto end; //String
    }
    }

    // invoice_line_item->is_intra_community_acquisition
    cJSON *is_intra_community_acquisition = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "is_intra_community_acquisition");
    if (cJSON_IsNull(is_intra_community_acquisition)) {
        is_intra_community_acquisition = NULL;
    }
    if (is_intra_community_acquisition) { 
    if(!cJSON_IsBool(is_intra_community_acquisition))
    {
    goto end; //Bool
    }
    is_intra_community_acquisition_local_var = malloc(sizeof(int));
    if(!is_intra_community_acquisition_local_var)
    {
        goto end;
    }
    *is_intra_community_acquisition_local_var = is_intra_community_acquisition->valueint;
    }

    // invoice_line_item->is_margin_25a
    cJSON *is_margin_25a = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "is_margin_25a");
    if (cJSON_IsNull(is_margin_25a)) {
        is_margin_25a = NULL;
    }
    if (is_margin_25a) { 
    if(!cJSON_IsBool(is_margin_25a))
    {
    goto end; //Bool
    }
    is_margin_25a_local_var = malloc(sizeof(int));
    if(!is_margin_25a_local_var)
    {
        goto end;
    }
    *is_margin_25a_local_var = is_margin_25a->valueint;
    }

    // invoice_line_item->ledger_account
    cJSON *ledger_account = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "ledger_account");
    if (cJSON_IsNull(ledger_account)) {
        ledger_account = NULL;
    }
    if (ledger_account) { 
    if(!cJSON_IsString(ledger_account) && !cJSON_IsNull(ledger_account))
    {
    goto end; //String
    }
    }

    // invoice_line_item->line_total
    cJSON *line_total = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "line_total");
    if (cJSON_IsNull(line_total)) {
        line_total = NULL;
    }
    if (!line_total) {
        goto end;
    }

    
    if(!cJSON_IsString(line_total))
    {
    goto end; //String
    }

    // invoice_line_item->line_total_gross
    cJSON *line_total_gross = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "line_total_gross");
    if (cJSON_IsNull(line_total_gross)) {
        line_total_gross = NULL;
    }
    if (line_total_gross) { 
    if(!cJSON_IsString(line_total_gross) && !cJSON_IsNull(line_total_gross))
    {
    goto end; //String
    }
    }

    // invoice_line_item->margin_25a_purchase_price
    cJSON *margin_25a_purchase_price = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "margin_25a_purchase_price");
    if (cJSON_IsNull(margin_25a_purchase_price)) {
        margin_25a_purchase_price = NULL;
    }
    if (margin_25a_purchase_price) { 
    if(!cJSON_IsString(margin_25a_purchase_price) && !cJSON_IsNull(margin_25a_purchase_price))
    {
    goto end; //String
    }
    }

    // invoice_line_item->meter_point_id
    cJSON *meter_point_id = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "meter_point_id");
    if (cJSON_IsNull(meter_point_id)) {
        meter_point_id = NULL;
    }
    if (meter_point_id) { 
    if(!cJSON_IsString(meter_point_id) && !cJSON_IsNull(meter_point_id))
    {
    goto end; //String
    }
    }

    // invoice_line_item->position
    cJSON *position = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "position");
    if (cJSON_IsNull(position)) {
        position = NULL;
    }
    if (!position) {
        goto end;
    }

    
    if(!cJSON_IsNumber(position))
    {
    goto end; //Numeric
    }
    position_local_var = malloc(sizeof(long));
    if(!position_local_var)
    {
        goto end;
    }
    *position_local_var = position->valuedouble;

    // invoice_line_item->price_components
    cJSON *price_components = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "price_components");
    if (cJSON_IsNull(price_components)) {
        price_components = NULL;
    }
    if (price_components) { 
    price_components_local_nonprim = _parseFromJSON(price_components); //custom
    }

    // invoice_line_item->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "product_id");
    if (cJSON_IsNull(product_id)) {
        product_id = NULL;
    }
    if (product_id) { 
    if(!cJSON_IsString(product_id) && !cJSON_IsNull(product_id))
    {
    goto end; //String
    }
    }

    // invoice_line_item->product_sku
    cJSON *product_sku = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "product_sku");
    if (cJSON_IsNull(product_sku)) {
        product_sku = NULL;
    }
    if (product_sku) { 
    if(!cJSON_IsString(product_sku) && !cJSON_IsNull(product_sku))
    {
    goto end; //String
    }
    }

    // invoice_line_item->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "quantity");
    if (cJSON_IsNull(quantity)) {
        quantity = NULL;
    }
    if (!quantity) {
        goto end;
    }

    
    if(!cJSON_IsString(quantity))
    {
    goto end; //String
    }

    // invoice_line_item->supplier_article_number
    cJSON *supplier_article_number = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "supplier_article_number");
    if (cJSON_IsNull(supplier_article_number)) {
        supplier_article_number = NULL;
    }
    if (supplier_article_number) { 
    if(!cJSON_IsString(supplier_article_number) && !cJSON_IsNull(supplier_article_number))
    {
    goto end; //String
    }
    }

    // invoice_line_item->tax_rate
    cJSON *tax_rate = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "tax_rate");
    if (cJSON_IsNull(tax_rate)) {
        tax_rate = NULL;
    }
    if (tax_rate) { 
    if(!cJSON_IsString(tax_rate) && !cJSON_IsNull(tax_rate))
    {
    goto end; //String
    }
    }

    // invoice_line_item->unit
    cJSON *unit = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "unit");
    if (cJSON_IsNull(unit)) {
        unit = NULL;
    }
    if (!unit) {
        goto end;
    }

    
    unit_local_nonprim = _parseFromJSON(unit); //custom

    // invoice_line_item->unit_price
    cJSON *unit_price = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "unit_price");
    if (cJSON_IsNull(unit_price)) {
        unit_price = NULL;
    }
    if (!unit_price) {
        goto end;
    }

    
    if(!cJSON_IsString(unit_price))
    {
    goto end; //String
    }

    // invoice_line_item->usage_data_id
    cJSON *usage_data_id = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "usage_data_id");
    if (cJSON_IsNull(usage_data_id)) {
        usage_data_id = NULL;
    }
    if (usage_data_id) { 
    if(!cJSON_IsString(usage_data_id) && !cJSON_IsNull(usage_data_id))
    {
    goto end; //String
    }
    }

    // invoice_line_item->vat_rate_nominal
    cJSON *vat_rate_nominal = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "vat_rate_nominal");
    if (cJSON_IsNull(vat_rate_nominal)) {
        vat_rate_nominal = NULL;
    }
    if (vat_rate_nominal) { 
    if(!cJSON_IsString(vat_rate_nominal) && !cJSON_IsNull(vat_rate_nominal))
    {
    goto end; //String
    }
    }

    // invoice_line_item->vat_special_case
    cJSON *vat_special_case = cJSON_GetObjectItemCaseSensitive(invoice_line_itemJSON, "vat_special_case");
    if (cJSON_IsNull(vat_special_case)) {
        vat_special_case = NULL;
    }
    if (vat_special_case) { 
    if(!cJSON_IsString(vat_special_case) && !cJSON_IsNull(vat_special_case))
    {
    goto end; //String
    }
    }


    if (article_number && !cJSON_IsNull(article_number)) article_number_local_str = strdup(article_number->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (discount_amount && !cJSON_IsNull(discount_amount)) discount_amount_local_str = strdup(discount_amount->valuestring);
    if (discount_percentage && !cJSON_IsNull(discount_percentage)) discount_percentage_local_str = strdup(discount_percentage->valuestring);
    if (input_vat_rate && !cJSON_IsNull(input_vat_rate)) input_vat_rate_local_str = strdup(input_vat_rate->valuestring);
    if (ledger_account && !cJSON_IsNull(ledger_account)) ledger_account_local_str = strdup(ledger_account->valuestring);
    if (line_total && !cJSON_IsNull(line_total)) line_total_local_str = strdup(line_total->valuestring);
    if (line_total_gross && !cJSON_IsNull(line_total_gross)) line_total_gross_local_str = strdup(line_total_gross->valuestring);
    if (margin_25a_purchase_price && !cJSON_IsNull(margin_25a_purchase_price)) margin_25a_purchase_price_local_str = strdup(margin_25a_purchase_price->valuestring);
    if (meter_point_id && !cJSON_IsNull(meter_point_id)) meter_point_id_local_str = strdup(meter_point_id->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (product_sku && !cJSON_IsNull(product_sku)) product_sku_local_str = strdup(product_sku->valuestring);
    if (quantity && !cJSON_IsNull(quantity)) quantity_local_str = strdup(quantity->valuestring);
    if (supplier_article_number && !cJSON_IsNull(supplier_article_number)) supplier_article_number_local_str = strdup(supplier_article_number->valuestring);
    if (tax_rate && !cJSON_IsNull(tax_rate)) tax_rate_local_str = strdup(tax_rate->valuestring);
    if (unit_price && !cJSON_IsNull(unit_price)) unit_price_local_str = strdup(unit_price->valuestring);
    if (usage_data_id && !cJSON_IsNull(usage_data_id)) usage_data_id_local_str = strdup(usage_data_id->valuestring);
    if (vat_rate_nominal && !cJSON_IsNull(vat_rate_nominal)) vat_rate_nominal_local_str = strdup(vat_rate_nominal->valuestring);
    if (vat_special_case && !cJSON_IsNull(vat_special_case)) vat_special_case_local_str = strdup(vat_special_case->valuestring);

    invoice_line_item_local_var = invoice_line_item_create_internal (
        article_number_local_str,
        description_local_str,
        discount_amount_local_str,
        discount_percentage_local_str,
        input_vat_deductible_local_var,
        input_vat_rate_local_str,
        is_intra_community_acquisition_local_var,
        is_margin_25a_local_var,
        ledger_account_local_str,
        line_total_local_str,
        line_total_gross_local_str,
        margin_25a_purchase_price_local_str,
        meter_point_id_local_str,
        position_local_var,
        price_components ? price_components_local_nonprim : NULL,
        product_id_local_str,
        product_sku_local_str,
        quantity_local_str,
        supplier_article_number_local_str,
        tax_rate_local_str,
        unit_local_nonprim,
        unit_price_local_str,
        usage_data_id_local_str,
        vat_rate_nominal_local_str,
        vat_special_case_local_str
        );

    if (!invoice_line_item_local_var) {
        goto end;
    }

    return invoice_line_item_local_var;
end:
    if (article_number_local_str) {
        free(article_number_local_str);
        article_number_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (discount_amount_local_str) {
        free(discount_amount_local_str);
        discount_amount_local_str = NULL;
    }
    if (discount_percentage_local_str) {
        free(discount_percentage_local_str);
        discount_percentage_local_str = NULL;
    }
    if (input_vat_deductible_local_var) {
        free(input_vat_deductible_local_var);
        input_vat_deductible_local_var = NULL;
    }
    if (input_vat_rate_local_str) {
        free(input_vat_rate_local_str);
        input_vat_rate_local_str = NULL;
    }
    if (is_intra_community_acquisition_local_var) {
        free(is_intra_community_acquisition_local_var);
        is_intra_community_acquisition_local_var = NULL;
    }
    if (is_margin_25a_local_var) {
        free(is_margin_25a_local_var);
        is_margin_25a_local_var = NULL;
    }
    if (ledger_account_local_str) {
        free(ledger_account_local_str);
        ledger_account_local_str = NULL;
    }
    if (line_total_local_str) {
        free(line_total_local_str);
        line_total_local_str = NULL;
    }
    if (line_total_gross_local_str) {
        free(line_total_gross_local_str);
        line_total_gross_local_str = NULL;
    }
    if (margin_25a_purchase_price_local_str) {
        free(margin_25a_purchase_price_local_str);
        margin_25a_purchase_price_local_str = NULL;
    }
    if (meter_point_id_local_str) {
        free(meter_point_id_local_str);
        meter_point_id_local_str = NULL;
    }
    if (position_local_var) {
        free(position_local_var);
        position_local_var = NULL;
    }
    if (price_components_local_nonprim) {
        _free(price_components_local_nonprim);
        price_components_local_nonprim = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (product_sku_local_str) {
        free(product_sku_local_str);
        product_sku_local_str = NULL;
    }
    if (quantity_local_str) {
        free(quantity_local_str);
        quantity_local_str = NULL;
    }
    if (supplier_article_number_local_str) {
        free(supplier_article_number_local_str);
        supplier_article_number_local_str = NULL;
    }
    if (tax_rate_local_str) {
        free(tax_rate_local_str);
        tax_rate_local_str = NULL;
    }
    if (unit_local_nonprim) {
        _free(unit_local_nonprim);
        unit_local_nonprim = NULL;
    }
    if (unit_price_local_str) {
        free(unit_price_local_str);
        unit_price_local_str = NULL;
    }
    if (usage_data_id_local_str) {
        free(usage_data_id_local_str);
        usage_data_id_local_str = NULL;
    }
    if (vat_rate_nominal_local_str) {
        free(vat_rate_nominal_local_str);
        vat_rate_nominal_local_str = NULL;
    }
    if (vat_special_case_local_str) {
        free(vat_special_case_local_str);
        vat_special_case_local_str = NULL;
    }
    return NULL;

}
