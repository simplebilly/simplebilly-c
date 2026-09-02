#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rate_request.h"



static rate_request_t *rate_request_create_internal(
    customer_info_t *customer,
    list_t *packages,
    address_t *recipient,
    address_t *sender
    ) {
    rate_request_t *rate_request_local_var = malloc(sizeof(rate_request_t));
    if (!rate_request_local_var) {
        return NULL;
    }
    memset(rate_request_local_var, 0, sizeof(rate_request_t));
    rate_request_local_var->_library_owned = 1;
    rate_request_local_var->customer = customer;
    rate_request_local_var->packages = packages;
    rate_request_local_var->recipient = recipient;
    rate_request_local_var->sender = sender;
    return rate_request_local_var;
}

__attribute__((deprecated)) rate_request_t *rate_request_create(
    customer_info_t *customer,
    list_t *packages,
    address_t *recipient,
    address_t *sender
    ) {
    rate_request_t *result = rate_request_create_internal (
        customer,
        packages,
        recipient,
        sender
        );
    if (!result) {
    }
    return result;
}

void rate_request_free(rate_request_t *rate_request) {
    if(NULL == rate_request){
        return ;
    }
    if(rate_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "rate_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (rate_request->customer) {
        customer_info_free(rate_request->customer);
        rate_request->customer = NULL;
    }
    if (rate_request->packages) {
        list_ForEach(listEntry, rate_request->packages) {
            package_free(listEntry->data);
        }
        list_freeList(rate_request->packages);
        rate_request->packages = NULL;
    }
    if (rate_request->recipient) {
        address_free(rate_request->recipient);
        rate_request->recipient = NULL;
    }
    if (rate_request->sender) {
        address_free(rate_request->sender);
        rate_request->sender = NULL;
    }
    free(rate_request);
}

cJSON *rate_request_convertToJSON(rate_request_t *rate_request) {
    cJSON *item = cJSON_CreateObject();

    // rate_request->customer
    if(rate_request->customer) {
    cJSON *customer_local_JSON = customer_info_convertToJSON(rate_request->customer);
    if(customer_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "customer", customer_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // rate_request->packages
    if (!rate_request->packages) {
        goto fail;
    }
    cJSON *packages = cJSON_AddArrayToObject(item, "packages");
    if(packages == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *packagesListEntry;
    if (rate_request->packages) {
    list_ForEach(packagesListEntry, rate_request->packages) {
    cJSON *itemLocal = package_convertToJSON(packagesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(packages, itemLocal);
    }
    }


    // rate_request->recipient
    if (!rate_request->recipient) {
        goto fail;
    }
    cJSON *recipient_local_JSON = address_convertToJSON(rate_request->recipient);
    if(recipient_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "recipient", recipient_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // rate_request->sender
    if (!rate_request->sender) {
        goto fail;
    }
    cJSON *sender_local_JSON = address_convertToJSON(rate_request->sender);
    if(sender_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sender", sender_local_JSON);
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

rate_request_t *rate_request_parseFromJSON(cJSON *rate_requestJSON){

    rate_request_t *rate_request_local_var = NULL;

    // define the local variable for rate_request->customer
    customer_info_t *customer_local_nonprim = NULL;

    // define the local list for rate_request->packages
    list_t *packagesList = NULL;

    // define the local variable for rate_request->recipient
    address_t *recipient_local_nonprim = NULL;

    // define the local variable for rate_request->sender
    address_t *sender_local_nonprim = NULL;

    // rate_request->customer
    cJSON *customer = cJSON_GetObjectItemCaseSensitive(rate_requestJSON, "customer");
    if (cJSON_IsNull(customer)) {
        customer = NULL;
    }
    if (customer) { 
    customer_local_nonprim = customer_info_parseFromJSON(customer); //nonprimitive
    }

    // rate_request->packages
    cJSON *packages = cJSON_GetObjectItemCaseSensitive(rate_requestJSON, "packages");
    if (cJSON_IsNull(packages)) {
        packages = NULL;
    }
    if (!packages) {
        goto end;
    }

    
    cJSON *packages_local_nonprimitive = NULL;
    if(!cJSON_IsArray(packages)){
        goto end; //nonprimitive container
    }

    packagesList = list_createList();

    cJSON_ArrayForEach(packages_local_nonprimitive,packages )
    {
        if(!cJSON_IsObject(packages_local_nonprimitive)){
            goto end;
        }
        package_t *packagesItem = package_parseFromJSON(packages_local_nonprimitive);

        list_addElement(packagesList, packagesItem);
    }

    // rate_request->recipient
    cJSON *recipient = cJSON_GetObjectItemCaseSensitive(rate_requestJSON, "recipient");
    if (cJSON_IsNull(recipient)) {
        recipient = NULL;
    }
    if (!recipient) {
        goto end;
    }

    
    recipient_local_nonprim = address_parseFromJSON(recipient); //nonprimitive

    // rate_request->sender
    cJSON *sender = cJSON_GetObjectItemCaseSensitive(rate_requestJSON, "sender");
    if (cJSON_IsNull(sender)) {
        sender = NULL;
    }
    if (!sender) {
        goto end;
    }

    
    sender_local_nonprim = address_parseFromJSON(sender); //nonprimitive



    rate_request_local_var = rate_request_create_internal (
        customer ? customer_local_nonprim : NULL,
        packagesList,
        recipient_local_nonprim,
        sender_local_nonprim
        );

    if (!rate_request_local_var) {
        goto end;
    }

    return rate_request_local_var;
end:
    if (customer_local_nonprim) {
        customer_info_free(customer_local_nonprim);
        customer_local_nonprim = NULL;
    }
    if (packagesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, packagesList) {
            package_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(packagesList);
        packagesList = NULL;
    }
    if (recipient_local_nonprim) {
        address_free(recipient_local_nonprim);
        recipient_local_nonprim = NULL;
    }
    if (sender_local_nonprim) {
        address_free(sender_local_nonprim);
        sender_local_nonprim = NULL;
    }
    return NULL;

}
