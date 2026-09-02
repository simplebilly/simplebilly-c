#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "customer_update.h"



static customer_update_t *customer_update_create_internal(
    any_type_t *address,
    char *contact_person,
    char *email,
    char *external_order_number,
    char *name,
    int *payment_grace_period_days,
    char *phone,
    char *vat_id
    ) {
    customer_update_t *customer_update_local_var = malloc(sizeof(customer_update_t));
    if (!customer_update_local_var) {
        return NULL;
    }
    memset(customer_update_local_var, 0, sizeof(customer_update_t));
    customer_update_local_var->_library_owned = 1;
    customer_update_local_var->address = address;
    customer_update_local_var->contact_person = contact_person;
    customer_update_local_var->email = email;
    customer_update_local_var->external_order_number = external_order_number;
    customer_update_local_var->name = name;
    customer_update_local_var->payment_grace_period_days = payment_grace_period_days;
    customer_update_local_var->phone = phone;
    customer_update_local_var->vat_id = vat_id;
    return customer_update_local_var;
}

__attribute__((deprecated)) customer_update_t *customer_update_create(
    any_type_t *address,
    char *contact_person,
    char *email,
    char *external_order_number,
    char *name,
    int *payment_grace_period_days,
    char *phone,
    char *vat_id
    ) {
    int *payment_grace_period_days_copy = NULL;
    if (payment_grace_period_days) {
        payment_grace_period_days_copy = malloc(sizeof(int));
        if (payment_grace_period_days_copy) *payment_grace_period_days_copy = *payment_grace_period_days;
    }
    customer_update_t *result = customer_update_create_internal (
        address,
        contact_person,
        email,
        external_order_number,
        name,
        payment_grace_period_days_copy,
        phone,
        vat_id
        );
    if (!result) {
        free(payment_grace_period_days_copy);
    }
    return result;
}

void customer_update_free(customer_update_t *customer_update) {
    if(NULL == customer_update){
        return ;
    }
    if(customer_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "customer_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (customer_update->address) {
        _free(customer_update->address);
        customer_update->address = NULL;
    }
    if (customer_update->contact_person) {
        free(customer_update->contact_person);
        customer_update->contact_person = NULL;
    }
    if (customer_update->email) {
        free(customer_update->email);
        customer_update->email = NULL;
    }
    if (customer_update->external_order_number) {
        free(customer_update->external_order_number);
        customer_update->external_order_number = NULL;
    }
    if (customer_update->name) {
        free(customer_update->name);
        customer_update->name = NULL;
    }
    if (customer_update->payment_grace_period_days) {
        free(customer_update->payment_grace_period_days);
        customer_update->payment_grace_period_days = NULL;
    }
    if (customer_update->phone) {
        free(customer_update->phone);
        customer_update->phone = NULL;
    }
    if (customer_update->vat_id) {
        free(customer_update->vat_id);
        customer_update->vat_id = NULL;
    }
    free(customer_update);
}

cJSON *customer_update_convertToJSON(customer_update_t *customer_update) {
    cJSON *item = cJSON_CreateObject();

    // customer_update->address
    if(customer_update->address) {
    cJSON *address_local_JSON = _convertToJSON(customer_update->address);
    if(address_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "address", address_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // customer_update->contact_person
    if(customer_update->contact_person) {
    if(cJSON_AddStringToObject(item, "contactPerson", customer_update->contact_person) == NULL) {
    goto fail; //String
    }
    }


    // customer_update->email
    if(customer_update->email) {
    if(cJSON_AddStringToObject(item, "email", customer_update->email) == NULL) {
    goto fail; //String
    }
    }


    // customer_update->external_order_number
    if(customer_update->external_order_number) {
    if(cJSON_AddStringToObject(item, "externalOrderNumber", customer_update->external_order_number) == NULL) {
    goto fail; //String
    }
    }


    // customer_update->name
    if(customer_update->name) {
    if(cJSON_AddStringToObject(item, "name", customer_update->name) == NULL) {
    goto fail; //String
    }
    }


    // customer_update->payment_grace_period_days
    if(customer_update->payment_grace_period_days) {
    if(cJSON_AddNumberToObject(item, "paymentGracePeriodDays", *customer_update->payment_grace_period_days) == NULL) {
    goto fail; //Numeric
    }
    }


    // customer_update->phone
    if(customer_update->phone) {
    if(cJSON_AddStringToObject(item, "phone", customer_update->phone) == NULL) {
    goto fail; //String
    }
    }


    // customer_update->vat_id
    if(customer_update->vat_id) {
    if(cJSON_AddStringToObject(item, "vatId", customer_update->vat_id) == NULL) {
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

customer_update_t *customer_update_parseFromJSON(cJSON *customer_updateJSON){

    customer_update_t *customer_update_local_var = NULL;

    // define the local variable for customer_update->address
    _t *address_local_nonprim = NULL;

    char *contact_person_local_str = NULL;

    char *email_local_str = NULL;

    char *external_order_number_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for customer_update->payment_grace_period_days
    int *payment_grace_period_days_local_var = NULL;

    char *phone_local_str = NULL;

    char *vat_id_local_str = NULL;

    // customer_update->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(customer_updateJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    address_local_nonprim = _parseFromJSON(address); //custom
    }

    // customer_update->contact_person
    cJSON *contact_person = cJSON_GetObjectItemCaseSensitive(customer_updateJSON, "contactPerson");
    if (cJSON_IsNull(contact_person)) {
        contact_person = NULL;
    }
    if (contact_person) { 
    if(!cJSON_IsString(contact_person) && !cJSON_IsNull(contact_person))
    {
    goto end; //String
    }
    }

    // customer_update->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(customer_updateJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // customer_update->external_order_number
    cJSON *external_order_number = cJSON_GetObjectItemCaseSensitive(customer_updateJSON, "externalOrderNumber");
    if (cJSON_IsNull(external_order_number)) {
        external_order_number = NULL;
    }
    if (external_order_number) { 
    if(!cJSON_IsString(external_order_number) && !cJSON_IsNull(external_order_number))
    {
    goto end; //String
    }
    }

    // customer_update->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(customer_updateJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // customer_update->payment_grace_period_days
    cJSON *payment_grace_period_days = cJSON_GetObjectItemCaseSensitive(customer_updateJSON, "paymentGracePeriodDays");
    if (cJSON_IsNull(payment_grace_period_days)) {
        payment_grace_period_days = NULL;
    }
    if (payment_grace_period_days) { 
    if(!cJSON_IsNumber(payment_grace_period_days))
    {
    goto end; //Numeric
    }
    payment_grace_period_days_local_var = malloc(sizeof(int));
    if(!payment_grace_period_days_local_var)
    {
        goto end;
    }
    *payment_grace_period_days_local_var = payment_grace_period_days->valuedouble;
    }

    // customer_update->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(customer_updateJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // customer_update->vat_id
    cJSON *vat_id = cJSON_GetObjectItemCaseSensitive(customer_updateJSON, "vatId");
    if (cJSON_IsNull(vat_id)) {
        vat_id = NULL;
    }
    if (vat_id) { 
    if(!cJSON_IsString(vat_id) && !cJSON_IsNull(vat_id))
    {
    goto end; //String
    }
    }


    if (contact_person && !cJSON_IsNull(contact_person)) contact_person_local_str = strdup(contact_person->valuestring);
    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (external_order_number && !cJSON_IsNull(external_order_number)) external_order_number_local_str = strdup(external_order_number->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (phone && !cJSON_IsNull(phone)) phone_local_str = strdup(phone->valuestring);
    if (vat_id && !cJSON_IsNull(vat_id)) vat_id_local_str = strdup(vat_id->valuestring);

    customer_update_local_var = customer_update_create_internal (
        address ? address_local_nonprim : NULL,
        contact_person_local_str,
        email_local_str,
        external_order_number_local_str,
        name_local_str,
        payment_grace_period_days_local_var,
        phone_local_str,
        vat_id_local_str
        );

    if (!customer_update_local_var) {
        goto end;
    }

    return customer_update_local_var;
end:
    if (address_local_nonprim) {
        _free(address_local_nonprim);
        address_local_nonprim = NULL;
    }
    if (contact_person_local_str) {
        free(contact_person_local_str);
        contact_person_local_str = NULL;
    }
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (external_order_number_local_str) {
        free(external_order_number_local_str);
        external_order_number_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (payment_grace_period_days_local_var) {
        free(payment_grace_period_days_local_var);
        payment_grace_period_days_local_var = NULL;
    }
    if (phone_local_str) {
        free(phone_local_str);
        phone_local_str = NULL;
    }
    if (vat_id_local_str) {
        free(vat_id_local_str);
        vat_id_local_str = NULL;
    }
    return NULL;

}
