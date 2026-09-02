#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "customer.h"



static customer_t *customer_create_internal(
    any_type_t *address,
    char *contact_person,
    char *email,
    char *external_order_number,
    char *name,
    int *payment_grace_period_days,
    char *phone,
    char *vat_id
    ) {
    customer_t *customer_local_var = malloc(sizeof(customer_t));
    if (!customer_local_var) {
        return NULL;
    }
    memset(customer_local_var, 0, sizeof(customer_t));
    customer_local_var->_library_owned = 1;
    customer_local_var->address = address;
    customer_local_var->contact_person = contact_person;
    customer_local_var->email = email;
    customer_local_var->external_order_number = external_order_number;
    customer_local_var->name = name;
    customer_local_var->payment_grace_period_days = payment_grace_period_days;
    customer_local_var->phone = phone;
    customer_local_var->vat_id = vat_id;
    return customer_local_var;
}

__attribute__((deprecated)) customer_t *customer_create(
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
    customer_t *result = customer_create_internal (
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

void customer_free(customer_t *customer) {
    if(NULL == customer){
        return ;
    }
    if(customer->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "customer_free");
        return ;
    }
    listEntry_t *listEntry;
    if (customer->address) {
        _free(customer->address);
        customer->address = NULL;
    }
    if (customer->contact_person) {
        free(customer->contact_person);
        customer->contact_person = NULL;
    }
    if (customer->email) {
        free(customer->email);
        customer->email = NULL;
    }
    if (customer->external_order_number) {
        free(customer->external_order_number);
        customer->external_order_number = NULL;
    }
    if (customer->name) {
        free(customer->name);
        customer->name = NULL;
    }
    if (customer->payment_grace_period_days) {
        free(customer->payment_grace_period_days);
        customer->payment_grace_period_days = NULL;
    }
    if (customer->phone) {
        free(customer->phone);
        customer->phone = NULL;
    }
    if (customer->vat_id) {
        free(customer->vat_id);
        customer->vat_id = NULL;
    }
    free(customer);
}

cJSON *customer_convertToJSON(customer_t *customer) {
    cJSON *item = cJSON_CreateObject();

    // customer->address
    if(customer->address) {
    cJSON *address_local_JSON = _convertToJSON(customer->address);
    if(address_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "address", address_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // customer->contact_person
    if(customer->contact_person) {
    if(cJSON_AddStringToObject(item, "contactPerson", customer->contact_person) == NULL) {
    goto fail; //String
    }
    }


    // customer->email
    if(customer->email) {
    if(cJSON_AddStringToObject(item, "email", customer->email) == NULL) {
    goto fail; //String
    }
    }


    // customer->external_order_number
    if(customer->external_order_number) {
    if(cJSON_AddStringToObject(item, "externalOrderNumber", customer->external_order_number) == NULL) {
    goto fail; //String
    }
    }


    // customer->name
    if (!customer->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", customer->name) == NULL) {
    goto fail; //String
    }


    // customer->payment_grace_period_days
    if(customer->payment_grace_period_days) {
    if(cJSON_AddNumberToObject(item, "paymentGracePeriodDays", *customer->payment_grace_period_days) == NULL) {
    goto fail; //Numeric
    }
    }


    // customer->phone
    if(customer->phone) {
    if(cJSON_AddStringToObject(item, "phone", customer->phone) == NULL) {
    goto fail; //String
    }
    }


    // customer->vat_id
    if(customer->vat_id) {
    if(cJSON_AddStringToObject(item, "vatId", customer->vat_id) == NULL) {
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

customer_t *customer_parseFromJSON(cJSON *customerJSON){

    customer_t *customer_local_var = NULL;

    // define the local variable for customer->address
    _t *address_local_nonprim = NULL;

    char *contact_person_local_str = NULL;

    char *email_local_str = NULL;

    char *external_order_number_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for customer->payment_grace_period_days
    int *payment_grace_period_days_local_var = NULL;

    char *phone_local_str = NULL;

    char *vat_id_local_str = NULL;

    // customer->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(customerJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    address_local_nonprim = _parseFromJSON(address); //custom
    }

    // customer->contact_person
    cJSON *contact_person = cJSON_GetObjectItemCaseSensitive(customerJSON, "contactPerson");
    if (cJSON_IsNull(contact_person)) {
        contact_person = NULL;
    }
    if (contact_person) { 
    if(!cJSON_IsString(contact_person) && !cJSON_IsNull(contact_person))
    {
    goto end; //String
    }
    }

    // customer->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(customerJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // customer->external_order_number
    cJSON *external_order_number = cJSON_GetObjectItemCaseSensitive(customerJSON, "externalOrderNumber");
    if (cJSON_IsNull(external_order_number)) {
        external_order_number = NULL;
    }
    if (external_order_number) { 
    if(!cJSON_IsString(external_order_number) && !cJSON_IsNull(external_order_number))
    {
    goto end; //String
    }
    }

    // customer->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(customerJSON, "name");
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

    // customer->payment_grace_period_days
    cJSON *payment_grace_period_days = cJSON_GetObjectItemCaseSensitive(customerJSON, "paymentGracePeriodDays");
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

    // customer->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(customerJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // customer->vat_id
    cJSON *vat_id = cJSON_GetObjectItemCaseSensitive(customerJSON, "vatId");
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

    customer_local_var = customer_create_internal (
        address ? address_local_nonprim : NULL,
        contact_person_local_str,
        email_local_str,
        external_order_number_local_str,
        name_local_str,
        payment_grace_period_days_local_var,
        phone_local_str,
        vat_id_local_str
        );

    if (!customer_local_var) {
        goto end;
    }

    return customer_local_var;
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
