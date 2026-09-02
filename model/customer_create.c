#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "customer_create.h"



static customer_create_t *customer_create_create_internal(
    any_type_t *address,
    char *contact_person,
    char *email,
    char *external_order_number,
    char *name,
    int *payment_grace_period_days,
    char *phone,
    char *vat_id
    ) {
    customer_create_t *customer_create_local_var = malloc(sizeof(customer_create_t));
    if (!customer_create_local_var) {
        return NULL;
    }
    memset(customer_create_local_var, 0, sizeof(customer_create_t));
    customer_create_local_var->_library_owned = 1;
    customer_create_local_var->address = address;
    customer_create_local_var->contact_person = contact_person;
    customer_create_local_var->email = email;
    customer_create_local_var->external_order_number = external_order_number;
    customer_create_local_var->name = name;
    customer_create_local_var->payment_grace_period_days = payment_grace_period_days;
    customer_create_local_var->phone = phone;
    customer_create_local_var->vat_id = vat_id;
    return customer_create_local_var;
}

__attribute__((deprecated)) customer_create_t *customer_create_create(
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
    customer_create_t *result = customer_create_create_internal (
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

void customer_create_free(customer_create_t *customer_create) {
    if(NULL == customer_create){
        return ;
    }
    if(customer_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "customer_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (customer_create->address) {
        _free(customer_create->address);
        customer_create->address = NULL;
    }
    if (customer_create->contact_person) {
        free(customer_create->contact_person);
        customer_create->contact_person = NULL;
    }
    if (customer_create->email) {
        free(customer_create->email);
        customer_create->email = NULL;
    }
    if (customer_create->external_order_number) {
        free(customer_create->external_order_number);
        customer_create->external_order_number = NULL;
    }
    if (customer_create->name) {
        free(customer_create->name);
        customer_create->name = NULL;
    }
    if (customer_create->payment_grace_period_days) {
        free(customer_create->payment_grace_period_days);
        customer_create->payment_grace_period_days = NULL;
    }
    if (customer_create->phone) {
        free(customer_create->phone);
        customer_create->phone = NULL;
    }
    if (customer_create->vat_id) {
        free(customer_create->vat_id);
        customer_create->vat_id = NULL;
    }
    free(customer_create);
}

cJSON *customer_create_convertToJSON(customer_create_t *customer_create) {
    cJSON *item = cJSON_CreateObject();

    // customer_create->address
    if(customer_create->address) {
    cJSON *address_local_JSON = _convertToJSON(customer_create->address);
    if(address_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "address", address_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // customer_create->contact_person
    if(customer_create->contact_person) {
    if(cJSON_AddStringToObject(item, "contactPerson", customer_create->contact_person) == NULL) {
    goto fail; //String
    }
    }


    // customer_create->email
    if(customer_create->email) {
    if(cJSON_AddStringToObject(item, "email", customer_create->email) == NULL) {
    goto fail; //String
    }
    }


    // customer_create->external_order_number
    if(customer_create->external_order_number) {
    if(cJSON_AddStringToObject(item, "externalOrderNumber", customer_create->external_order_number) == NULL) {
    goto fail; //String
    }
    }


    // customer_create->name
    if (!customer_create->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", customer_create->name) == NULL) {
    goto fail; //String
    }


    // customer_create->payment_grace_period_days
    if(customer_create->payment_grace_period_days) {
    if(cJSON_AddNumberToObject(item, "paymentGracePeriodDays", *customer_create->payment_grace_period_days) == NULL) {
    goto fail; //Numeric
    }
    }


    // customer_create->phone
    if(customer_create->phone) {
    if(cJSON_AddStringToObject(item, "phone", customer_create->phone) == NULL) {
    goto fail; //String
    }
    }


    // customer_create->vat_id
    if(customer_create->vat_id) {
    if(cJSON_AddStringToObject(item, "vatId", customer_create->vat_id) == NULL) {
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

customer_create_t *customer_create_parseFromJSON(cJSON *customer_createJSON){

    customer_create_t *customer_create_local_var = NULL;

    // define the local variable for customer_create->address
    _t *address_local_nonprim = NULL;

    char *contact_person_local_str = NULL;

    char *email_local_str = NULL;

    char *external_order_number_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for customer_create->payment_grace_period_days
    int *payment_grace_period_days_local_var = NULL;

    char *phone_local_str = NULL;

    char *vat_id_local_str = NULL;

    // customer_create->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(customer_createJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    address_local_nonprim = _parseFromJSON(address); //custom
    }

    // customer_create->contact_person
    cJSON *contact_person = cJSON_GetObjectItemCaseSensitive(customer_createJSON, "contactPerson");
    if (cJSON_IsNull(contact_person)) {
        contact_person = NULL;
    }
    if (contact_person) { 
    if(!cJSON_IsString(contact_person) && !cJSON_IsNull(contact_person))
    {
    goto end; //String
    }
    }

    // customer_create->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(customer_createJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // customer_create->external_order_number
    cJSON *external_order_number = cJSON_GetObjectItemCaseSensitive(customer_createJSON, "externalOrderNumber");
    if (cJSON_IsNull(external_order_number)) {
        external_order_number = NULL;
    }
    if (external_order_number) { 
    if(!cJSON_IsString(external_order_number) && !cJSON_IsNull(external_order_number))
    {
    goto end; //String
    }
    }

    // customer_create->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(customer_createJSON, "name");
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

    // customer_create->payment_grace_period_days
    cJSON *payment_grace_period_days = cJSON_GetObjectItemCaseSensitive(customer_createJSON, "paymentGracePeriodDays");
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

    // customer_create->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(customer_createJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // customer_create->vat_id
    cJSON *vat_id = cJSON_GetObjectItemCaseSensitive(customer_createJSON, "vatId");
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

    customer_create_local_var = customer_create_create_internal (
        address ? address_local_nonprim : NULL,
        contact_person_local_str,
        email_local_str,
        external_order_number_local_str,
        name_local_str,
        payment_grace_period_days_local_var,
        phone_local_str,
        vat_id_local_str
        );

    if (!customer_create_local_var) {
        goto end;
    }

    return customer_create_local_var;
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
