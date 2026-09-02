#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "open_item.h"



static open_item_t *open_item_create_internal(
    char *amount_due,
    char *amount_paid,
    char *customer_id,
    long *days_overdue,
    char *due_date,
    char *invoice_id,
    char *invoice_number,
    char *issue_date,
    char *open_amount,
    simplebilly_api_reminder_level__e reminder_level
    ) {
    open_item_t *open_item_local_var = malloc(sizeof(open_item_t));
    if (!open_item_local_var) {
        return NULL;
    }
    memset(open_item_local_var, 0, sizeof(open_item_t));
    open_item_local_var->_library_owned = 1;
    open_item_local_var->amount_due = amount_due;
    open_item_local_var->amount_paid = amount_paid;
    open_item_local_var->customer_id = customer_id;
    open_item_local_var->days_overdue = days_overdue;
    open_item_local_var->due_date = due_date;
    open_item_local_var->invoice_id = invoice_id;
    open_item_local_var->invoice_number = invoice_number;
    open_item_local_var->issue_date = issue_date;
    open_item_local_var->open_amount = open_amount;
    open_item_local_var->reminder_level = reminder_level;
    return open_item_local_var;
}

__attribute__((deprecated)) open_item_t *open_item_create(
    char *amount_due,
    char *amount_paid,
    char *customer_id,
    long *days_overdue,
    char *due_date,
    char *invoice_id,
    char *invoice_number,
    char *issue_date,
    char *open_amount,
    simplebilly_api_reminder_level__e reminder_level
    ) {
    long *days_overdue_copy = NULL;
    if (days_overdue) {
        days_overdue_copy = malloc(sizeof(long));
        if (days_overdue_copy) *days_overdue_copy = *days_overdue;
    }
    open_item_t *result = open_item_create_internal (
        amount_due,
        amount_paid,
        customer_id,
        days_overdue_copy,
        due_date,
        invoice_id,
        invoice_number,
        issue_date,
        open_amount,
        reminder_level
        );
    if (!result) {
        free(days_overdue_copy);
    }
    return result;
}

void open_item_free(open_item_t *open_item) {
    if(NULL == open_item){
        return ;
    }
    if(open_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "open_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (open_item->amount_due) {
        free(open_item->amount_due);
        open_item->amount_due = NULL;
    }
    if (open_item->amount_paid) {
        free(open_item->amount_paid);
        open_item->amount_paid = NULL;
    }
    if (open_item->customer_id) {
        free(open_item->customer_id);
        open_item->customer_id = NULL;
    }
    if (open_item->days_overdue) {
        free(open_item->days_overdue);
        open_item->days_overdue = NULL;
    }
    if (open_item->due_date) {
        free(open_item->due_date);
        open_item->due_date = NULL;
    }
    if (open_item->invoice_id) {
        free(open_item->invoice_id);
        open_item->invoice_id = NULL;
    }
    if (open_item->invoice_number) {
        free(open_item->invoice_number);
        open_item->invoice_number = NULL;
    }
    if (open_item->issue_date) {
        free(open_item->issue_date);
        open_item->issue_date = NULL;
    }
    if (open_item->open_amount) {
        free(open_item->open_amount);
        open_item->open_amount = NULL;
    }
    free(open_item);
}

cJSON *open_item_convertToJSON(open_item_t *open_item) {
    cJSON *item = cJSON_CreateObject();

    // open_item->amount_due
    if (!open_item->amount_due) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amount_due", open_item->amount_due) == NULL) {
    goto fail; //String
    }


    // open_item->amount_paid
    if (!open_item->amount_paid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amount_paid", open_item->amount_paid) == NULL) {
    goto fail; //String
    }


    // open_item->customer_id
    if(open_item->customer_id) {
    if(cJSON_AddStringToObject(item, "customer_id", open_item->customer_id) == NULL) {
    goto fail; //String
    }
    }


    // open_item->days_overdue
    if(open_item->days_overdue) {
    if(cJSON_AddNumberToObject(item, "days_overdue", *open_item->days_overdue) == NULL) {
    goto fail; //Numeric
    }
    }


    // open_item->due_date
    if(open_item->due_date) {
    if(cJSON_AddStringToObject(item, "due_date", open_item->due_date) == NULL) {
    goto fail; //String
    }
    }


    // open_item->invoice_id
    if (!open_item->invoice_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invoice_id", open_item->invoice_id) == NULL) {
    goto fail; //String
    }


    // open_item->invoice_number
    if (!open_item->invoice_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invoice_number", open_item->invoice_number) == NULL) {
    goto fail; //String
    }


    // open_item->issue_date
    if (!open_item->issue_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "issue_date", open_item->issue_date) == NULL) {
    goto fail; //String
    }


    // open_item->open_amount
    if (!open_item->open_amount) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "open_amount", open_item->open_amount) == NULL) {
    goto fail; //String
    }


    // open_item->reminder_level
    if (simplebilly_api_reminder_level__NULL == open_item->reminder_level) {
        goto fail;
    }
    cJSON *reminder_level_local_JSON = reminder_level_convertToJSON(open_item->reminder_level);
    if(reminder_level_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "reminder_level", reminder_level_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

open_item_t *open_item_parseFromJSON(cJSON *open_itemJSON){

    open_item_t *open_item_local_var = NULL;

    char *amount_due_local_str = NULL;

    char *amount_paid_local_str = NULL;

    char *customer_id_local_str = NULL;

    // define the local variable for open_item->days_overdue
    long *days_overdue_local_var = NULL;

    char *due_date_local_str = NULL;

    char *invoice_id_local_str = NULL;

    char *invoice_number_local_str = NULL;

    char *issue_date_local_str = NULL;

    char *open_amount_local_str = NULL;

    // define the local variable for open_item->reminder_level
    simplebilly_api_reminder_level__e reminder_level_local_nonprim = 0;

    // open_item->amount_due
    cJSON *amount_due = cJSON_GetObjectItemCaseSensitive(open_itemJSON, "amount_due");
    if (cJSON_IsNull(amount_due)) {
        amount_due = NULL;
    }
    if (!amount_due) {
        goto end;
    }

    
    if(!cJSON_IsString(amount_due))
    {
    goto end; //String
    }

    // open_item->amount_paid
    cJSON *amount_paid = cJSON_GetObjectItemCaseSensitive(open_itemJSON, "amount_paid");
    if (cJSON_IsNull(amount_paid)) {
        amount_paid = NULL;
    }
    if (!amount_paid) {
        goto end;
    }

    
    if(!cJSON_IsString(amount_paid))
    {
    goto end; //String
    }

    // open_item->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(open_itemJSON, "customer_id");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (customer_id) { 
    if(!cJSON_IsString(customer_id) && !cJSON_IsNull(customer_id))
    {
    goto end; //String
    }
    }

    // open_item->days_overdue
    cJSON *days_overdue = cJSON_GetObjectItemCaseSensitive(open_itemJSON, "days_overdue");
    if (cJSON_IsNull(days_overdue)) {
        days_overdue = NULL;
    }
    if (days_overdue) { 
    if(!cJSON_IsNumber(days_overdue))
    {
    goto end; //Numeric
    }
    days_overdue_local_var = malloc(sizeof(long));
    if(!days_overdue_local_var)
    {
        goto end;
    }
    *days_overdue_local_var = days_overdue->valuedouble;
    }

    // open_item->due_date
    cJSON *due_date = cJSON_GetObjectItemCaseSensitive(open_itemJSON, "due_date");
    if (cJSON_IsNull(due_date)) {
        due_date = NULL;
    }
    if (due_date) { 
    if(!cJSON_IsString(due_date) && !cJSON_IsNull(due_date))
    {
    goto end; //String
    }
    }

    // open_item->invoice_id
    cJSON *invoice_id = cJSON_GetObjectItemCaseSensitive(open_itemJSON, "invoice_id");
    if (cJSON_IsNull(invoice_id)) {
        invoice_id = NULL;
    }
    if (!invoice_id) {
        goto end;
    }

    
    if(!cJSON_IsString(invoice_id))
    {
    goto end; //String
    }

    // open_item->invoice_number
    cJSON *invoice_number = cJSON_GetObjectItemCaseSensitive(open_itemJSON, "invoice_number");
    if (cJSON_IsNull(invoice_number)) {
        invoice_number = NULL;
    }
    if (!invoice_number) {
        goto end;
    }

    
    if(!cJSON_IsString(invoice_number))
    {
    goto end; //String
    }

    // open_item->issue_date
    cJSON *issue_date = cJSON_GetObjectItemCaseSensitive(open_itemJSON, "issue_date");
    if (cJSON_IsNull(issue_date)) {
        issue_date = NULL;
    }
    if (!issue_date) {
        goto end;
    }

    
    if(!cJSON_IsString(issue_date))
    {
    goto end; //String
    }

    // open_item->open_amount
    cJSON *open_amount = cJSON_GetObjectItemCaseSensitive(open_itemJSON, "open_amount");
    if (cJSON_IsNull(open_amount)) {
        open_amount = NULL;
    }
    if (!open_amount) {
        goto end;
    }

    
    if(!cJSON_IsString(open_amount))
    {
    goto end; //String
    }

    // open_item->reminder_level
    cJSON *reminder_level = cJSON_GetObjectItemCaseSensitive(open_itemJSON, "reminder_level");
    if (cJSON_IsNull(reminder_level)) {
        reminder_level = NULL;
    }
    if (!reminder_level) {
        goto end;
    }

    
    reminder_level_local_nonprim = reminder_level_parseFromJSON(reminder_level); //custom


    if (amount_due && !cJSON_IsNull(amount_due)) amount_due_local_str = strdup(amount_due->valuestring);
    if (amount_paid && !cJSON_IsNull(amount_paid)) amount_paid_local_str = strdup(amount_paid->valuestring);
    if (customer_id && !cJSON_IsNull(customer_id)) customer_id_local_str = strdup(customer_id->valuestring);
    if (due_date && !cJSON_IsNull(due_date)) due_date_local_str = strdup(due_date->valuestring);
    if (invoice_id && !cJSON_IsNull(invoice_id)) invoice_id_local_str = strdup(invoice_id->valuestring);
    if (invoice_number && !cJSON_IsNull(invoice_number)) invoice_number_local_str = strdup(invoice_number->valuestring);
    if (issue_date && !cJSON_IsNull(issue_date)) issue_date_local_str = strdup(issue_date->valuestring);
    if (open_amount && !cJSON_IsNull(open_amount)) open_amount_local_str = strdup(open_amount->valuestring);

    open_item_local_var = open_item_create_internal (
        amount_due_local_str,
        amount_paid_local_str,
        customer_id_local_str,
        days_overdue_local_var,
        due_date_local_str,
        invoice_id_local_str,
        invoice_number_local_str,
        issue_date_local_str,
        open_amount_local_str,
        reminder_level_local_nonprim
        );

    if (!open_item_local_var) {
        goto end;
    }

    return open_item_local_var;
end:
    if (amount_due_local_str) {
        free(amount_due_local_str);
        amount_due_local_str = NULL;
    }
    if (amount_paid_local_str) {
        free(amount_paid_local_str);
        amount_paid_local_str = NULL;
    }
    if (customer_id_local_str) {
        free(customer_id_local_str);
        customer_id_local_str = NULL;
    }
    if (days_overdue_local_var) {
        free(days_overdue_local_var);
        days_overdue_local_var = NULL;
    }
    if (due_date_local_str) {
        free(due_date_local_str);
        due_date_local_str = NULL;
    }
    if (invoice_id_local_str) {
        free(invoice_id_local_str);
        invoice_id_local_str = NULL;
    }
    if (invoice_number_local_str) {
        free(invoice_number_local_str);
        invoice_number_local_str = NULL;
    }
    if (issue_date_local_str) {
        free(issue_date_local_str);
        issue_date_local_str = NULL;
    }
    if (open_amount_local_str) {
        free(open_amount_local_str);
        open_amount_local_str = NULL;
    }
    if (reminder_level_local_nonprim) {
        reminder_level_local_nonprim = 0;
    }
    return NULL;

}
