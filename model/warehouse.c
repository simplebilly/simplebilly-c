#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "warehouse.h"



static warehouse_t *warehouse_create_internal(
    char *address_city,
    country_code_t *address_country,
    char *address_street,
    char *address_zip,
    any_type_t *bin_locations,
    char *code,
    int *is_active,
    int *is_default,
    char *name,
    char *notes
    ) {
    warehouse_t *warehouse_local_var = malloc(sizeof(warehouse_t));
    if (!warehouse_local_var) {
        return NULL;
    }
    memset(warehouse_local_var, 0, sizeof(warehouse_t));
    warehouse_local_var->_library_owned = 1;
    warehouse_local_var->address_city = address_city;
    warehouse_local_var->address_country = address_country;
    warehouse_local_var->address_street = address_street;
    warehouse_local_var->address_zip = address_zip;
    warehouse_local_var->bin_locations = bin_locations;
    warehouse_local_var->code = code;
    warehouse_local_var->is_active = is_active;
    warehouse_local_var->is_default = is_default;
    warehouse_local_var->name = name;
    warehouse_local_var->notes = notes;
    return warehouse_local_var;
}

__attribute__((deprecated)) warehouse_t *warehouse_create(
    char *address_city,
    country_code_t *address_country,
    char *address_street,
    char *address_zip,
    any_type_t *bin_locations,
    char *code,
    int *is_active,
    int *is_default,
    char *name,
    char *notes
    ) {
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    int *is_default_copy = NULL;
    if (is_default) {
        is_default_copy = malloc(sizeof(int));
        if (is_default_copy) *is_default_copy = *is_default;
    }
    warehouse_t *result = warehouse_create_internal (
        address_city,
        address_country,
        address_street,
        address_zip,
        bin_locations,
        code,
        is_active_copy,
        is_default_copy,
        name,
        notes
        );
    if (!result) {
        free(is_active_copy);
        free(is_default_copy);
    }
    return result;
}

void warehouse_free(warehouse_t *warehouse) {
    if(NULL == warehouse){
        return ;
    }
    if(warehouse->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "warehouse_free");
        return ;
    }
    listEntry_t *listEntry;
    if (warehouse->address_city) {
        free(warehouse->address_city);
        warehouse->address_city = NULL;
    }
    if (warehouse->address_country) {
        country_code_free(warehouse->address_country);
        warehouse->address_country = NULL;
    }
    if (warehouse->address_street) {
        free(warehouse->address_street);
        warehouse->address_street = NULL;
    }
    if (warehouse->address_zip) {
        free(warehouse->address_zip);
        warehouse->address_zip = NULL;
    }
    if (warehouse->bin_locations) {
        _free(warehouse->bin_locations);
        warehouse->bin_locations = NULL;
    }
    if (warehouse->code) {
        free(warehouse->code);
        warehouse->code = NULL;
    }
    if (warehouse->is_active) {
        free(warehouse->is_active);
        warehouse->is_active = NULL;
    }
    if (warehouse->is_default) {
        free(warehouse->is_default);
        warehouse->is_default = NULL;
    }
    if (warehouse->name) {
        free(warehouse->name);
        warehouse->name = NULL;
    }
    if (warehouse->notes) {
        free(warehouse->notes);
        warehouse->notes = NULL;
    }
    free(warehouse);
}

cJSON *warehouse_convertToJSON(warehouse_t *warehouse) {
    cJSON *item = cJSON_CreateObject();

    // warehouse->address_city
    if(warehouse->address_city) {
    if(cJSON_AddStringToObject(item, "addressCity", warehouse->address_city) == NULL) {
    goto fail; //String
    }
    }


    // warehouse->address_country
    if(warehouse->address_country) {
    cJSON *address_country_local_JSON = country_code_convertToJSON(warehouse->address_country);
    if(address_country_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "addressCountry", address_country_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // warehouse->address_street
    if(warehouse->address_street) {
    if(cJSON_AddStringToObject(item, "addressStreet", warehouse->address_street) == NULL) {
    goto fail; //String
    }
    }


    // warehouse->address_zip
    if(warehouse->address_zip) {
    if(cJSON_AddStringToObject(item, "addressZip", warehouse->address_zip) == NULL) {
    goto fail; //String
    }
    }


    // warehouse->bin_locations
    if(warehouse->bin_locations) {
    cJSON *bin_locations_local_JSON = _convertToJSON(warehouse->bin_locations);
    if(bin_locations_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "binLocations", bin_locations_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // warehouse->code
    if (!warehouse->code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "code", warehouse->code) == NULL) {
    goto fail; //String
    }


    // warehouse->is_active
    if(warehouse->is_active) {
    if(cJSON_AddBoolToObject(item, "isActive", *warehouse->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // warehouse->is_default
    if(warehouse->is_default) {
    if(cJSON_AddBoolToObject(item, "isDefault", *warehouse->is_default) == NULL) {
    goto fail; //Bool
    }
    }


    // warehouse->name
    if (!warehouse->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", warehouse->name) == NULL) {
    goto fail; //String
    }


    // warehouse->notes
    if(warehouse->notes) {
    if(cJSON_AddStringToObject(item, "notes", warehouse->notes) == NULL) {
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

warehouse_t *warehouse_parseFromJSON(cJSON *warehouseJSON){

    warehouse_t *warehouse_local_var = NULL;

    char *address_city_local_str = NULL;

    // define the local variable for warehouse->address_country
    country_code_t *address_country_local_nonprim = NULL;

    char *address_street_local_str = NULL;

    char *address_zip_local_str = NULL;

    // define the local variable for warehouse->bin_locations
    _t *bin_locations_local_nonprim = NULL;

    char *code_local_str = NULL;

    // define the local variable for warehouse->is_active
    int *is_active_local_var = NULL;

    // define the local variable for warehouse->is_default
    int *is_default_local_var = NULL;

    char *name_local_str = NULL;

    char *notes_local_str = NULL;

    // warehouse->address_city
    cJSON *address_city = cJSON_GetObjectItemCaseSensitive(warehouseJSON, "addressCity");
    if (cJSON_IsNull(address_city)) {
        address_city = NULL;
    }
    if (address_city) { 
    if(!cJSON_IsString(address_city) && !cJSON_IsNull(address_city))
    {
    goto end; //String
    }
    }

    // warehouse->address_country
    cJSON *address_country = cJSON_GetObjectItemCaseSensitive(warehouseJSON, "addressCountry");
    if (cJSON_IsNull(address_country)) {
        address_country = NULL;
    }
    if (address_country) { 
    address_country_local_nonprim = country_code_parseFromJSON(address_country); //custom
    }

    // warehouse->address_street
    cJSON *address_street = cJSON_GetObjectItemCaseSensitive(warehouseJSON, "addressStreet");
    if (cJSON_IsNull(address_street)) {
        address_street = NULL;
    }
    if (address_street) { 
    if(!cJSON_IsString(address_street) && !cJSON_IsNull(address_street))
    {
    goto end; //String
    }
    }

    // warehouse->address_zip
    cJSON *address_zip = cJSON_GetObjectItemCaseSensitive(warehouseJSON, "addressZip");
    if (cJSON_IsNull(address_zip)) {
        address_zip = NULL;
    }
    if (address_zip) { 
    if(!cJSON_IsString(address_zip) && !cJSON_IsNull(address_zip))
    {
    goto end; //String
    }
    }

    // warehouse->bin_locations
    cJSON *bin_locations = cJSON_GetObjectItemCaseSensitive(warehouseJSON, "binLocations");
    if (cJSON_IsNull(bin_locations)) {
        bin_locations = NULL;
    }
    if (bin_locations) { 
    bin_locations_local_nonprim = _parseFromJSON(bin_locations); //custom
    }

    // warehouse->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(warehouseJSON, "code");
    if (cJSON_IsNull(code)) {
        code = NULL;
    }
    if (!code) {
        goto end;
    }

    
    if(!cJSON_IsString(code))
    {
    goto end; //String
    }

    // warehouse->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(warehouseJSON, "isActive");
    if (cJSON_IsNull(is_active)) {
        is_active = NULL;
    }
    if (is_active) { 
    if(!cJSON_IsBool(is_active))
    {
    goto end; //Bool
    }
    is_active_local_var = malloc(sizeof(int));
    if(!is_active_local_var)
    {
        goto end;
    }
    *is_active_local_var = is_active->valueint;
    }

    // warehouse->is_default
    cJSON *is_default = cJSON_GetObjectItemCaseSensitive(warehouseJSON, "isDefault");
    if (cJSON_IsNull(is_default)) {
        is_default = NULL;
    }
    if (is_default) { 
    if(!cJSON_IsBool(is_default))
    {
    goto end; //Bool
    }
    is_default_local_var = malloc(sizeof(int));
    if(!is_default_local_var)
    {
        goto end;
    }
    *is_default_local_var = is_default->valueint;
    }

    // warehouse->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(warehouseJSON, "name");
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

    // warehouse->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(warehouseJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }


    if (address_city && !cJSON_IsNull(address_city)) address_city_local_str = strdup(address_city->valuestring);
    if (address_street && !cJSON_IsNull(address_street)) address_street_local_str = strdup(address_street->valuestring);
    if (address_zip && !cJSON_IsNull(address_zip)) address_zip_local_str = strdup(address_zip->valuestring);
    if (code && !cJSON_IsNull(code)) code_local_str = strdup(code->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);

    warehouse_local_var = warehouse_create_internal (
        address_city_local_str,
        address_country ? address_country_local_nonprim : NULL,
        address_street_local_str,
        address_zip_local_str,
        bin_locations ? bin_locations_local_nonprim : NULL,
        code_local_str,
        is_active_local_var,
        is_default_local_var,
        name_local_str,
        notes_local_str
        );

    if (!warehouse_local_var) {
        goto end;
    }

    return warehouse_local_var;
end:
    if (address_city_local_str) {
        free(address_city_local_str);
        address_city_local_str = NULL;
    }
    if (address_country_local_nonprim) {
        country_code_free(address_country_local_nonprim);
        address_country_local_nonprim = NULL;
    }
    if (address_street_local_str) {
        free(address_street_local_str);
        address_street_local_str = NULL;
    }
    if (address_zip_local_str) {
        free(address_zip_local_str);
        address_zip_local_str = NULL;
    }
    if (bin_locations_local_nonprim) {
        _free(bin_locations_local_nonprim);
        bin_locations_local_nonprim = NULL;
    }
    if (code_local_str) {
        free(code_local_str);
        code_local_str = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (is_default_local_var) {
        free(is_default_local_var);
        is_default_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    return NULL;

}
