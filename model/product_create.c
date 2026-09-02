#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "product_create.h"



static product_create_t *product_create_create_internal(
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
    product_create_t *product_create_local_var = malloc(sizeof(product_create_t));
    if (!product_create_local_var) {
        return NULL;
    }
    memset(product_create_local_var, 0, sizeof(product_create_t));
    product_create_local_var->_library_owned = 1;
    product_create_local_var->availability = availability;
    product_create_local_var->barcode = barcode;
    product_create_local_var->brand = brand;
    product_create_local_var->category_id = category_id;
    product_create_local_var->condition = condition;
    product_create_local_var->default_ledger_account = default_ledger_account;
    product_create_local_var->default_price = default_price;
    product_create_local_var->default_price_formula_id = default_price_formula_id;
    product_create_local_var->default_tax_rate = default_tax_rate;
    product_create_local_var->description = description;
    product_create_local_var->gtin = gtin;
    product_create_local_var->height = height;
    product_create_local_var->image_link = image_link;
    product_create_local_var->images = images;
    product_create_local_var->is_taxable = is_taxable;
    product_create_local_var->length = length;
    product_create_local_var->link = link;
    product_create_local_var->max_stock = max_stock;
    product_create_local_var->min_stock = min_stock;
    product_create_local_var->mpn = mpn;
    product_create_local_var->name = name;
    product_create_local_var->package_height = package_height;
    product_create_local_var->package_length = package_length;
    product_create_local_var->package_weight_unit = package_weight_unit;
    product_create_local_var->package_weight_value = package_weight_value;
    product_create_local_var->package_width = package_width;
    product_create_local_var->product_code = product_code;
    product_create_local_var->product_type = product_type;
    product_create_local_var->purchase_price = purchase_price;
    product_create_local_var->reorder_quantity = reorder_quantity;
    product_create_local_var->sale_price = sale_price;
    product_create_local_var->shipping_price = shipping_price;
    product_create_local_var->shipping_requires_insurance = shipping_requires_insurance;
    product_create_local_var->sku = sku;
    product_create_local_var->stock_quantity = stock_quantity;
    product_create_local_var->tags = tags;
    product_create_local_var->tax_price = tax_price;
    product_create_local_var->track_batch = track_batch;
    product_create_local_var->track_serial = track_serial;
    product_create_local_var->unit = unit;
    product_create_local_var->weight_unit = weight_unit;
    product_create_local_var->weight_value = weight_value;
    product_create_local_var->width = width;
    return product_create_local_var;
}

__attribute__((deprecated)) product_create_t *product_create_create(
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
    product_create_t *result = product_create_create_internal (
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

void product_create_free(product_create_t *product_create) {
    if(NULL == product_create){
        return ;
    }
    if(product_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "product_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (product_create->availability) {
        free(product_create->availability);
        product_create->availability = NULL;
    }
    if (product_create->barcode) {
        free(product_create->barcode);
        product_create->barcode = NULL;
    }
    if (product_create->brand) {
        free(product_create->brand);
        product_create->brand = NULL;
    }
    if (product_create->category_id) {
        free(product_create->category_id);
        product_create->category_id = NULL;
    }
    if (product_create->condition) {
        free(product_create->condition);
        product_create->condition = NULL;
    }
    if (product_create->default_ledger_account) {
        free(product_create->default_ledger_account);
        product_create->default_ledger_account = NULL;
    }
    if (product_create->default_price) {
        free(product_create->default_price);
        product_create->default_price = NULL;
    }
    if (product_create->default_price_formula_id) {
        free(product_create->default_price_formula_id);
        product_create->default_price_formula_id = NULL;
    }
    if (product_create->default_tax_rate) {
        free(product_create->default_tax_rate);
        product_create->default_tax_rate = NULL;
    }
    if (product_create->description) {
        free(product_create->description);
        product_create->description = NULL;
    }
    if (product_create->gtin) {
        free(product_create->gtin);
        product_create->gtin = NULL;
    }
    if (product_create->height) {
        free(product_create->height);
        product_create->height = NULL;
    }
    if (product_create->image_link) {
        free(product_create->image_link);
        product_create->image_link = NULL;
    }
    if (product_create->images) {
        _free(product_create->images);
        product_create->images = NULL;
    }
    if (product_create->is_taxable) {
        free(product_create->is_taxable);
        product_create->is_taxable = NULL;
    }
    if (product_create->length) {
        free(product_create->length);
        product_create->length = NULL;
    }
    if (product_create->link) {
        free(product_create->link);
        product_create->link = NULL;
    }
    if (product_create->max_stock) {
        free(product_create->max_stock);
        product_create->max_stock = NULL;
    }
    if (product_create->min_stock) {
        free(product_create->min_stock);
        product_create->min_stock = NULL;
    }
    if (product_create->mpn) {
        free(product_create->mpn);
        product_create->mpn = NULL;
    }
    if (product_create->name) {
        free(product_create->name);
        product_create->name = NULL;
    }
    if (product_create->package_height) {
        free(product_create->package_height);
        product_create->package_height = NULL;
    }
    if (product_create->package_length) {
        free(product_create->package_length);
        product_create->package_length = NULL;
    }
    if (product_create->package_weight_unit) {
        free(product_create->package_weight_unit);
        product_create->package_weight_unit = NULL;
    }
    if (product_create->package_weight_value) {
        free(product_create->package_weight_value);
        product_create->package_weight_value = NULL;
    }
    if (product_create->package_width) {
        free(product_create->package_width);
        product_create->package_width = NULL;
    }
    if (product_create->product_code) {
        free(product_create->product_code);
        product_create->product_code = NULL;
    }
    if (product_create->product_type) {
        free(product_create->product_type);
        product_create->product_type = NULL;
    }
    if (product_create->purchase_price) {
        free(product_create->purchase_price);
        product_create->purchase_price = NULL;
    }
    if (product_create->reorder_quantity) {
        free(product_create->reorder_quantity);
        product_create->reorder_quantity = NULL;
    }
    if (product_create->sale_price) {
        free(product_create->sale_price);
        product_create->sale_price = NULL;
    }
    if (product_create->shipping_price) {
        free(product_create->shipping_price);
        product_create->shipping_price = NULL;
    }
    if (product_create->shipping_requires_insurance) {
        free(product_create->shipping_requires_insurance);
        product_create->shipping_requires_insurance = NULL;
    }
    if (product_create->sku) {
        free(product_create->sku);
        product_create->sku = NULL;
    }
    if (product_create->stock_quantity) {
        free(product_create->stock_quantity);
        product_create->stock_quantity = NULL;
    }
    if (product_create->tags) {
        _free(product_create->tags);
        product_create->tags = NULL;
    }
    if (product_create->tax_price) {
        free(product_create->tax_price);
        product_create->tax_price = NULL;
    }
    if (product_create->track_batch) {
        free(product_create->track_batch);
        product_create->track_batch = NULL;
    }
    if (product_create->track_serial) {
        free(product_create->track_serial);
        product_create->track_serial = NULL;
    }
    if (product_create->unit) {
        _free(product_create->unit);
        product_create->unit = NULL;
    }
    if (product_create->weight_unit) {
        free(product_create->weight_unit);
        product_create->weight_unit = NULL;
    }
    if (product_create->weight_value) {
        free(product_create->weight_value);
        product_create->weight_value = NULL;
    }
    if (product_create->width) {
        free(product_create->width);
        product_create->width = NULL;
    }
    free(product_create);
}

cJSON *product_create_convertToJSON(product_create_t *product_create) {
    cJSON *item = cJSON_CreateObject();

    // product_create->availability
    if(product_create->availability) {
    if(cJSON_AddStringToObject(item, "availability", product_create->availability) == NULL) {
    goto fail; //String
    }
    }


    // product_create->barcode
    if(product_create->barcode) {
    if(cJSON_AddStringToObject(item, "barcode", product_create->barcode) == NULL) {
    goto fail; //String
    }
    }


    // product_create->brand
    if(product_create->brand) {
    if(cJSON_AddStringToObject(item, "brand", product_create->brand) == NULL) {
    goto fail; //String
    }
    }


    // product_create->category_id
    if(product_create->category_id) {
    if(cJSON_AddStringToObject(item, "categoryId", product_create->category_id) == NULL) {
    goto fail; //String
    }
    }


    // product_create->condition
    if(product_create->condition) {
    if(cJSON_AddStringToObject(item, "condition", product_create->condition) == NULL) {
    goto fail; //String
    }
    }


    // product_create->default_ledger_account
    if(product_create->default_ledger_account) {
    if(cJSON_AddStringToObject(item, "defaultLedgerAccount", product_create->default_ledger_account) == NULL) {
    goto fail; //String
    }
    }


    // product_create->default_price
    if(product_create->default_price) {
    if(cJSON_AddStringToObject(item, "defaultPrice", product_create->default_price) == NULL) {
    goto fail; //String
    }
    }


    // product_create->default_price_formula_id
    if(product_create->default_price_formula_id) {
    if(cJSON_AddStringToObject(item, "defaultPriceFormulaId", product_create->default_price_formula_id) == NULL) {
    goto fail; //String
    }
    }


    // product_create->default_tax_rate
    if(product_create->default_tax_rate) {
    if(cJSON_AddStringToObject(item, "defaultTaxRate", product_create->default_tax_rate) == NULL) {
    goto fail; //String
    }
    }


    // product_create->description
    if(product_create->description) {
    if(cJSON_AddStringToObject(item, "description", product_create->description) == NULL) {
    goto fail; //String
    }
    }


    // product_create->gtin
    if(product_create->gtin) {
    if(cJSON_AddStringToObject(item, "gtin", product_create->gtin) == NULL) {
    goto fail; //String
    }
    }


    // product_create->height
    if(product_create->height) {
    if(cJSON_AddStringToObject(item, "height", product_create->height) == NULL) {
    goto fail; //String
    }
    }


    // product_create->image_link
    if(product_create->image_link) {
    if(cJSON_AddStringToObject(item, "imageLink", product_create->image_link) == NULL) {
    goto fail; //String
    }
    }


    // product_create->images
    if(product_create->images) {
    cJSON *images_local_JSON = _convertToJSON(product_create->images);
    if(images_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "images", images_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // product_create->is_taxable
    if(product_create->is_taxable) {
    if(cJSON_AddBoolToObject(item, "isTaxable", *product_create->is_taxable) == NULL) {
    goto fail; //Bool
    }
    }


    // product_create->length
    if(product_create->length) {
    if(cJSON_AddStringToObject(item, "length", product_create->length) == NULL) {
    goto fail; //String
    }
    }


    // product_create->link
    if(product_create->link) {
    if(cJSON_AddStringToObject(item, "link", product_create->link) == NULL) {
    goto fail; //String
    }
    }


    // product_create->max_stock
    if(product_create->max_stock) {
    if(cJSON_AddNumberToObject(item, "maxStock", *product_create->max_stock) == NULL) {
    goto fail; //Numeric
    }
    }


    // product_create->min_stock
    if(product_create->min_stock) {
    if(cJSON_AddNumberToObject(item, "minStock", *product_create->min_stock) == NULL) {
    goto fail; //Numeric
    }
    }


    // product_create->mpn
    if(product_create->mpn) {
    if(cJSON_AddStringToObject(item, "mpn", product_create->mpn) == NULL) {
    goto fail; //String
    }
    }


    // product_create->name
    if (!product_create->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", product_create->name) == NULL) {
    goto fail; //String
    }


    // product_create->package_height
    if(product_create->package_height) {
    if(cJSON_AddStringToObject(item, "packageHeight", product_create->package_height) == NULL) {
    goto fail; //String
    }
    }


    // product_create->package_length
    if(product_create->package_length) {
    if(cJSON_AddStringToObject(item, "packageLength", product_create->package_length) == NULL) {
    goto fail; //String
    }
    }


    // product_create->package_weight_unit
    if(product_create->package_weight_unit) {
    if(cJSON_AddStringToObject(item, "packageWeightUnit", product_create->package_weight_unit) == NULL) {
    goto fail; //String
    }
    }


    // product_create->package_weight_value
    if(product_create->package_weight_value) {
    if(cJSON_AddStringToObject(item, "packageWeightValue", product_create->package_weight_value) == NULL) {
    goto fail; //String
    }
    }


    // product_create->package_width
    if(product_create->package_width) {
    if(cJSON_AddStringToObject(item, "packageWidth", product_create->package_width) == NULL) {
    goto fail; //String
    }
    }


    // product_create->product_code
    if (!product_create->product_code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productCode", product_create->product_code) == NULL) {
    goto fail; //String
    }


    // product_create->product_type
    if(product_create->product_type) {
    if(cJSON_AddStringToObject(item, "productType", product_create->product_type) == NULL) {
    goto fail; //String
    }
    }


    // product_create->purchase_price
    if(product_create->purchase_price) {
    if(cJSON_AddStringToObject(item, "purchasePrice", product_create->purchase_price) == NULL) {
    goto fail; //String
    }
    }


    // product_create->reorder_quantity
    if(product_create->reorder_quantity) {
    if(cJSON_AddNumberToObject(item, "reorderQuantity", *product_create->reorder_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // product_create->sale_price
    if(product_create->sale_price) {
    if(cJSON_AddStringToObject(item, "salePrice", product_create->sale_price) == NULL) {
    goto fail; //String
    }
    }


    // product_create->shipping_price
    if(product_create->shipping_price) {
    if(cJSON_AddStringToObject(item, "shippingPrice", product_create->shipping_price) == NULL) {
    goto fail; //String
    }
    }


    // product_create->shipping_requires_insurance
    if(product_create->shipping_requires_insurance) {
    if(cJSON_AddBoolToObject(item, "shippingRequiresInsurance", *product_create->shipping_requires_insurance) == NULL) {
    goto fail; //Bool
    }
    }


    // product_create->sku
    if (!product_create->sku) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sku", product_create->sku) == NULL) {
    goto fail; //String
    }


    // product_create->stock_quantity
    if(product_create->stock_quantity) {
    if(cJSON_AddNumberToObject(item, "stockQuantity", *product_create->stock_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // product_create->tags
    if(product_create->tags) {
    cJSON *tags_local_JSON = _convertToJSON(product_create->tags);
    if(tags_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "tags", tags_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // product_create->tax_price
    if(product_create->tax_price) {
    if(cJSON_AddStringToObject(item, "taxPrice", product_create->tax_price) == NULL) {
    goto fail; //String
    }
    }


    // product_create->track_batch
    if(product_create->track_batch) {
    if(cJSON_AddBoolToObject(item, "trackBatch", *product_create->track_batch) == NULL) {
    goto fail; //Bool
    }
    }


    // product_create->track_serial
    if(product_create->track_serial) {
    if(cJSON_AddBoolToObject(item, "trackSerial", *product_create->track_serial) == NULL) {
    goto fail; //Bool
    }
    }


    // product_create->unit
    if(product_create->unit) {
    cJSON *unit_local_JSON = _convertToJSON(product_create->unit);
    if(unit_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "unit", unit_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // product_create->weight_unit
    if(product_create->weight_unit) {
    if(cJSON_AddStringToObject(item, "weightUnit", product_create->weight_unit) == NULL) {
    goto fail; //String
    }
    }


    // product_create->weight_value
    if(product_create->weight_value) {
    if(cJSON_AddStringToObject(item, "weightValue", product_create->weight_value) == NULL) {
    goto fail; //String
    }
    }


    // product_create->width
    if(product_create->width) {
    if(cJSON_AddStringToObject(item, "width", product_create->width) == NULL) {
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

product_create_t *product_create_parseFromJSON(cJSON *product_createJSON){

    product_create_t *product_create_local_var = NULL;

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

    // define the local variable for product_create->images
    _t *images_local_nonprim = NULL;

    // define the local variable for product_create->is_taxable
    int *is_taxable_local_var = NULL;

    char *length_local_str = NULL;

    char *link_local_str = NULL;

    // define the local variable for product_create->max_stock
    long *max_stock_local_var = NULL;

    // define the local variable for product_create->min_stock
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

    // define the local variable for product_create->reorder_quantity
    long *reorder_quantity_local_var = NULL;

    char *sale_price_local_str = NULL;

    char *shipping_price_local_str = NULL;

    // define the local variable for product_create->shipping_requires_insurance
    int *shipping_requires_insurance_local_var = NULL;

    char *sku_local_str = NULL;

    // define the local variable for product_create->stock_quantity
    long *stock_quantity_local_var = NULL;

    // define the local variable for product_create->tags
    _t *tags_local_nonprim = NULL;

    char *tax_price_local_str = NULL;

    // define the local variable for product_create->track_batch
    int *track_batch_local_var = NULL;

    // define the local variable for product_create->track_serial
    int *track_serial_local_var = NULL;

    // define the local variable for product_create->unit
    _t *unit_local_nonprim = NULL;

    char *weight_unit_local_str = NULL;

    char *weight_value_local_str = NULL;

    char *width_local_str = NULL;

    // product_create->availability
    cJSON *availability = cJSON_GetObjectItemCaseSensitive(product_createJSON, "availability");
    if (cJSON_IsNull(availability)) {
        availability = NULL;
    }
    if (availability) { 
    if(!cJSON_IsString(availability) && !cJSON_IsNull(availability))
    {
    goto end; //String
    }
    }

    // product_create->barcode
    cJSON *barcode = cJSON_GetObjectItemCaseSensitive(product_createJSON, "barcode");
    if (cJSON_IsNull(barcode)) {
        barcode = NULL;
    }
    if (barcode) { 
    if(!cJSON_IsString(barcode) && !cJSON_IsNull(barcode))
    {
    goto end; //String
    }
    }

    // product_create->brand
    cJSON *brand = cJSON_GetObjectItemCaseSensitive(product_createJSON, "brand");
    if (cJSON_IsNull(brand)) {
        brand = NULL;
    }
    if (brand) { 
    if(!cJSON_IsString(brand) && !cJSON_IsNull(brand))
    {
    goto end; //String
    }
    }

    // product_create->category_id
    cJSON *category_id = cJSON_GetObjectItemCaseSensitive(product_createJSON, "categoryId");
    if (cJSON_IsNull(category_id)) {
        category_id = NULL;
    }
    if (category_id) { 
    if(!cJSON_IsString(category_id) && !cJSON_IsNull(category_id))
    {
    goto end; //String
    }
    }

    // product_create->condition
    cJSON *condition = cJSON_GetObjectItemCaseSensitive(product_createJSON, "condition");
    if (cJSON_IsNull(condition)) {
        condition = NULL;
    }
    if (condition) { 
    if(!cJSON_IsString(condition) && !cJSON_IsNull(condition))
    {
    goto end; //String
    }
    }

    // product_create->default_ledger_account
    cJSON *default_ledger_account = cJSON_GetObjectItemCaseSensitive(product_createJSON, "defaultLedgerAccount");
    if (cJSON_IsNull(default_ledger_account)) {
        default_ledger_account = NULL;
    }
    if (default_ledger_account) { 
    if(!cJSON_IsString(default_ledger_account) && !cJSON_IsNull(default_ledger_account))
    {
    goto end; //String
    }
    }

    // product_create->default_price
    cJSON *default_price = cJSON_GetObjectItemCaseSensitive(product_createJSON, "defaultPrice");
    if (cJSON_IsNull(default_price)) {
        default_price = NULL;
    }
    if (default_price) { 
    if(!cJSON_IsString(default_price) && !cJSON_IsNull(default_price))
    {
    goto end; //String
    }
    }

    // product_create->default_price_formula_id
    cJSON *default_price_formula_id = cJSON_GetObjectItemCaseSensitive(product_createJSON, "defaultPriceFormulaId");
    if (cJSON_IsNull(default_price_formula_id)) {
        default_price_formula_id = NULL;
    }
    if (default_price_formula_id) { 
    if(!cJSON_IsString(default_price_formula_id) && !cJSON_IsNull(default_price_formula_id))
    {
    goto end; //String
    }
    }

    // product_create->default_tax_rate
    cJSON *default_tax_rate = cJSON_GetObjectItemCaseSensitive(product_createJSON, "defaultTaxRate");
    if (cJSON_IsNull(default_tax_rate)) {
        default_tax_rate = NULL;
    }
    if (default_tax_rate) { 
    if(!cJSON_IsString(default_tax_rate) && !cJSON_IsNull(default_tax_rate))
    {
    goto end; //String
    }
    }

    // product_create->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(product_createJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // product_create->gtin
    cJSON *gtin = cJSON_GetObjectItemCaseSensitive(product_createJSON, "gtin");
    if (cJSON_IsNull(gtin)) {
        gtin = NULL;
    }
    if (gtin) { 
    if(!cJSON_IsString(gtin) && !cJSON_IsNull(gtin))
    {
    goto end; //String
    }
    }

    // product_create->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(product_createJSON, "height");
    if (cJSON_IsNull(height)) {
        height = NULL;
    }
    if (height) { 
    if(!cJSON_IsString(height) && !cJSON_IsNull(height))
    {
    goto end; //String
    }
    }

    // product_create->image_link
    cJSON *image_link = cJSON_GetObjectItemCaseSensitive(product_createJSON, "imageLink");
    if (cJSON_IsNull(image_link)) {
        image_link = NULL;
    }
    if (image_link) { 
    if(!cJSON_IsString(image_link) && !cJSON_IsNull(image_link))
    {
    goto end; //String
    }
    }

    // product_create->images
    cJSON *images = cJSON_GetObjectItemCaseSensitive(product_createJSON, "images");
    if (cJSON_IsNull(images)) {
        images = NULL;
    }
    if (images) { 
    images_local_nonprim = _parseFromJSON(images); //custom
    }

    // product_create->is_taxable
    cJSON *is_taxable = cJSON_GetObjectItemCaseSensitive(product_createJSON, "isTaxable");
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

    // product_create->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(product_createJSON, "length");
    if (cJSON_IsNull(length)) {
        length = NULL;
    }
    if (length) { 
    if(!cJSON_IsString(length) && !cJSON_IsNull(length))
    {
    goto end; //String
    }
    }

    // product_create->link
    cJSON *link = cJSON_GetObjectItemCaseSensitive(product_createJSON, "link");
    if (cJSON_IsNull(link)) {
        link = NULL;
    }
    if (link) { 
    if(!cJSON_IsString(link) && !cJSON_IsNull(link))
    {
    goto end; //String
    }
    }

    // product_create->max_stock
    cJSON *max_stock = cJSON_GetObjectItemCaseSensitive(product_createJSON, "maxStock");
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

    // product_create->min_stock
    cJSON *min_stock = cJSON_GetObjectItemCaseSensitive(product_createJSON, "minStock");
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

    // product_create->mpn
    cJSON *mpn = cJSON_GetObjectItemCaseSensitive(product_createJSON, "mpn");
    if (cJSON_IsNull(mpn)) {
        mpn = NULL;
    }
    if (mpn) { 
    if(!cJSON_IsString(mpn) && !cJSON_IsNull(mpn))
    {
    goto end; //String
    }
    }

    // product_create->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(product_createJSON, "name");
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

    // product_create->package_height
    cJSON *package_height = cJSON_GetObjectItemCaseSensitive(product_createJSON, "packageHeight");
    if (cJSON_IsNull(package_height)) {
        package_height = NULL;
    }
    if (package_height) { 
    if(!cJSON_IsString(package_height) && !cJSON_IsNull(package_height))
    {
    goto end; //String
    }
    }

    // product_create->package_length
    cJSON *package_length = cJSON_GetObjectItemCaseSensitive(product_createJSON, "packageLength");
    if (cJSON_IsNull(package_length)) {
        package_length = NULL;
    }
    if (package_length) { 
    if(!cJSON_IsString(package_length) && !cJSON_IsNull(package_length))
    {
    goto end; //String
    }
    }

    // product_create->package_weight_unit
    cJSON *package_weight_unit = cJSON_GetObjectItemCaseSensitive(product_createJSON, "packageWeightUnit");
    if (cJSON_IsNull(package_weight_unit)) {
        package_weight_unit = NULL;
    }
    if (package_weight_unit) { 
    if(!cJSON_IsString(package_weight_unit) && !cJSON_IsNull(package_weight_unit))
    {
    goto end; //String
    }
    }

    // product_create->package_weight_value
    cJSON *package_weight_value = cJSON_GetObjectItemCaseSensitive(product_createJSON, "packageWeightValue");
    if (cJSON_IsNull(package_weight_value)) {
        package_weight_value = NULL;
    }
    if (package_weight_value) { 
    if(!cJSON_IsString(package_weight_value) && !cJSON_IsNull(package_weight_value))
    {
    goto end; //String
    }
    }

    // product_create->package_width
    cJSON *package_width = cJSON_GetObjectItemCaseSensitive(product_createJSON, "packageWidth");
    if (cJSON_IsNull(package_width)) {
        package_width = NULL;
    }
    if (package_width) { 
    if(!cJSON_IsString(package_width) && !cJSON_IsNull(package_width))
    {
    goto end; //String
    }
    }

    // product_create->product_code
    cJSON *product_code = cJSON_GetObjectItemCaseSensitive(product_createJSON, "productCode");
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

    // product_create->product_type
    cJSON *product_type = cJSON_GetObjectItemCaseSensitive(product_createJSON, "productType");
    if (cJSON_IsNull(product_type)) {
        product_type = NULL;
    }
    if (product_type) { 
    if(!cJSON_IsString(product_type) && !cJSON_IsNull(product_type))
    {
    goto end; //String
    }
    }

    // product_create->purchase_price
    cJSON *purchase_price = cJSON_GetObjectItemCaseSensitive(product_createJSON, "purchasePrice");
    if (cJSON_IsNull(purchase_price)) {
        purchase_price = NULL;
    }
    if (purchase_price) { 
    if(!cJSON_IsString(purchase_price) && !cJSON_IsNull(purchase_price))
    {
    goto end; //String
    }
    }

    // product_create->reorder_quantity
    cJSON *reorder_quantity = cJSON_GetObjectItemCaseSensitive(product_createJSON, "reorderQuantity");
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

    // product_create->sale_price
    cJSON *sale_price = cJSON_GetObjectItemCaseSensitive(product_createJSON, "salePrice");
    if (cJSON_IsNull(sale_price)) {
        sale_price = NULL;
    }
    if (sale_price) { 
    if(!cJSON_IsString(sale_price) && !cJSON_IsNull(sale_price))
    {
    goto end; //String
    }
    }

    // product_create->shipping_price
    cJSON *shipping_price = cJSON_GetObjectItemCaseSensitive(product_createJSON, "shippingPrice");
    if (cJSON_IsNull(shipping_price)) {
        shipping_price = NULL;
    }
    if (shipping_price) { 
    if(!cJSON_IsString(shipping_price) && !cJSON_IsNull(shipping_price))
    {
    goto end; //String
    }
    }

    // product_create->shipping_requires_insurance
    cJSON *shipping_requires_insurance = cJSON_GetObjectItemCaseSensitive(product_createJSON, "shippingRequiresInsurance");
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

    // product_create->sku
    cJSON *sku = cJSON_GetObjectItemCaseSensitive(product_createJSON, "sku");
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

    // product_create->stock_quantity
    cJSON *stock_quantity = cJSON_GetObjectItemCaseSensitive(product_createJSON, "stockQuantity");
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

    // product_create->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(product_createJSON, "tags");
    if (cJSON_IsNull(tags)) {
        tags = NULL;
    }
    if (tags) { 
    tags_local_nonprim = _parseFromJSON(tags); //custom
    }

    // product_create->tax_price
    cJSON *tax_price = cJSON_GetObjectItemCaseSensitive(product_createJSON, "taxPrice");
    if (cJSON_IsNull(tax_price)) {
        tax_price = NULL;
    }
    if (tax_price) { 
    if(!cJSON_IsString(tax_price) && !cJSON_IsNull(tax_price))
    {
    goto end; //String
    }
    }

    // product_create->track_batch
    cJSON *track_batch = cJSON_GetObjectItemCaseSensitive(product_createJSON, "trackBatch");
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

    // product_create->track_serial
    cJSON *track_serial = cJSON_GetObjectItemCaseSensitive(product_createJSON, "trackSerial");
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

    // product_create->unit
    cJSON *unit = cJSON_GetObjectItemCaseSensitive(product_createJSON, "unit");
    if (cJSON_IsNull(unit)) {
        unit = NULL;
    }
    if (unit) { 
    unit_local_nonprim = _parseFromJSON(unit); //custom
    }

    // product_create->weight_unit
    cJSON *weight_unit = cJSON_GetObjectItemCaseSensitive(product_createJSON, "weightUnit");
    if (cJSON_IsNull(weight_unit)) {
        weight_unit = NULL;
    }
    if (weight_unit) { 
    if(!cJSON_IsString(weight_unit) && !cJSON_IsNull(weight_unit))
    {
    goto end; //String
    }
    }

    // product_create->weight_value
    cJSON *weight_value = cJSON_GetObjectItemCaseSensitive(product_createJSON, "weightValue");
    if (cJSON_IsNull(weight_value)) {
        weight_value = NULL;
    }
    if (weight_value) { 
    if(!cJSON_IsString(weight_value) && !cJSON_IsNull(weight_value))
    {
    goto end; //String
    }
    }

    // product_create->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(product_createJSON, "width");
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

    product_create_local_var = product_create_create_internal (
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

    if (!product_create_local_var) {
        goto end;
    }

    return product_create_local_var;
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
