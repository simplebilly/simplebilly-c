#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sales_volume_item.h"



static sales_volume_item_t *sales_volume_item_create_internal(
    char *contact_id,
    char *contact_type,
    char *last_purchase_date,
    char *name,
    int *total_invoices,
    char *total_revenue
    ) {
    sales_volume_item_t *sales_volume_item_local_var = malloc(sizeof(sales_volume_item_t));
    if (!sales_volume_item_local_var) {
        return NULL;
    }
    memset(sales_volume_item_local_var, 0, sizeof(sales_volume_item_t));
    sales_volume_item_local_var->_library_owned = 1;
    sales_volume_item_local_var->contact_id = contact_id;
    sales_volume_item_local_var->contact_type = contact_type;
    sales_volume_item_local_var->last_purchase_date = last_purchase_date;
    sales_volume_item_local_var->name = name;
    sales_volume_item_local_var->total_invoices = total_invoices;
    sales_volume_item_local_var->total_revenue = total_revenue;
    return sales_volume_item_local_var;
}

__attribute__((deprecated)) sales_volume_item_t *sales_volume_item_create(
    char *contact_id,
    char *contact_type,
    char *last_purchase_date,
    char *name,
    int *total_invoices,
    char *total_revenue
    ) {
    int *total_invoices_copy = NULL;
    if (total_invoices) {
        total_invoices_copy = malloc(sizeof(int));
        if (total_invoices_copy) *total_invoices_copy = *total_invoices;
    }
    sales_volume_item_t *result = sales_volume_item_create_internal (
        contact_id,
        contact_type,
        last_purchase_date,
        name,
        total_invoices_copy,
        total_revenue
        );
    if (!result) {
        free(total_invoices_copy);
    }
    return result;
}

void sales_volume_item_free(sales_volume_item_t *sales_volume_item) {
    if(NULL == sales_volume_item){
        return ;
    }
    if(sales_volume_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "sales_volume_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (sales_volume_item->contact_id) {
        free(sales_volume_item->contact_id);
        sales_volume_item->contact_id = NULL;
    }
    if (sales_volume_item->contact_type) {
        free(sales_volume_item->contact_type);
        sales_volume_item->contact_type = NULL;
    }
    if (sales_volume_item->last_purchase_date) {
        free(sales_volume_item->last_purchase_date);
        sales_volume_item->last_purchase_date = NULL;
    }
    if (sales_volume_item->name) {
        free(sales_volume_item->name);
        sales_volume_item->name = NULL;
    }
    if (sales_volume_item->total_invoices) {
        free(sales_volume_item->total_invoices);
        sales_volume_item->total_invoices = NULL;
    }
    if (sales_volume_item->total_revenue) {
        free(sales_volume_item->total_revenue);
        sales_volume_item->total_revenue = NULL;
    }
    free(sales_volume_item);
}

cJSON *sales_volume_item_convertToJSON(sales_volume_item_t *sales_volume_item) {
    cJSON *item = cJSON_CreateObject();

    // sales_volume_item->contact_id
    if (!sales_volume_item->contact_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "contact_id", sales_volume_item->contact_id) == NULL) {
    goto fail; //String
    }


    // sales_volume_item->contact_type
    if (!sales_volume_item->contact_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "contact_type", sales_volume_item->contact_type) == NULL) {
    goto fail; //String
    }


    // sales_volume_item->last_purchase_date
    if(sales_volume_item->last_purchase_date) {
    if(cJSON_AddStringToObject(item, "last_purchase_date", sales_volume_item->last_purchase_date) == NULL) {
    goto fail; //String
    }
    }


    // sales_volume_item->name
    if (!sales_volume_item->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", sales_volume_item->name) == NULL) {
    goto fail; //String
    }


    // sales_volume_item->total_invoices
    if (!sales_volume_item->total_invoices) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_invoices", *sales_volume_item->total_invoices) == NULL) {
    goto fail; //Numeric
    }


    // sales_volume_item->total_revenue
    if (!sales_volume_item->total_revenue) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_revenue", sales_volume_item->total_revenue) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

sales_volume_item_t *sales_volume_item_parseFromJSON(cJSON *sales_volume_itemJSON){

    sales_volume_item_t *sales_volume_item_local_var = NULL;

    char *contact_id_local_str = NULL;

    char *contact_type_local_str = NULL;

    char *last_purchase_date_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for sales_volume_item->total_invoices
    int *total_invoices_local_var = NULL;

    char *total_revenue_local_str = NULL;

    // sales_volume_item->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(sales_volume_itemJSON, "contact_id");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (!contact_id) {
        goto end;
    }

    
    if(!cJSON_IsString(contact_id))
    {
    goto end; //String
    }

    // sales_volume_item->contact_type
    cJSON *contact_type = cJSON_GetObjectItemCaseSensitive(sales_volume_itemJSON, "contact_type");
    if (cJSON_IsNull(contact_type)) {
        contact_type = NULL;
    }
    if (!contact_type) {
        goto end;
    }

    
    if(!cJSON_IsString(contact_type))
    {
    goto end; //String
    }

    // sales_volume_item->last_purchase_date
    cJSON *last_purchase_date = cJSON_GetObjectItemCaseSensitive(sales_volume_itemJSON, "last_purchase_date");
    if (cJSON_IsNull(last_purchase_date)) {
        last_purchase_date = NULL;
    }
    if (last_purchase_date) { 
    if(!cJSON_IsString(last_purchase_date) && !cJSON_IsNull(last_purchase_date))
    {
    goto end; //String
    }
    }

    // sales_volume_item->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(sales_volume_itemJSON, "name");
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

    // sales_volume_item->total_invoices
    cJSON *total_invoices = cJSON_GetObjectItemCaseSensitive(sales_volume_itemJSON, "total_invoices");
    if (cJSON_IsNull(total_invoices)) {
        total_invoices = NULL;
    }
    if (!total_invoices) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_invoices))
    {
    goto end; //Numeric
    }
    total_invoices_local_var = malloc(sizeof(int));
    if(!total_invoices_local_var)
    {
        goto end;
    }
    *total_invoices_local_var = total_invoices->valuedouble;

    // sales_volume_item->total_revenue
    cJSON *total_revenue = cJSON_GetObjectItemCaseSensitive(sales_volume_itemJSON, "total_revenue");
    if (cJSON_IsNull(total_revenue)) {
        total_revenue = NULL;
    }
    if (!total_revenue) {
        goto end;
    }

    
    if(!cJSON_IsString(total_revenue))
    {
    goto end; //String
    }


    if (contact_id && !cJSON_IsNull(contact_id)) contact_id_local_str = strdup(contact_id->valuestring);
    if (contact_type && !cJSON_IsNull(contact_type)) contact_type_local_str = strdup(contact_type->valuestring);
    if (last_purchase_date && !cJSON_IsNull(last_purchase_date)) last_purchase_date_local_str = strdup(last_purchase_date->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (total_revenue && !cJSON_IsNull(total_revenue)) total_revenue_local_str = strdup(total_revenue->valuestring);

    sales_volume_item_local_var = sales_volume_item_create_internal (
        contact_id_local_str,
        contact_type_local_str,
        last_purchase_date_local_str,
        name_local_str,
        total_invoices_local_var,
        total_revenue_local_str
        );

    if (!sales_volume_item_local_var) {
        goto end;
    }

    return sales_volume_item_local_var;
end:
    if (contact_id_local_str) {
        free(contact_id_local_str);
        contact_id_local_str = NULL;
    }
    if (contact_type_local_str) {
        free(contact_type_local_str);
        contact_type_local_str = NULL;
    }
    if (last_purchase_date_local_str) {
        free(last_purchase_date_local_str);
        last_purchase_date_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (total_invoices_local_var) {
        free(total_invoices_local_var);
        total_invoices_local_var = NULL;
    }
    if (total_revenue_local_str) {
        free(total_revenue_local_str);
        total_revenue_local_str = NULL;
    }
    return NULL;

}
