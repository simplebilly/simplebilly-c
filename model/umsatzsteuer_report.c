#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "umsatzsteuer_report.h"



static umsatzsteuer_report_t *umsatzsteuer_report_create_internal(
    char *generated_at,
    list_t *input_tax,
    list_t *output_tax,
    char *period,
    char *total_input_tax,
    char *total_output_tax,
    char *vat_payable,
    char *vat_refund
    ) {
    umsatzsteuer_report_t *umsatzsteuer_report_local_var = malloc(sizeof(umsatzsteuer_report_t));
    if (!umsatzsteuer_report_local_var) {
        return NULL;
    }
    memset(umsatzsteuer_report_local_var, 0, sizeof(umsatzsteuer_report_t));
    umsatzsteuer_report_local_var->_library_owned = 1;
    umsatzsteuer_report_local_var->generated_at = generated_at;
    umsatzsteuer_report_local_var->input_tax = input_tax;
    umsatzsteuer_report_local_var->output_tax = output_tax;
    umsatzsteuer_report_local_var->period = period;
    umsatzsteuer_report_local_var->total_input_tax = total_input_tax;
    umsatzsteuer_report_local_var->total_output_tax = total_output_tax;
    umsatzsteuer_report_local_var->vat_payable = vat_payable;
    umsatzsteuer_report_local_var->vat_refund = vat_refund;
    return umsatzsteuer_report_local_var;
}

__attribute__((deprecated)) umsatzsteuer_report_t *umsatzsteuer_report_create(
    char *generated_at,
    list_t *input_tax,
    list_t *output_tax,
    char *period,
    char *total_input_tax,
    char *total_output_tax,
    char *vat_payable,
    char *vat_refund
    ) {
    umsatzsteuer_report_t *result = umsatzsteuer_report_create_internal (
        generated_at,
        input_tax,
        output_tax,
        period,
        total_input_tax,
        total_output_tax,
        vat_payable,
        vat_refund
        );
    if (!result) {
    }
    return result;
}

void umsatzsteuer_report_free(umsatzsteuer_report_t *umsatzsteuer_report) {
    if(NULL == umsatzsteuer_report){
        return ;
    }
    if(umsatzsteuer_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "umsatzsteuer_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (umsatzsteuer_report->generated_at) {
        free(umsatzsteuer_report->generated_at);
        umsatzsteuer_report->generated_at = NULL;
    }
    if (umsatzsteuer_report->input_tax) {
        list_ForEach(listEntry, umsatzsteuer_report->input_tax) {
            vat_detail_free(listEntry->data);
        }
        list_freeList(umsatzsteuer_report->input_tax);
        umsatzsteuer_report->input_tax = NULL;
    }
    if (umsatzsteuer_report->output_tax) {
        list_ForEach(listEntry, umsatzsteuer_report->output_tax) {
            vat_detail_free(listEntry->data);
        }
        list_freeList(umsatzsteuer_report->output_tax);
        umsatzsteuer_report->output_tax = NULL;
    }
    if (umsatzsteuer_report->period) {
        free(umsatzsteuer_report->period);
        umsatzsteuer_report->period = NULL;
    }
    if (umsatzsteuer_report->total_input_tax) {
        free(umsatzsteuer_report->total_input_tax);
        umsatzsteuer_report->total_input_tax = NULL;
    }
    if (umsatzsteuer_report->total_output_tax) {
        free(umsatzsteuer_report->total_output_tax);
        umsatzsteuer_report->total_output_tax = NULL;
    }
    if (umsatzsteuer_report->vat_payable) {
        free(umsatzsteuer_report->vat_payable);
        umsatzsteuer_report->vat_payable = NULL;
    }
    if (umsatzsteuer_report->vat_refund) {
        free(umsatzsteuer_report->vat_refund);
        umsatzsteuer_report->vat_refund = NULL;
    }
    free(umsatzsteuer_report);
}

cJSON *umsatzsteuer_report_convertToJSON(umsatzsteuer_report_t *umsatzsteuer_report) {
    cJSON *item = cJSON_CreateObject();

    // umsatzsteuer_report->generated_at
    if (!umsatzsteuer_report->generated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "generated_at", umsatzsteuer_report->generated_at) == NULL) {
    goto fail; //String
    }


    // umsatzsteuer_report->input_tax
    if (!umsatzsteuer_report->input_tax) {
        goto fail;
    }
    cJSON *input_tax = cJSON_AddArrayToObject(item, "input_tax");
    if(input_tax == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *input_taxListEntry;
    if (umsatzsteuer_report->input_tax) {
    list_ForEach(input_taxListEntry, umsatzsteuer_report->input_tax) {
    cJSON *itemLocal = vat_detail_convertToJSON(input_taxListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(input_tax, itemLocal);
    }
    }


    // umsatzsteuer_report->output_tax
    if (!umsatzsteuer_report->output_tax) {
        goto fail;
    }
    cJSON *output_tax = cJSON_AddArrayToObject(item, "output_tax");
    if(output_tax == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *output_taxListEntry;
    if (umsatzsteuer_report->output_tax) {
    list_ForEach(output_taxListEntry, umsatzsteuer_report->output_tax) {
    cJSON *itemLocal = vat_detail_convertToJSON(output_taxListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(output_tax, itemLocal);
    }
    }


    // umsatzsteuer_report->period
    if (!umsatzsteuer_report->period) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "period", umsatzsteuer_report->period) == NULL) {
    goto fail; //String
    }


    // umsatzsteuer_report->total_input_tax
    if (!umsatzsteuer_report->total_input_tax) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_input_tax", umsatzsteuer_report->total_input_tax) == NULL) {
    goto fail; //String
    }


    // umsatzsteuer_report->total_output_tax
    if (!umsatzsteuer_report->total_output_tax) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_output_tax", umsatzsteuer_report->total_output_tax) == NULL) {
    goto fail; //String
    }


    // umsatzsteuer_report->vat_payable
    if (!umsatzsteuer_report->vat_payable) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "vat_payable", umsatzsteuer_report->vat_payable) == NULL) {
    goto fail; //String
    }


    // umsatzsteuer_report->vat_refund
    if (!umsatzsteuer_report->vat_refund) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "vat_refund", umsatzsteuer_report->vat_refund) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

umsatzsteuer_report_t *umsatzsteuer_report_parseFromJSON(cJSON *umsatzsteuer_reportJSON){

    umsatzsteuer_report_t *umsatzsteuer_report_local_var = NULL;

    char *generated_at_local_str = NULL;

    // define the local list for umsatzsteuer_report->input_tax
    list_t *input_taxList = NULL;

    // define the local list for umsatzsteuer_report->output_tax
    list_t *output_taxList = NULL;

    char *period_local_str = NULL;

    char *total_input_tax_local_str = NULL;

    char *total_output_tax_local_str = NULL;

    char *vat_payable_local_str = NULL;

    char *vat_refund_local_str = NULL;

    // umsatzsteuer_report->generated_at
    cJSON *generated_at = cJSON_GetObjectItemCaseSensitive(umsatzsteuer_reportJSON, "generated_at");
    if (cJSON_IsNull(generated_at)) {
        generated_at = NULL;
    }
    if (!generated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(generated_at))
    {
    goto end; //String
    }

    // umsatzsteuer_report->input_tax
    cJSON *input_tax = cJSON_GetObjectItemCaseSensitive(umsatzsteuer_reportJSON, "input_tax");
    if (cJSON_IsNull(input_tax)) {
        input_tax = NULL;
    }
    if (!input_tax) {
        goto end;
    }

    
    cJSON *input_tax_local_nonprimitive = NULL;
    if(!cJSON_IsArray(input_tax)){
        goto end; //nonprimitive container
    }

    input_taxList = list_createList();

    cJSON_ArrayForEach(input_tax_local_nonprimitive,input_tax )
    {
        if(!cJSON_IsObject(input_tax_local_nonprimitive)){
            goto end;
        }
        vat_detail_t *input_taxItem = vat_detail_parseFromJSON(input_tax_local_nonprimitive);

        list_addElement(input_taxList, input_taxItem);
    }

    // umsatzsteuer_report->output_tax
    cJSON *output_tax = cJSON_GetObjectItemCaseSensitive(umsatzsteuer_reportJSON, "output_tax");
    if (cJSON_IsNull(output_tax)) {
        output_tax = NULL;
    }
    if (!output_tax) {
        goto end;
    }

    
    cJSON *output_tax_local_nonprimitive = NULL;
    if(!cJSON_IsArray(output_tax)){
        goto end; //nonprimitive container
    }

    output_taxList = list_createList();

    cJSON_ArrayForEach(output_tax_local_nonprimitive,output_tax )
    {
        if(!cJSON_IsObject(output_tax_local_nonprimitive)){
            goto end;
        }
        vat_detail_t *output_taxItem = vat_detail_parseFromJSON(output_tax_local_nonprimitive);

        list_addElement(output_taxList, output_taxItem);
    }

    // umsatzsteuer_report->period
    cJSON *period = cJSON_GetObjectItemCaseSensitive(umsatzsteuer_reportJSON, "period");
    if (cJSON_IsNull(period)) {
        period = NULL;
    }
    if (!period) {
        goto end;
    }

    
    if(!cJSON_IsString(period))
    {
    goto end; //String
    }

    // umsatzsteuer_report->total_input_tax
    cJSON *total_input_tax = cJSON_GetObjectItemCaseSensitive(umsatzsteuer_reportJSON, "total_input_tax");
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

    // umsatzsteuer_report->total_output_tax
    cJSON *total_output_tax = cJSON_GetObjectItemCaseSensitive(umsatzsteuer_reportJSON, "total_output_tax");
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

    // umsatzsteuer_report->vat_payable
    cJSON *vat_payable = cJSON_GetObjectItemCaseSensitive(umsatzsteuer_reportJSON, "vat_payable");
    if (cJSON_IsNull(vat_payable)) {
        vat_payable = NULL;
    }
    if (!vat_payable) {
        goto end;
    }

    
    if(!cJSON_IsString(vat_payable))
    {
    goto end; //String
    }

    // umsatzsteuer_report->vat_refund
    cJSON *vat_refund = cJSON_GetObjectItemCaseSensitive(umsatzsteuer_reportJSON, "vat_refund");
    if (cJSON_IsNull(vat_refund)) {
        vat_refund = NULL;
    }
    if (!vat_refund) {
        goto end;
    }

    
    if(!cJSON_IsString(vat_refund))
    {
    goto end; //String
    }


    if (generated_at && !cJSON_IsNull(generated_at)) generated_at_local_str = strdup(generated_at->valuestring);
    if (period && !cJSON_IsNull(period)) period_local_str = strdup(period->valuestring);
    if (total_input_tax && !cJSON_IsNull(total_input_tax)) total_input_tax_local_str = strdup(total_input_tax->valuestring);
    if (total_output_tax && !cJSON_IsNull(total_output_tax)) total_output_tax_local_str = strdup(total_output_tax->valuestring);
    if (vat_payable && !cJSON_IsNull(vat_payable)) vat_payable_local_str = strdup(vat_payable->valuestring);
    if (vat_refund && !cJSON_IsNull(vat_refund)) vat_refund_local_str = strdup(vat_refund->valuestring);

    umsatzsteuer_report_local_var = umsatzsteuer_report_create_internal (
        generated_at_local_str,
        input_taxList,
        output_taxList,
        period_local_str,
        total_input_tax_local_str,
        total_output_tax_local_str,
        vat_payable_local_str,
        vat_refund_local_str
        );

    if (!umsatzsteuer_report_local_var) {
        goto end;
    }

    return umsatzsteuer_report_local_var;
end:
    if (generated_at_local_str) {
        free(generated_at_local_str);
        generated_at_local_str = NULL;
    }
    if (input_taxList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, input_taxList) {
            vat_detail_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(input_taxList);
        input_taxList = NULL;
    }
    if (output_taxList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, output_taxList) {
            vat_detail_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(output_taxList);
        output_taxList = NULL;
    }
    if (period_local_str) {
        free(period_local_str);
        period_local_str = NULL;
    }
    if (total_input_tax_local_str) {
        free(total_input_tax_local_str);
        total_input_tax_local_str = NULL;
    }
    if (total_output_tax_local_str) {
        free(total_output_tax_local_str);
        total_output_tax_local_str = NULL;
    }
    if (vat_payable_local_str) {
        free(vat_payable_local_str);
        vat_payable_local_str = NULL;
    }
    if (vat_refund_local_str) {
        free(vat_refund_local_str);
        vat_refund_local_str = NULL;
    }
    return NULL;

}
