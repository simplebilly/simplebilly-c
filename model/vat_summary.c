#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vat_summary.h"



static vat_summary_t *vat_summary_create_internal(
    list_t *input_tax_items,
    list_t *output_tax_items,
    char *total_input_tax,
    char *total_output_tax,
    char *vat_due
    ) {
    vat_summary_t *vat_summary_local_var = malloc(sizeof(vat_summary_t));
    if (!vat_summary_local_var) {
        return NULL;
    }
    memset(vat_summary_local_var, 0, sizeof(vat_summary_t));
    vat_summary_local_var->_library_owned = 1;
    vat_summary_local_var->input_tax_items = input_tax_items;
    vat_summary_local_var->output_tax_items = output_tax_items;
    vat_summary_local_var->total_input_tax = total_input_tax;
    vat_summary_local_var->total_output_tax = total_output_tax;
    vat_summary_local_var->vat_due = vat_due;
    return vat_summary_local_var;
}

__attribute__((deprecated)) vat_summary_t *vat_summary_create(
    list_t *input_tax_items,
    list_t *output_tax_items,
    char *total_input_tax,
    char *total_output_tax,
    char *vat_due
    ) {
    vat_summary_t *result = vat_summary_create_internal (
        input_tax_items,
        output_tax_items,
        total_input_tax,
        total_output_tax,
        vat_due
        );
    if (!result) {
    }
    return result;
}

void vat_summary_free(vat_summary_t *vat_summary) {
    if(NULL == vat_summary){
        return ;
    }
    if(vat_summary->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "vat_summary_free");
        return ;
    }
    listEntry_t *listEntry;
    if (vat_summary->input_tax_items) {
        list_ForEach(listEntry, vat_summary->input_tax_items) {
            vat_item_free(listEntry->data);
        }
        list_freeList(vat_summary->input_tax_items);
        vat_summary->input_tax_items = NULL;
    }
    if (vat_summary->output_tax_items) {
        list_ForEach(listEntry, vat_summary->output_tax_items) {
            vat_item_free(listEntry->data);
        }
        list_freeList(vat_summary->output_tax_items);
        vat_summary->output_tax_items = NULL;
    }
    if (vat_summary->total_input_tax) {
        free(vat_summary->total_input_tax);
        vat_summary->total_input_tax = NULL;
    }
    if (vat_summary->total_output_tax) {
        free(vat_summary->total_output_tax);
        vat_summary->total_output_tax = NULL;
    }
    if (vat_summary->vat_due) {
        free(vat_summary->vat_due);
        vat_summary->vat_due = NULL;
    }
    free(vat_summary);
}

cJSON *vat_summary_convertToJSON(vat_summary_t *vat_summary) {
    cJSON *item = cJSON_CreateObject();

    // vat_summary->input_tax_items
    if (!vat_summary->input_tax_items) {
        goto fail;
    }
    cJSON *input_tax_items = cJSON_AddArrayToObject(item, "input_tax_items");
    if(input_tax_items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *input_tax_itemsListEntry;
    if (vat_summary->input_tax_items) {
    list_ForEach(input_tax_itemsListEntry, vat_summary->input_tax_items) {
    cJSON *itemLocal = vat_item_convertToJSON(input_tax_itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(input_tax_items, itemLocal);
    }
    }


    // vat_summary->output_tax_items
    if (!vat_summary->output_tax_items) {
        goto fail;
    }
    cJSON *output_tax_items = cJSON_AddArrayToObject(item, "output_tax_items");
    if(output_tax_items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *output_tax_itemsListEntry;
    if (vat_summary->output_tax_items) {
    list_ForEach(output_tax_itemsListEntry, vat_summary->output_tax_items) {
    cJSON *itemLocal = vat_item_convertToJSON(output_tax_itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(output_tax_items, itemLocal);
    }
    }


    // vat_summary->total_input_tax
    if (!vat_summary->total_input_tax) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_input_tax", vat_summary->total_input_tax) == NULL) {
    goto fail; //String
    }


    // vat_summary->total_output_tax
    if (!vat_summary->total_output_tax) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_output_tax", vat_summary->total_output_tax) == NULL) {
    goto fail; //String
    }


    // vat_summary->vat_due
    if (!vat_summary->vat_due) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "vat_due", vat_summary->vat_due) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

vat_summary_t *vat_summary_parseFromJSON(cJSON *vat_summaryJSON){

    vat_summary_t *vat_summary_local_var = NULL;

    // define the local list for vat_summary->input_tax_items
    list_t *input_tax_itemsList = NULL;

    // define the local list for vat_summary->output_tax_items
    list_t *output_tax_itemsList = NULL;

    char *total_input_tax_local_str = NULL;

    char *total_output_tax_local_str = NULL;

    char *vat_due_local_str = NULL;

    // vat_summary->input_tax_items
    cJSON *input_tax_items = cJSON_GetObjectItemCaseSensitive(vat_summaryJSON, "input_tax_items");
    if (cJSON_IsNull(input_tax_items)) {
        input_tax_items = NULL;
    }
    if (!input_tax_items) {
        goto end;
    }

    
    cJSON *input_tax_items_local_nonprimitive = NULL;
    if(!cJSON_IsArray(input_tax_items)){
        goto end; //nonprimitive container
    }

    input_tax_itemsList = list_createList();

    cJSON_ArrayForEach(input_tax_items_local_nonprimitive,input_tax_items )
    {
        if(!cJSON_IsObject(input_tax_items_local_nonprimitive)){
            goto end;
        }
        vat_item_t *input_tax_itemsItem = vat_item_parseFromJSON(input_tax_items_local_nonprimitive);

        list_addElement(input_tax_itemsList, input_tax_itemsItem);
    }

    // vat_summary->output_tax_items
    cJSON *output_tax_items = cJSON_GetObjectItemCaseSensitive(vat_summaryJSON, "output_tax_items");
    if (cJSON_IsNull(output_tax_items)) {
        output_tax_items = NULL;
    }
    if (!output_tax_items) {
        goto end;
    }

    
    cJSON *output_tax_items_local_nonprimitive = NULL;
    if(!cJSON_IsArray(output_tax_items)){
        goto end; //nonprimitive container
    }

    output_tax_itemsList = list_createList();

    cJSON_ArrayForEach(output_tax_items_local_nonprimitive,output_tax_items )
    {
        if(!cJSON_IsObject(output_tax_items_local_nonprimitive)){
            goto end;
        }
        vat_item_t *output_tax_itemsItem = vat_item_parseFromJSON(output_tax_items_local_nonprimitive);

        list_addElement(output_tax_itemsList, output_tax_itemsItem);
    }

    // vat_summary->total_input_tax
    cJSON *total_input_tax = cJSON_GetObjectItemCaseSensitive(vat_summaryJSON, "total_input_tax");
    if (cJSON_IsNull(total_input_tax)) {
        total_input_tax = NULL;
    }
    if (!total_input_tax) {
        goto end;
    }

    
    if(!cJSON_IsString(total_input_tax))
    {
    goto end; //String
    }

    // vat_summary->total_output_tax
    cJSON *total_output_tax = cJSON_GetObjectItemCaseSensitive(vat_summaryJSON, "total_output_tax");
    if (cJSON_IsNull(total_output_tax)) {
        total_output_tax = NULL;
    }
    if (!total_output_tax) {
        goto end;
    }

    
    if(!cJSON_IsString(total_output_tax))
    {
    goto end; //String
    }

    // vat_summary->vat_due
    cJSON *vat_due = cJSON_GetObjectItemCaseSensitive(vat_summaryJSON, "vat_due");
    if (cJSON_IsNull(vat_due)) {
        vat_due = NULL;
    }
    if (!vat_due) {
        goto end;
    }

    
    if(!cJSON_IsString(vat_due))
    {
    goto end; //String
    }


    if (total_input_tax && !cJSON_IsNull(total_input_tax)) total_input_tax_local_str = strdup(total_input_tax->valuestring);
    if (total_output_tax && !cJSON_IsNull(total_output_tax)) total_output_tax_local_str = strdup(total_output_tax->valuestring);
    if (vat_due && !cJSON_IsNull(vat_due)) vat_due_local_str = strdup(vat_due->valuestring);

    vat_summary_local_var = vat_summary_create_internal (
        input_tax_itemsList,
        output_tax_itemsList,
        total_input_tax_local_str,
        total_output_tax_local_str,
        vat_due_local_str
        );

    if (!vat_summary_local_var) {
        goto end;
    }

    return vat_summary_local_var;
end:
    if (input_tax_itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, input_tax_itemsList) {
            vat_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(input_tax_itemsList);
        input_tax_itemsList = NULL;
    }
    if (output_tax_itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, output_tax_itemsList) {
            vat_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(output_tax_itemsList);
        output_tax_itemsList = NULL;
    }
    if (total_input_tax_local_str) {
        free(total_input_tax_local_str);
        total_input_tax_local_str = NULL;
    }
    if (total_output_tax_local_str) {
        free(total_output_tax_local_str);
        total_output_tax_local_str = NULL;
    }
    if (vat_due_local_str) {
        free(vat_due_local_str);
        vat_due_local_str = NULL;
    }
    return NULL;

}
