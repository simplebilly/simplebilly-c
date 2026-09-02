#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "address.h"



static address_t *address_create_internal(
    char *city,
    char *company,
    char *country,
    char *email,
    char *name,
    char *phone,
    char *street,
    char *street_number,
    char *zip
    ) {
    address_t *address_local_var = malloc(sizeof(address_t));
    if (!address_local_var) {
        return NULL;
    }
    memset(address_local_var, 0, sizeof(address_t));
    address_local_var->_library_owned = 1;
    address_local_var->city = city;
    address_local_var->company = company;
    address_local_var->country = country;
    address_local_var->email = email;
    address_local_var->name = name;
    address_local_var->phone = phone;
    address_local_var->street = street;
    address_local_var->street_number = street_number;
    address_local_var->zip = zip;
    return address_local_var;
}

__attribute__((deprecated)) address_t *address_create(
    char *city,
    char *company,
    char *country,
    char *email,
    char *name,
    char *phone,
    char *street,
    char *street_number,
    char *zip
    ) {
    address_t *result = address_create_internal (
        city,
        company,
        country,
        email,
        name,
        phone,
        street,
        street_number,
        zip
        );
    if (!result) {
    }
    return result;
}

void address_free(address_t *address) {
    if(NULL == address){
        return ;
    }
    if(address->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "address_free");
        return ;
    }
    listEntry_t *listEntry;
    if (address->city) {
        free(address->city);
        address->city = NULL;
    }
    if (address->company) {
        free(address->company);
        address->company = NULL;
    }
    if (address->country) {
        free(address->country);
        address->country = NULL;
    }
    if (address->email) {
        free(address->email);
        address->email = NULL;
    }
    if (address->name) {
        free(address->name);
        address->name = NULL;
    }
    if (address->phone) {
        free(address->phone);
        address->phone = NULL;
    }
    if (address->street) {
        free(address->street);
        address->street = NULL;
    }
    if (address->street_number) {
        free(address->street_number);
        address->street_number = NULL;
    }
    if (address->zip) {
        free(address->zip);
        address->zip = NULL;
    }
    free(address);
}

cJSON *address_convertToJSON(address_t *address) {
    cJSON *item = cJSON_CreateObject();

    // address->city
    if (!address->city) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "city", address->city) == NULL) {
    goto fail; //String
    }


    // address->company
    if(address->company) {
    if(cJSON_AddStringToObject(item, "company", address->company) == NULL) {
    goto fail; //String
    }
    }


    // address->country
    if (!address->country) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "country", address->country) == NULL) {
    goto fail; //String
    }


    // address->email
    if(address->email) {
    if(cJSON_AddStringToObject(item, "email", address->email) == NULL) {
    goto fail; //String
    }
    }


    // address->name
    if (!address->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", address->name) == NULL) {
    goto fail; //String
    }


    // address->phone
    if(address->phone) {
    if(cJSON_AddStringToObject(item, "phone", address->phone) == NULL) {
    goto fail; //String
    }
    }


    // address->street
    if (!address->street) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "street", address->street) == NULL) {
    goto fail; //String
    }


    // address->street_number
    if (!address->street_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "street_number", address->street_number) == NULL) {
    goto fail; //String
    }


    // address->zip
    if (!address->zip) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "zip", address->zip) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

address_t *address_parseFromJSON(cJSON *addressJSON){

    address_t *address_local_var = NULL;

    char *city_local_str = NULL;

    char *company_local_str = NULL;

    char *country_local_str = NULL;

    char *email_local_str = NULL;

    char *name_local_str = NULL;

    char *phone_local_str = NULL;

    char *street_local_str = NULL;

    char *street_number_local_str = NULL;

    char *zip_local_str = NULL;

    // address->city
    cJSON *city = cJSON_GetObjectItemCaseSensitive(addressJSON, "city");
    if (cJSON_IsNull(city)) {
        city = NULL;
    }
    if (!city) {
        goto end;
    }

    
    if(!cJSON_IsString(city))
    {
    goto end; //String
    }

    // address->company
    cJSON *company = cJSON_GetObjectItemCaseSensitive(addressJSON, "company");
    if (cJSON_IsNull(company)) {
        company = NULL;
    }
    if (company) { 
    if(!cJSON_IsString(company) && !cJSON_IsNull(company))
    {
    goto end; //String
    }
    }

    // address->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(addressJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (!country) {
        goto end;
    }

    
    if(!cJSON_IsString(country))
    {
    goto end; //String
    }

    // address->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(addressJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // address->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(addressJSON, "name");
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

    // address->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(addressJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // address->street
    cJSON *street = cJSON_GetObjectItemCaseSensitive(addressJSON, "street");
    if (cJSON_IsNull(street)) {
        street = NULL;
    }
    if (!street) {
        goto end;
    }

    
    if(!cJSON_IsString(street))
    {
    goto end; //String
    }

    // address->street_number
    cJSON *street_number = cJSON_GetObjectItemCaseSensitive(addressJSON, "street_number");
    if (cJSON_IsNull(street_number)) {
        street_number = NULL;
    }
    if (!street_number) {
        goto end;
    }

    
    if(!cJSON_IsString(street_number))
    {
    goto end; //String
    }

    // address->zip
    cJSON *zip = cJSON_GetObjectItemCaseSensitive(addressJSON, "zip");
    if (cJSON_IsNull(zip)) {
        zip = NULL;
    }
    if (!zip) {
        goto end;
    }

    
    if(!cJSON_IsString(zip))
    {
    goto end; //String
    }


    if (city && !cJSON_IsNull(city)) city_local_str = strdup(city->valuestring);
    if (company && !cJSON_IsNull(company)) company_local_str = strdup(company->valuestring);
    if (country && !cJSON_IsNull(country)) country_local_str = strdup(country->valuestring);
    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (phone && !cJSON_IsNull(phone)) phone_local_str = strdup(phone->valuestring);
    if (street && !cJSON_IsNull(street)) street_local_str = strdup(street->valuestring);
    if (street_number && !cJSON_IsNull(street_number)) street_number_local_str = strdup(street_number->valuestring);
    if (zip && !cJSON_IsNull(zip)) zip_local_str = strdup(zip->valuestring);

    address_local_var = address_create_internal (
        city_local_str,
        company_local_str,
        country_local_str,
        email_local_str,
        name_local_str,
        phone_local_str,
        street_local_str,
        street_number_local_str,
        zip_local_str
        );

    if (!address_local_var) {
        goto end;
    }

    return address_local_var;
end:
    if (city_local_str) {
        free(city_local_str);
        city_local_str = NULL;
    }
    if (company_local_str) {
        free(company_local_str);
        company_local_str = NULL;
    }
    if (country_local_str) {
        free(country_local_str);
        country_local_str = NULL;
    }
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (phone_local_str) {
        free(phone_local_str);
        phone_local_str = NULL;
    }
    if (street_local_str) {
        free(street_local_str);
        street_local_str = NULL;
    }
    if (street_number_local_str) {
        free(street_number_local_str);
        street_number_local_str = NULL;
    }
    if (zip_local_str) {
        free(zip_local_str);
        zip_local_str = NULL;
    }
    return NULL;

}
