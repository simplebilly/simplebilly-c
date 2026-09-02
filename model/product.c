#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "product.h"



static product_t *product_create_internal(
    char *availability,
    char *barcode,
    char *brand,
    char *category_id,
    char *condition,
    char *default_ledger_account,
    char *default_price,
    char *default_price_formula_id,
    char *default_tax_rate,
    char *description,
    char *gtin,
    char *height,
    char *image_link,
    any_type_t *images,
    int *is_taxable,
    char *length,
    char *link,
    long *max_stock,
    long *min_stock,
    char *mpn,
    char *name,
    char *package_height,
    char *package_length,
    char *package_weight_unit,
    char *package_weight_value,
    char *package_width,
    char *product_code,
    char *product_type,
    char *purchase_price,
    long *reorder_quantity,
    char *sale_price,
    char *shipping_price,
    int *shipping_requires_insurance,
    char *sku,
    long *stock_quantity,
    any_type_t *tags,
    char *tax_price,
    int *track_batch,
    int *track_serial,
    any_type_t *unit,
    char *weight_unit,
    char *weight_value,
    char *width
    ) {
    product_t *product_local_var = malloc(sizeof(product_t));
    if (!product_local_var) {
        return NULL;
    }
    memset(product_local_var, 0, sizeof(product_t));
    product_local_var->_library_owned = 1;
    product_local_var->availability = availability;
    product_local_var->barcode = barcode;
    product_local_var->brand = brand;
    product_local_var->category_id = category_id;
    product_local_var->condition = condition;
    product_local_var->default_ledger_account = default_ledger_account;
    product_local_var->default_price = default_price;
    product_local_var->default_price_formula_id = default_price_formula_id;
    product_local_var->default_tax_rate = default_tax_rate;
    product_local_var->description = description;
    product_local_var->gtin = gtin;
    product_local_var->height = height;
    product_local_var->image_link = image_link;
    product_local_var->images = images;
    product_local_var->is_taxable = is_taxable;
    product_local_var->length = length;
    product_local_var->link = link;
    product_local_var->max_stock = max_stock;
    product_local_var->min_stock = min_stock;
    product_local_var->mpn = mpn;
    product_local_var->name = name;
    product_local_var->package_height = package_height;
    product_local_var->package_length = package_length;
    product_local_var->package_weight_unit = package_weight_unit;
    product_local_var->package_weight_value = package_weight_value;
    product_local_var->package_width = package_width;
    product_local_var->product_code = product_code;
    product_local_var->product_type = product_type;
    product_local_var->purchase_price = purchase_price;
    product_local_var->reorder_quantity = reorder_quantity;
    product_local_var->sale_price = sale_price;
    product_local_var->shipping_price = shipping_price;
    product_local_var->shipping_requires_insurance = shipping_requires_insurance;
    product_local_var->sku = sku;
    product_local_var->stock_quantity = stock_quantity;
    product_local_var->tags = tags;
    product_local_var->tax_price = tax_price;
    product_local_var->track_batch = track_batch;
    product_local_var->track_serial = track_serial;
    product_local_var->unit = unit;
    product_local_var->weight_unit = weight_unit;
    product_local_var->weight_value = weight_value;
    product_local_var->width = width;
    return product_local_var;
}

__attribute__((deprecated)) product_t *product_create(
    char *availability,
    char *barcode,
    char *brand,
    char *category_id,
    char *condition,
    char *default_ledger_account,
    char *default_price,
    char *default_price_formula_id,
    char *default_tax_rate,
    char *description,
    char *gtin,
    char *height,
    char *image_link,
    any_type_t *images,
    int *is_taxable,
    char *length,
    char *link,
    long *max_stock,
    long *min_stock,
    char *mpn,
    char *name,
    char *package_height,
    char *package_length,
    char *package_weight_unit,
    char *package_weight_value,
    char *package_width,
    char *product_code,
    char *product_type,
    char *purchase_price,
    long *reorder_quantity,
    char *sale_price,
    char *shipping_price,
    int *shipping_requires_insurance,
    char *sku,
    long *stock_quantity,
    any_type_t *tags,
    char *tax_price,
    int *track_batch,
    int *track_serial,
    any_type_t *unit,
    char *weight_unit,
    char *weight_value,
    char *width
    ) {
    int *is_taxable_copy = NULL;
    if (is_taxable) {
        is_taxable_copy = malloc(sizeof(int));
        if (is_taxable_copy) *is_taxable_copy = *is_taxable;
    }
    long *max_stock_copy = NULL;
    if (max_stock) {
        max_stock_copy = malloc(sizeof(long));
        if (max_stock_copy) *max_stock_copy = *max_stock;
    }
    long *min_stock_copy = NULL;
    if (min_stock) {
        min_stock_copy = malloc(sizeof(long));
        if (min_stock_copy) *min_stock_copy = *min_stock;
    }
    long *reorder_quantity_copy = NULL;
    if (reorder_quantity) {
        reorder_quantity_copy = malloc(sizeof(long));
        if (reorder_quantity_copy) *reorder_quantity_copy = *reorder_quantity;
    }
    int *shipping_requires_insurance_copy = NULL;
    if (shipping_requires_insurance) {
        shipping_requires_insurance_copy = malloc(sizeof(int));
        if (shipping_requires_insurance_copy) *shipping_requires_insurance_copy = *shipping_requires_insurance;
    }
    long *stock_quantity_copy = NULL;
    if (stock_quantity) {
        stock_quantity_copy = malloc(sizeof(long));
        if (stock_quantity_copy) *stock_quantity_copy = *stock_quantity;
    }
    int *track_batch_copy = NULL;
    if (track_batch) {
        track_batch_copy = malloc(sizeof(int));
        if (track_batch_copy) *track_batch_copy = *track_batch;
    }
    int *track_serial_copy = NULL;
    if (track_serial) {
        track_serial_copy = malloc(sizeof(int));
        if (track_serial_copy) *track_serial_copy = *track_serial;
    }
    product_t *result = product_create_internal (
        availability,
        barcode,
        brand,
        category_id,
        condition,
        default_ledger_account,
        default_price,
        default_price_formula_id,
        default_tax_rate,
        description,
        gtin,
        height,
        image_link,
        images,
        is_taxable_copy,
        length,
        link,
        max_stock_copy,
        min_stock_copy,
        mpn,
        name,
        package_height,
        package_length,
        package_weight_unit,
        package_weight_value,
        package_width,
        product_code,
        product_type,
        purchase_price,
        reorder_quantity_copy,
        sale_price,
        shipping_price,
        shipping_requires_insurance_copy,
        sku,
        stock_quantity_copy,
        tags,
        tax_price,
        track_batch_copy,
        track_serial_copy,
        unit,
        weight_unit,
        weight_value,
        width
        );
    if (!result) {
        free(is_taxable_copy);
        free(max_stock_copy);
        free(min_stock_copy);
        free(reorder_quantity_copy);
        free(shipping_requires_insurance_copy);
        free(stock_quantity_copy);
        free(track_batch_copy);
        free(track_serial_copy);
    }
    return result;
}

void product_free(product_t *product) {
    if(NULL == product){
        return ;
    }
    if(product->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "product_free");
        return ;
    }
    listEntry_t *listEntry;
    if (product->availability) {
        free(product->availability);
        product->availability = NULL;
    }
    if (product->barcode) {
        free(product->barcode);
        product->barcode = NULL;
    }
    if (product->brand) {
        free(product->brand);
        product->brand = NULL;
    }
    if (product->category_id) {
        free(product->category_id);
        product->category_id = NULL;
    }
    if (product->condition) {
        free(product->condition);
        product->condition = NULL;
    }
    if (product->default_ledger_account) {
        free(product->default_ledger_account);
        product->default_ledger_account = NULL;
    }
    if (product->default_price) {
        free(product->default_price);
        product->default_price = NULL;
    }
    if (product->default_price_formula_id) {
        free(product->default_price_formula_id);
        product->default_price_formula_id = NULL;
    }
    if (product->default_tax_rate) {
        free(product->default_tax_rate);
        product->default_tax_rate = NULL;
    }
    if (product->description) {
        free(product->description);
        product->description = NULL;
    }
    if (product->gtin) {
        free(product->gtin);
        product->gtin = NULL;
    }
    if (product->height) {
        free(product->height);
        product->height = NULL;
    }
    if (product->image_link) {
        free(product->image_link);
        product->image_link = NULL;
    }
    if (product->images) {
        _free(product->images);
        product->images = NULL;
    }
    if (product->is_taxable) {
        free(product->is_taxable);
        product->is_taxable = NULL;
    }
    if (product->length) {
        free(product->length);
        product->length = NULL;
    }
    if (product->link) {
        free(product->link);
        product->link = NULL;
    }
    if (product->max_stock) {
        free(product->max_stock);
        product->max_stock = NULL;
    }
    if (product->min_stock) {
        free(product->min_stock);
        product->min_stock = NULL;
    }
    if (product->mpn) {
        free(product->mpn);
        product->mpn = NULL;
    }
    if (product->name) {
        free(product->name);
        product->name = NULL;
    }
    if (product->package_height) {
        free(product->package_height);
        product->package_height = NULL;
    }
    if (product->package_length) {
        free(product->package_length);
        product->package_length = NULL;
    }
    if (product->package_weight_unit) {
        free(product->package_weight_unit);
        product->package_weight_unit = NULL;
    }
    if (product->package_weight_value) {
        free(product->package_weight_value);
        product->package_weight_value = NULL;
    }
    if (product->package_width) {
        free(product->package_width);
        product->package_width = NULL;
    }
    if (product->product_code) {
        free(product->product_code);
        product->product_code = NULL;
    }
    if (product->product_type) {
        free(product->product_type);
        product->product_type = NULL;
    }
    if (product->purchase_price) {
        free(product->purchase_price);
        product->purchase_price = NULL;
    }
    if (product->reorder_quantity) {
        free(product->reorder_quantity);
        product->reorder_quantity = NULL;
    }
    if (product->sale_price) {
        free(product->sale_price);
        product->sale_price = NULL;
    }
    if (product->shipping_price) {
        free(product->shipping_price);
        product->shipping_price = NULL;
    }
    if (product->shipping_requires_insurance) {
        free(product->shipping_requires_insurance);
        product->shipping_requires_insurance = NULL;
    }
    if (product->sku) {
        free(product->sku);
        product->sku = NULL;
    }
    if (product->stock_quantity) {
        free(product->stock_quantity);
        product->stock_quantity = NULL;
    }
    if (product->tags) {
        _free(product->tags);
        product->tags = NULL;
    }
    if (product->tax_price) {
        free(product->tax_price);
        product->tax_price = NULL;
    }
    if (product->track_batch) {
        free(product->track_batch);
        product->track_batch = NULL;
    }
    if (product->track_serial) {
        free(product->track_serial);
        product->track_serial = NULL;
    }
    if (product->unit) {
        _free(product->unit);
        product->unit = NULL;
    }
    if (product->weight_unit) {
        free(product->weight_unit);
        product->weight_unit = NULL;
    }
    if (product->weight_value) {
        free(product->weight_value);
        product->weight_value = NULL;
    }
    if (product->width) {
        free(product->width);
        product->width = NULL;
    }
    free(product);
}

cJSON *product_convertToJSON(product_t *product) {
    cJSON *item = cJSON_CreateObject();

    // product->availability
    if(product->availability) {
    if(cJSON_AddStringToObject(item, "availability", product->availability) == NULL) {
    goto fail; //String
    }
    }


    // product->barcode
    if(product->barcode) {
    if(cJSON_AddStringToObject(item, "barcode", product->barcode) == NULL) {
    goto fail; //String
    }
    }


    // product->brand
    if(product->brand) {
    if(cJSON_AddStringToObject(item, "brand", product->brand) == NULL) {
    goto fail; //String
    }
    }


    // product->category_id
    if(product->category_id) {
    if(cJSON_AddStringToObject(item, "categoryId", product->category_id) == NULL) {
    goto fail; //String
    }
    }


    // product->condition
    if(product->condition) {
    if(cJSON_AddStringToObject(item, "condition", product->condition) == NULL) {
    goto fail; //String
    }
    }


    // product->default_ledger_account
    if(product->default_ledger_account) {
    if(cJSON_AddStringToObject(item, "defaultLedgerAccount", product->default_ledger_account) == NULL) {
    goto fail; //String
    }
    }


    // product->default_price
    if(product->default_price) {
    if(cJSON_AddStringToObject(item, "defaultPrice", product->default_price) == NULL) {
    goto fail; //String
    }
    }


    // product->default_price_formula_id
    if(product->default_price_formula_id) {
    if(cJSON_AddStringToObject(item, "defaultPriceFormulaId", product->default_price_formula_id) == NULL) {
    goto fail; //String
    }
    }


    // product->default_tax_rate
    if(product->default_tax_rate) {
    if(cJSON_AddStringToObject(item, "defaultTaxRate", product->default_tax_rate) == NULL) {
    goto fail; //String
    }
    }


    // product->description
    if(product->description) {
    if(cJSON_AddStringToObject(item, "description", product->description) == NULL) {
    goto fail; //String
    }
    }


    // product->gtin
    if(product->gtin) {
    if(cJSON_AddStringToObject(item, "gtin", product->gtin) == NULL) {
    goto fail; //String
    }
    }


    // product->height
    if(product->height) {
    if(cJSON_AddStringToObject(item, "height", product->height) == NULL) {
    goto fail; //String
    }
    }


    // product->image_link
    if(product->image_link) {
    if(cJSON_AddStringToObject(item, "imageLink", product->image_link) == NULL) {
    goto fail; //String
    }
    }


    // product->images
    if(product->images) {
    cJSON *images_local_JSON = _convertToJSON(product->images);
    if(images_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "images", images_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // product->is_taxable
    if(product->is_taxable) {
    if(cJSON_AddBoolToObject(item, "isTaxable", *product->is_taxable) == NULL) {
    goto fail; //Bool
    }
    }


    // product->length
    if(product->length) {
    if(cJSON_AddStringToObject(item, "length", product->length) == NULL) {
    goto fail; //String
    }
    }


    // product->link
    if(product->link) {
    if(cJSON_AddStringToObject(item, "link", product->link) == NULL) {
    goto fail; //String
    }
    }


    // product->max_stock
    if(product->max_stock) {
    if(cJSON_AddNumberToObject(item, "maxStock", *product->max_stock) == NULL) {
    goto fail; //Numeric
    }
    }


    // product->min_stock
    if(product->min_stock) {
    if(cJSON_AddNumberToObject(item, "minStock", *product->min_stock) == NULL) {
    goto fail; //Numeric
    }
    }


    // product->mpn
    if(product->mpn) {
    if(cJSON_AddStringToObject(item, "mpn", product->mpn) == NULL) {
    goto fail; //String
    }
    }


    // product->name
    if (!product->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", product->name) == NULL) {
    goto fail; //String
    }


    // product->package_height
    if(product->package_height) {
    if(cJSON_AddStringToObject(item, "packageHeight", product->package_height) == NULL) {
    goto fail; //String
    }
    }


    // product->package_length
    if(product->package_length) {
    if(cJSON_AddStringToObject(item, "packageLength", product->package_length) == NULL) {
    goto fail; //String
    }
    }


    // product->package_weight_unit
    if(product->package_weight_unit) {
    if(cJSON_AddStringToObject(item, "packageWeightUnit", product->package_weight_unit) == NULL) {
    goto fail; //String
    }
    }


    // product->package_weight_value
    if(product->package_weight_value) {
    if(cJSON_AddStringToObject(item, "packageWeightValue", product->package_weight_value) == NULL) {
    goto fail; //String
    }
    }


    // product->package_width
    if(product->package_width) {
    if(cJSON_AddStringToObject(item, "packageWidth", product->package_width) == NULL) {
    goto fail; //String
    }
    }


    // product->product_code
    if (!product->product_code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productCode", product->product_code) == NULL) {
    goto fail; //String
    }


    // product->product_type
    if(product->product_type) {
    if(cJSON_AddStringToObject(item, "productType", product->product_type) == NULL) {
    goto fail; //String
    }
    }


    // product->purchase_price
    if(product->purchase_price) {
    if(cJSON_AddStringToObject(item, "purchasePrice", product->purchase_price) == NULL) {
    goto fail; //String
    }
    }


    // product->reorder_quantity
    if(product->reorder_quantity) {
    if(cJSON_AddNumberToObject(item, "reorderQuantity", *product->reorder_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // product->sale_price
    if(product->sale_price) {
    if(cJSON_AddStringToObject(item, "salePrice", product->sale_price) == NULL) {
    goto fail; //String
    }
    }


    // product->shipping_price
    if(product->shipping_price) {
    if(cJSON_AddStringToObject(item, "shippingPrice", product->shipping_price) == NULL) {
    goto fail; //String
    }
    }


    // product->shipping_requires_insurance
    if(product->shipping_requires_insurance) {
    if(cJSON_AddBoolToObject(item, "shippingRequiresInsurance", *product->shipping_requires_insurance) == NULL) {
    goto fail; //Bool
    }
    }


    // product->sku
    if (!product->sku) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sku", product->sku) == NULL) {
    goto fail; //String
    }


    // product->stock_quantity
    if(product->stock_quantity) {
    if(cJSON_AddNumberToObject(item, "stockQuantity", *product->stock_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // product->tags
    if(product->tags) {
    cJSON *tags_local_JSON = _convertToJSON(product->tags);
    if(tags_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "tags", tags_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // product->tax_price
    if(product->tax_price) {
    if(cJSON_AddStringToObject(item, "taxPrice", product->tax_price) == NULL) {
    goto fail; //String
    }
    }


    // product->track_batch
    if(product->track_batch) {
    if(cJSON_AddBoolToObject(item, "trackBatch", *product->track_batch) == NULL) {
    goto fail; //Bool
    }
    }


    // product->track_serial
    if(product->track_serial) {
    if(cJSON_AddBoolToObject(item, "trackSerial", *product->track_serial) == NULL) {
    goto fail; //Bool
    }
    }


    // product->unit
    if(product->unit) {
    cJSON *unit_local_JSON = _convertToJSON(product->unit);
    if(unit_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "unit", unit_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // product->weight_unit
    if(product->weight_unit) {
    if(cJSON_AddStringToObject(item, "weightUnit", product->weight_unit) == NULL) {
    goto fail; //String
    }
    }


    // product->weight_value
    if(product->weight_value) {
    if(cJSON_AddStringToObject(item, "weightValue", product->weight_value) == NULL) {
    goto fail; //String
    }
    }


    // product->width
    if(product->width) {
    if(cJSON_AddStringToObject(item, "width", product->width) == NULL) {
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

product_t *product_parseFromJSON(cJSON *productJSON){

    product_t *product_local_var = NULL;

    char *availability_local_str = NULL;

    char *barcode_local_str = NULL;

    char *brand_local_str = NULL;

    char *category_id_local_str = NULL;

    char *condition_local_str = NULL;

    char *default_ledger_account_local_str = NULL;

    char *default_price_local_str = NULL;

    char *default_price_formula_id_local_str = NULL;

    char *default_tax_rate_local_str = NULL;

    char *description_local_str = NULL;

    char *gtin_local_str = NULL;

    char *height_local_str = NULL;

    char *image_link_local_str = NULL;

    // define the local variable for product->images
    _t *images_local_nonprim = NULL;

    // define the local variable for product->is_taxable
    int *is_taxable_local_var = NULL;

    char *length_local_str = NULL;

    char *link_local_str = NULL;

    // define the local variable for product->max_stock
    long *max_stock_local_var = NULL;

    // define the local variable for product->min_stock
    long *min_stock_local_var = NULL;

    char *mpn_local_str = NULL;

    char *name_local_str = NULL;

    char *package_height_local_str = NULL;

    char *package_length_local_str = NULL;

    char *package_weight_unit_local_str = NULL;

    char *package_weight_value_local_str = NULL;

    char *package_width_local_str = NULL;

    char *product_code_local_str = NULL;

    char *product_type_local_str = NULL;

    char *purchase_price_local_str = NULL;

    // define the local variable for product->reorder_quantity
    long *reorder_quantity_local_var = NULL;

    char *sale_price_local_str = NULL;

    char *shipping_price_local_str = NULL;

    // define the local variable for product->shipping_requires_insurance
    int *shipping_requires_insurance_local_var = NULL;

    char *sku_local_str = NULL;

    // define the local variable for product->stock_quantity
    long *stock_quantity_local_var = NULL;

    // define the local variable for product->tags
    _t *tags_local_nonprim = NULL;

    char *tax_price_local_str = NULL;

    // define the local variable for product->track_batch
    int *track_batch_local_var = NULL;

    // define the local variable for product->track_serial
    int *track_serial_local_var = NULL;

    // define the local variable for product->unit
    _t *unit_local_nonprim = NULL;

    char *weight_unit_local_str = NULL;

    char *weight_value_local_str = NULL;

    char *width_local_str = NULL;

    // product->availability
    cJSON *availability = cJSON_GetObjectItemCaseSensitive(productJSON, "availability");
    if (cJSON_IsNull(availability)) {
        availability = NULL;
    }
    if (availability) { 
    if(!cJSON_IsString(availability) && !cJSON_IsNull(availability))
    {
    goto end; //String
    }
    }

    // product->barcode
    cJSON *barcode = cJSON_GetObjectItemCaseSensitive(productJSON, "barcode");
    if (cJSON_IsNull(barcode)) {
        barcode = NULL;
    }
    if (barcode) { 
    if(!cJSON_IsString(barcode) && !cJSON_IsNull(barcode))
    {
    goto end; //String
    }
    }

    // product->brand
    cJSON *brand = cJSON_GetObjectItemCaseSensitive(productJSON, "brand");
    if (cJSON_IsNull(brand)) {
        brand = NULL;
    }
    if (brand) { 
    if(!cJSON_IsString(brand) && !cJSON_IsNull(brand))
    {
    goto end; //String
    }
    }

    // product->category_id
    cJSON *category_id = cJSON_GetObjectItemCaseSensitive(productJSON, "categoryId");
    if (cJSON_IsNull(category_id)) {
        category_id = NULL;
    }
    if (category_id) { 
    if(!cJSON_IsString(category_id) && !cJSON_IsNull(category_id))
    {
    goto end; //String
    }
    }

    // product->condition
    cJSON *condition = cJSON_GetObjectItemCaseSensitive(productJSON, "condition");
    if (cJSON_IsNull(condition)) {
        condition = NULL;
    }
    if (condition) { 
    if(!cJSON_IsString(condition) && !cJSON_IsNull(condition))
    {
    goto end; //String
    }
    }

    // product->default_ledger_account
    cJSON *default_ledger_account = cJSON_GetObjectItemCaseSensitive(productJSON, "defaultLedgerAccount");
    if (cJSON_IsNull(default_ledger_account)) {
        default_ledger_account = NULL;
    }
    if (default_ledger_account) { 
    if(!cJSON_IsString(default_ledger_account) && !cJSON_IsNull(default_ledger_account))
    {
    goto end; //String
    }
    }

    // product->default_price
    cJSON *default_price = cJSON_GetObjectItemCaseSensitive(productJSON, "defaultPrice");
    if (cJSON_IsNull(default_price)) {
        default_price = NULL;
    }
    if (default_price) { 
    if(!cJSON_IsString(default_price) && !cJSON_IsNull(default_price))
    {
    goto end; //String
    }
    }

    // product->default_price_formula_id
    cJSON *default_price_formula_id = cJSON_GetObjectItemCaseSensitive(productJSON, "defaultPriceFormulaId");
    if (cJSON_IsNull(default_price_formula_id)) {
        default_price_formula_id = NULL;
    }
    if (default_price_formula_id) { 
    if(!cJSON_IsString(default_price_formula_id) && !cJSON_IsNull(default_price_formula_id))
    {
    goto end; //String
    }
    }

    // product->default_tax_rate
    cJSON *default_tax_rate = cJSON_GetObjectItemCaseSensitive(productJSON, "defaultTaxRate");
    if (cJSON_IsNull(default_tax_rate)) {
        default_tax_rate = NULL;
    }
    if (default_tax_rate) { 
    if(!cJSON_IsString(default_tax_rate) && !cJSON_IsNull(default_tax_rate))
    {
    goto end; //String
    }
    }

    // product->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(productJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // product->gtin
    cJSON *gtin = cJSON_GetObjectItemCaseSensitive(productJSON, "gtin");
    if (cJSON_IsNull(gtin)) {
        gtin = NULL;
    }
    if (gtin) { 
    if(!cJSON_IsString(gtin) && !cJSON_IsNull(gtin))
    {
    goto end; //String
    }
    }

    // product->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(productJSON, "height");
    if (cJSON_IsNull(height)) {
        height = NULL;
    }
    if (height) { 
    if(!cJSON_IsString(height) && !cJSON_IsNull(height))
    {
    goto end; //String
    }
    }

    // product->image_link
    cJSON *image_link = cJSON_GetObjectItemCaseSensitive(productJSON, "imageLink");
    if (cJSON_IsNull(image_link)) {
        image_link = NULL;
    }
    if (image_link) { 
    if(!cJSON_IsString(image_link) && !cJSON_IsNull(image_link))
    {
    goto end; //String
    }
    }

    // product->images
    cJSON *images = cJSON_GetObjectItemCaseSensitive(productJSON, "images");
    if (cJSON_IsNull(images)) {
        images = NULL;
    }
    if (images) { 
    images_local_nonprim = _parseFromJSON(images); //custom
    }

    // product->is_taxable
    cJSON *is_taxable = cJSON_GetObjectItemCaseSensitive(productJSON, "isTaxable");
    if (cJSON_IsNull(is_taxable)) {
        is_taxable = NULL;
    }
    if (is_taxable) { 
    if(!cJSON_IsBool(is_taxable))
    {
    goto end; //Bool
    }
    is_taxable_local_var = malloc(sizeof(int));
    if(!is_taxable_local_var)
    {
        goto end;
    }
    *is_taxable_local_var = is_taxable->valueint;
    }

    // product->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(productJSON, "length");
    if (cJSON_IsNull(length)) {
        length = NULL;
    }
    if (length) { 
    if(!cJSON_IsString(length) && !cJSON_IsNull(length))
    {
    goto end; //String
    }
    }

    // product->link
    cJSON *link = cJSON_GetObjectItemCaseSensitive(productJSON, "link");
    if (cJSON_IsNull(link)) {
        link = NULL;
    }
    if (link) { 
    if(!cJSON_IsString(link) && !cJSON_IsNull(link))
    {
    goto end; //String
    }
    }

    // product->max_stock
    cJSON *max_stock = cJSON_GetObjectItemCaseSensitive(productJSON, "maxStock");
    if (cJSON_IsNull(max_stock)) {
        max_stock = NULL;
    }
    if (max_stock) { 
    if(!cJSON_IsNumber(max_stock))
    {
    goto end; //Numeric
    }
    max_stock_local_var = malloc(sizeof(long));
    if(!max_stock_local_var)
    {
        goto end;
    }
    *max_stock_local_var = max_stock->valuedouble;
    }

    // product->min_stock
    cJSON *min_stock = cJSON_GetObjectItemCaseSensitive(productJSON, "minStock");
    if (cJSON_IsNull(min_stock)) {
        min_stock = NULL;
    }
    if (min_stock) { 
    if(!cJSON_IsNumber(min_stock))
    {
    goto end; //Numeric
    }
    min_stock_local_var = malloc(sizeof(long));
    if(!min_stock_local_var)
    {
        goto end;
    }
    *min_stock_local_var = min_stock->valuedouble;
    }

    // product->mpn
    cJSON *mpn = cJSON_GetObjectItemCaseSensitive(productJSON, "mpn");
    if (cJSON_IsNull(mpn)) {
        mpn = NULL;
    }
    if (mpn) { 
    if(!cJSON_IsString(mpn) && !cJSON_IsNull(mpn))
    {
    goto end; //String
    }
    }

    // product->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(productJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // product->package_height
    cJSON *package_height = cJSON_GetObjectItemCaseSensitive(productJSON, "packageHeight");
    if (cJSON_IsNull(package_height)) {
        package_height = NULL;
    }
    if (package_height) { 
    if(!cJSON_IsString(package_height) && !cJSON_IsNull(package_height))
    {
    goto end; //String
    }
    }

    // product->package_length
    cJSON *package_length = cJSON_GetObjectItemCaseSensitive(productJSON, "packageLength");
    if (cJSON_IsNull(package_length)) {
        package_length = NULL;
    }
    if (package_length) { 
    if(!cJSON_IsString(package_length) && !cJSON_IsNull(package_length))
    {
    goto end; //String
    }
    }

    // product->package_weight_unit
    cJSON *package_weight_unit = cJSON_GetObjectItemCaseSensitive(productJSON, "packageWeightUnit");
    if (cJSON_IsNull(package_weight_unit)) {
        package_weight_unit = NULL;
    }
    if (package_weight_unit) { 
    if(!cJSON_IsString(package_weight_unit) && !cJSON_IsNull(package_weight_unit))
    {
    goto end; //String
    }
    }

    // product->package_weight_value
    cJSON *package_weight_value = cJSON_GetObjectItemCaseSensitive(productJSON, "packageWeightValue");
    if (cJSON_IsNull(package_weight_value)) {
        package_weight_value = NULL;
    }
    if (package_weight_value) { 
    if(!cJSON_IsString(package_weight_value) && !cJSON_IsNull(package_weight_value))
    {
    goto end; //String
    }
    }

    // product->package_width
    cJSON *package_width = cJSON_GetObjectItemCaseSensitive(productJSON, "packageWidth");
    if (cJSON_IsNull(package_width)) {
        package_width = NULL;
    }
    if (package_width) { 
    if(!cJSON_IsString(package_width) && !cJSON_IsNull(package_width))
    {
    goto end; //String
    }
    }

    // product->product_code
    cJSON *product_code = cJSON_GetObjectItemCaseSensitive(productJSON, "productCode");
    if (cJSON_IsNull(product_code)) {
        product_code = NULL;
    }
    if (!product_code) {
        goto end;
    }

    
    if(!cJSON_IsString(product_code))
    {
    goto end; //String
    }

    // product->product_type
    cJSON *product_type = cJSON_GetObjectItemCaseSensitive(productJSON, "productType");
    if (cJSON_IsNull(product_type)) {
        product_type = NULL;
    }
    if (product_type) { 
    if(!cJSON_IsString(product_type) && !cJSON_IsNull(product_type))
    {
    goto end; //String
    }
    }

    // product->purchase_price
    cJSON *purchase_price = cJSON_GetObjectItemCaseSensitive(productJSON, "purchasePrice");
    if (cJSON_IsNull(purchase_price)) {
        purchase_price = NULL;
    }
    if (purchase_price) { 
    if(!cJSON_IsString(purchase_price) && !cJSON_IsNull(purchase_price))
    {
    goto end; //String
    }
    }

    // product->reorder_quantity
    cJSON *reorder_quantity = cJSON_GetObjectItemCaseSensitive(productJSON, "reorderQuantity");
    if (cJSON_IsNull(reorder_quantity)) {
        reorder_quantity = NULL;
    }
    if (reorder_quantity) { 
    if(!cJSON_IsNumber(reorder_quantity))
    {
    goto end; //Numeric
    }
    reorder_quantity_local_var = malloc(sizeof(long));
    if(!reorder_quantity_local_var)
    {
        goto end;
    }
    *reorder_quantity_local_var = reorder_quantity->valuedouble;
    }

    // product->sale_price
    cJSON *sale_price = cJSON_GetObjectItemCaseSensitive(productJSON, "salePrice");
    if (cJSON_IsNull(sale_price)) {
        sale_price = NULL;
    }
    if (sale_price) { 
    if(!cJSON_IsString(sale_price) && !cJSON_IsNull(sale_price))
    {
    goto end; //String
    }
    }

    // product->shipping_price
    cJSON *shipping_price = cJSON_GetObjectItemCaseSensitive(productJSON, "shippingPrice");
    if (cJSON_IsNull(shipping_price)) {
        shipping_price = NULL;
    }
    if (shipping_price) { 
    if(!cJSON_IsString(shipping_price) && !cJSON_IsNull(shipping_price))
    {
    goto end; //String
    }
    }

    // product->shipping_requires_insurance
    cJSON *shipping_requires_insurance = cJSON_GetObjectItemCaseSensitive(productJSON, "shippingRequiresInsurance");
    if (cJSON_IsNull(shipping_requires_insurance)) {
        shipping_requires_insurance = NULL;
    }
    if (shipping_requires_insurance) { 
    if(!cJSON_IsBool(shipping_requires_insurance))
    {
    goto end; //Bool
    }
    shipping_requires_insurance_local_var = malloc(sizeof(int));
    if(!shipping_requires_insurance_local_var)
    {
        goto end;
    }
    *shipping_requires_insurance_local_var = shipping_requires_insurance->valueint;
    }

    // product->sku
    cJSON *sku = cJSON_GetObjectItemCaseSensitive(productJSON, "sku");
    if (cJSON_IsNull(sku)) {
        sku = NULL;
    }
    if (!sku) {
        goto end;
    }

    
    if(!cJSON_IsString(sku))
    {
    goto end; //String
    }

    // product->stock_quantity
    cJSON *stock_quantity = cJSON_GetObjectItemCaseSensitive(productJSON, "stockQuantity");
    if (cJSON_IsNull(stock_quantity)) {
        stock_quantity = NULL;
    }
    if (stock_quantity) { 
    if(!cJSON_IsNumber(stock_quantity))
    {
    goto end; //Numeric
    }
    stock_quantity_local_var = malloc(sizeof(long));
    if(!stock_quantity_local_var)
    {
        goto end;
    }
    *stock_quantity_local_var = stock_quantity->valuedouble;
    }

    // product->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(productJSON, "tags");
    if (cJSON_IsNull(tags)) {
        tags = NULL;
    }
    if (tags) { 
    tags_local_nonprim = _parseFromJSON(tags); //custom
    }

    // product->tax_price
    cJSON *tax_price = cJSON_GetObjectItemCaseSensitive(productJSON, "taxPrice");
    if (cJSON_IsNull(tax_price)) {
        tax_price = NULL;
    }
    if (tax_price) { 
    if(!cJSON_IsString(tax_price) && !cJSON_IsNull(tax_price))
    {
    goto end; //String
    }
    }

    // product->track_batch
    cJSON *track_batch = cJSON_GetObjectItemCaseSensitive(productJSON, "trackBatch");
    if (cJSON_IsNull(track_batch)) {
        track_batch = NULL;
    }
    if (track_batch) { 
    if(!cJSON_IsBool(track_batch))
    {
    goto end; //Bool
    }
    track_batch_local_var = malloc(sizeof(int));
    if(!track_batch_local_var)
    {
        goto end;
    }
    *track_batch_local_var = track_batch->valueint;
    }

    // product->track_serial
    cJSON *track_serial = cJSON_GetObjectItemCaseSensitive(productJSON, "trackSerial");
    if (cJSON_IsNull(track_serial)) {
        track_serial = NULL;
    }
    if (track_serial) { 
    if(!cJSON_IsBool(track_serial))
    {
    goto end; //Bool
    }
    track_serial_local_var = malloc(sizeof(int));
    if(!track_serial_local_var)
    {
        goto end;
    }
    *track_serial_local_var = track_serial->valueint;
    }

    // product->unit
    cJSON *unit = cJSON_GetObjectItemCaseSensitive(productJSON, "unit");
    if (cJSON_IsNull(unit)) {
        unit = NULL;
    }
    if (unit) { 
    unit_local_nonprim = _parseFromJSON(unit); //custom
    }

    // product->weight_unit
    cJSON *weight_unit = cJSON_GetObjectItemCaseSensitive(productJSON, "weightUnit");
    if (cJSON_IsNull(weight_unit)) {
        weight_unit = NULL;
    }
    if (weight_unit) { 
    if(!cJSON_IsString(weight_unit) && !cJSON_IsNull(weight_unit))
    {
    goto end; //String
    }
    }

    // product->weight_value
    cJSON *weight_value = cJSON_GetObjectItemCaseSensitive(productJSON, "weightValue");
    if (cJSON_IsNull(weight_value)) {
        weight_value = NULL;
    }
    if (weight_value) { 
    if(!cJSON_IsString(weight_value) && !cJSON_IsNull(weight_value))
    {
    goto end; //String
    }
    }

    // product->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(productJSON, "width");
    if (cJSON_IsNull(width)) {
        width = NULL;
    }
    if (width) { 
    if(!cJSON_IsString(width) && !cJSON_IsNull(width))
    {
    goto end; //String
    }
    }


    if (availability && !cJSON_IsNull(availability)) availability_local_str = strdup(availability->valuestring);
    if (barcode && !cJSON_IsNull(barcode)) barcode_local_str = strdup(barcode->valuestring);
    if (brand && !cJSON_IsNull(brand)) brand_local_str = strdup(brand->valuestring);
    if (category_id && !cJSON_IsNull(category_id)) category_id_local_str = strdup(category_id->valuestring);
    if (condition && !cJSON_IsNull(condition)) condition_local_str = strdup(condition->valuestring);
    if (default_ledger_account && !cJSON_IsNull(default_ledger_account)) default_ledger_account_local_str = strdup(default_ledger_account->valuestring);
    if (default_price && !cJSON_IsNull(default_price)) default_price_local_str = strdup(default_price->valuestring);
    if (default_price_formula_id && !cJSON_IsNull(default_price_formula_id)) default_price_formula_id_local_str = strdup(default_price_formula_id->valuestring);
    if (default_tax_rate && !cJSON_IsNull(default_tax_rate)) default_tax_rate_local_str = strdup(default_tax_rate->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (gtin && !cJSON_IsNull(gtin)) gtin_local_str = strdup(gtin->valuestring);
    if (height && !cJSON_IsNull(height)) height_local_str = strdup(height->valuestring);
    if (image_link && !cJSON_IsNull(image_link)) image_link_local_str = strdup(image_link->valuestring);
    if (length && !cJSON_IsNull(length)) length_local_str = strdup(length->valuestring);
    if (link && !cJSON_IsNull(link)) link_local_str = strdup(link->valuestring);
    if (mpn && !cJSON_IsNull(mpn)) mpn_local_str = strdup(mpn->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (package_height && !cJSON_IsNull(package_height)) package_height_local_str = strdup(package_height->valuestring);
    if (package_length && !cJSON_IsNull(package_length)) package_length_local_str = strdup(package_length->valuestring);
    if (package_weight_unit && !cJSON_IsNull(package_weight_unit)) package_weight_unit_local_str = strdup(package_weight_unit->valuestring);
    if (package_weight_value && !cJSON_IsNull(package_weight_value)) package_weight_value_local_str = strdup(package_weight_value->valuestring);
    if (package_width && !cJSON_IsNull(package_width)) package_width_local_str = strdup(package_width->valuestring);
    if (product_code && !cJSON_IsNull(product_code)) product_code_local_str = strdup(product_code->valuestring);
    if (product_type && !cJSON_IsNull(product_type)) product_type_local_str = strdup(product_type->valuestring);
    if (purchase_price && !cJSON_IsNull(purchase_price)) purchase_price_local_str = strdup(purchase_price->valuestring);
    if (sale_price && !cJSON_IsNull(sale_price)) sale_price_local_str = strdup(sale_price->valuestring);
    if (shipping_price && !cJSON_IsNull(shipping_price)) shipping_price_local_str = strdup(shipping_price->valuestring);
    if (sku && !cJSON_IsNull(sku)) sku_local_str = strdup(sku->valuestring);
    if (tax_price && !cJSON_IsNull(tax_price)) tax_price_local_str = strdup(tax_price->valuestring);
    if (weight_unit && !cJSON_IsNull(weight_unit)) weight_unit_local_str = strdup(weight_unit->valuestring);
    if (weight_value && !cJSON_IsNull(weight_value)) weight_value_local_str = strdup(weight_value->valuestring);
    if (width && !cJSON_IsNull(width)) width_local_str = strdup(width->valuestring);

    product_local_var = product_create_internal (
        availability_local_str,
        barcode_local_str,
        brand_local_str,
        category_id_local_str,
        condition_local_str,
        default_ledger_account_local_str,
        default_price_local_str,
        default_price_formula_id_local_str,
        default_tax_rate_local_str,
        description_local_str,
        gtin_local_str,
        height_local_str,
        image_link_local_str,
        images ? images_local_nonprim : NULL,
        is_taxable_local_var,
        length_local_str,
        link_local_str,
        max_stock_local_var,
        min_stock_local_var,
        mpn_local_str,
        name_local_str,
        package_height_local_str,
        package_length_local_str,
        package_weight_unit_local_str,
        package_weight_value_local_str,
        package_width_local_str,
        product_code_local_str,
        product_type_local_str,
        purchase_price_local_str,
        reorder_quantity_local_var,
        sale_price_local_str,
        shipping_price_local_str,
        shipping_requires_insurance_local_var,
        sku_local_str,
        stock_quantity_local_var,
        tags ? tags_local_nonprim : NULL,
        tax_price_local_str,
        track_batch_local_var,
        track_serial_local_var,
        unit ? unit_local_nonprim : NULL,
        weight_unit_local_str,
        weight_value_local_str,
        width_local_str
        );

    if (!product_local_var) {
        goto end;
    }

    return product_local_var;
end:
    if (availability_local_str) {
        free(availability_local_str);
        availability_local_str = NULL;
    }
    if (barcode_local_str) {
        free(barcode_local_str);
        barcode_local_str = NULL;
    }
    if (brand_local_str) {
        free(brand_local_str);
        brand_local_str = NULL;
    }
    if (category_id_local_str) {
        free(category_id_local_str);
        category_id_local_str = NULL;
    }
    if (condition_local_str) {
        free(condition_local_str);
        condition_local_str = NULL;
    }
    if (default_ledger_account_local_str) {
        free(default_ledger_account_local_str);
        default_ledger_account_local_str = NULL;
    }
    if (default_price_local_str) {
        free(default_price_local_str);
        default_price_local_str = NULL;
    }
    if (default_price_formula_id_local_str) {
        free(default_price_formula_id_local_str);
        default_price_formula_id_local_str = NULL;
    }
    if (default_tax_rate_local_str) {
        free(default_tax_rate_local_str);
        default_tax_rate_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (gtin_local_str) {
        free(gtin_local_str);
        gtin_local_str = NULL;
    }
    if (height_local_str) {
        free(height_local_str);
        height_local_str = NULL;
    }
    if (image_link_local_str) {
        free(image_link_local_str);
        image_link_local_str = NULL;
    }
    if (images_local_nonprim) {
        _free(images_local_nonprim);
        images_local_nonprim = NULL;
    }
    if (is_taxable_local_var) {
        free(is_taxable_local_var);
        is_taxable_local_var = NULL;
    }
    if (length_local_str) {
        free(length_local_str);
        length_local_str = NULL;
    }
    if (link_local_str) {
        free(link_local_str);
        link_local_str = NULL;
    }
    if (max_stock_local_var) {
        free(max_stock_local_var);
        max_stock_local_var = NULL;
    }
    if (min_stock_local_var) {
        free(min_stock_local_var);
        min_stock_local_var = NULL;
    }
    if (mpn_local_str) {
        free(mpn_local_str);
        mpn_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (package_height_local_str) {
        free(package_height_local_str);
        package_height_local_str = NULL;
    }
    if (package_length_local_str) {
        free(package_length_local_str);
        package_length_local_str = NULL;
    }
    if (package_weight_unit_local_str) {
        free(package_weight_unit_local_str);
        package_weight_unit_local_str = NULL;
    }
    if (package_weight_value_local_str) {
        free(package_weight_value_local_str);
        package_weight_value_local_str = NULL;
    }
    if (package_width_local_str) {
        free(package_width_local_str);
        package_width_local_str = NULL;
    }
    if (product_code_local_str) {
        free(product_code_local_str);
        product_code_local_str = NULL;
    }
    if (product_type_local_str) {
        free(product_type_local_str);
        product_type_local_str = NULL;
    }
    if (purchase_price_local_str) {
        free(purchase_price_local_str);
        purchase_price_local_str = NULL;
    }
    if (reorder_quantity_local_var) {
        free(reorder_quantity_local_var);
        reorder_quantity_local_var = NULL;
    }
    if (sale_price_local_str) {
        free(sale_price_local_str);
        sale_price_local_str = NULL;
    }
    if (shipping_price_local_str) {
        free(shipping_price_local_str);
        shipping_price_local_str = NULL;
    }
    if (shipping_requires_insurance_local_var) {
        free(shipping_requires_insurance_local_var);
        shipping_requires_insurance_local_var = NULL;
    }
    if (sku_local_str) {
        free(sku_local_str);
        sku_local_str = NULL;
    }
    if (stock_quantity_local_var) {
        free(stock_quantity_local_var);
        stock_quantity_local_var = NULL;
    }
    if (tags_local_nonprim) {
        _free(tags_local_nonprim);
        tags_local_nonprim = NULL;
    }
    if (tax_price_local_str) {
        free(tax_price_local_str);
        tax_price_local_str = NULL;
    }
    if (track_batch_local_var) {
        free(track_batch_local_var);
        track_batch_local_var = NULL;
    }
    if (track_serial_local_var) {
        free(track_serial_local_var);
        track_serial_local_var = NULL;
    }
    if (unit_local_nonprim) {
        _free(unit_local_nonprim);
        unit_local_nonprim = NULL;
    }
    if (weight_unit_local_str) {
        free(weight_unit_local_str);
        weight_unit_local_str = NULL;
    }
    if (weight_value_local_str) {
        free(weight_value_local_str);
        weight_value_local_str = NULL;
    }
    if (width_local_str) {
        free(width_local_str);
        width_local_str = NULL;
    }
    return NULL;

}
