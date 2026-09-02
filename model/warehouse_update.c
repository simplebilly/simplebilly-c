#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "warehouse_update.h"



static warehouse_update_t *warehouse_update_create_internal(
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
    warehouse_update_t *warehouse_update_local_var = malloc(sizeof(warehouse_update_t));
    if (!warehouse_update_local_var) {
        return NULL;
    }
    memset(warehouse_update_local_var, 0, sizeof(warehouse_update_t));
    warehouse_update_local_var->_library_owned = 1;
    warehouse_update_local_var->address_city = address_city;
    warehouse_update_local_var->address_country = address_country;
    warehouse_update_local_var->address_street = address_street;
    warehouse_update_local_var->address_zip = address_zip;
    warehouse_update_local_var->bin_locations = bin_locations;
    warehouse_update_local_var->code = code;
    warehouse_update_local_var->is_active = is_active;
    warehouse_update_local_var->is_default = is_default;
    warehouse_update_local_var->name = name;
    warehouse_update_local_var->notes = notes;
    return warehouse_update_local_var;
}

__attribute__((deprecated)) warehouse_update_t *warehouse_update_create(
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
    warehouse_update_t *result = warehouse_update_create_internal (
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

void warehouse_update_free(warehouse_update_t *warehouse_update) {
    if(NULL == warehouse_update){
        return ;
    }
    if(warehouse_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "warehouse_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (warehouse_update->address_city) {
        free(warehouse_update->address_city);
        warehouse_update->address_city = NULL;
    }
    if (warehouse_update->address_country) {
        country_code_free(warehouse_update->address_country);
        warehouse_update->address_country = NULL;
    }
    if (warehouse_update->address_street) {
        free(warehouse_update->address_street);
        warehouse_update->address_street = NULL;
    }
    if (warehouse_update->address_zip) {
        free(warehouse_update->address_zip);
        warehouse_update->address_zip = NULL;
    }
    if (warehouse_update->bin_locations) {
        _free(warehouse_update->bin_locations);
        warehouse_update->bin_locations = NULL;
    }
    if (warehouse_update->code) {
        free(warehouse_update->code);
        warehouse_update->code = NULL;
    }
    if (warehouse_update->is_active) {
        free(warehouse_update->is_active);
        warehouse_update->is_active = NULL;
    }
    if (warehouse_update->is_default) {
        free(warehouse_update->is_default);
        warehouse_update->is_default = NULL;
    }
    if (warehouse_update->name) {
        free(warehouse_update->name);
        warehouse_update->name = NULL;
    }
    if (warehouse_update->notes) {
        free(warehouse_update->notes);
        warehouse_update->notes = NULL;
    }
    free(warehouse_update);
}

cJSON *warehouse_update_convertToJSON(warehouse_update_t *warehouse_update) {
    cJSON *item = cJSON_CreateObject();

    // warehouse_update->address_city
    if(warehouse_update->address_city) {
    if(cJSON_AddStringToObject(item, "addressCity", warehouse_update->address_city) == NULL) {
    goto fail; //String
    }
    }


    // warehouse_update->address_country
    if(warehouse_update->address_country) {
    cJSON *address_country_local_JSON = country_code_convertToJSON(warehouse_update->address_country);
    if(address_country_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "addressCountry", address_country_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // warehouse_update->address_street
    if(warehouse_update->address_street) {
    if(cJSON_AddStringToObject(item, "addressStreet", warehouse_update->address_street) == NULL) {
    goto fail; //String
    }
    }


    // warehouse_update->address_zip
    if(warehouse_update->address_zip) {
    if(cJSON_AddStringToObject(item, "addressZip", warehouse_update->address_zip) == NULL) {
    goto fail; //String
    }
    }


    // warehouse_update->bin_locations
    if(warehouse_update->bin_locations) {
    cJSON *bin_locations_local_JSON = _convertToJSON(warehouse_update->bin_locations);
    if(bin_locations_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "binLocations", bin_locations_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // warehouse_update->code
    if(warehouse_update->code) {
    if(cJSON_AddStringToObject(item, "code", warehouse_update->code) == NULL) {
    goto fail; //String
    }
    }


    // warehouse_update->is_active
    if(warehouse_update->is_active) {
    if(cJSON_AddBoolToObject(item, "isActive", *warehouse_update->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // warehouse_update->is_default
    if(warehouse_update->is_default) {
    if(cJSON_AddBoolToObject(item, "isDefault", *warehouse_update->is_default) == NULL) {
    goto fail; //Bool
    }
    }


    // warehouse_update->name
    if(warehouse_update->name) {
    if(cJSON_AddStringToObject(item, "name", warehouse_update->name) == NULL) {
    goto fail; //String
    }
    }


    // warehouse_update->notes
    if(warehouse_update->notes) {
    if(cJSON_AddStringToObject(item, "notes", warehouse_update->notes) == NULL) {
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

warehouse_update_t *warehouse_update_parseFromJSON(cJSON *warehouse_updateJSON){

    warehouse_update_t *warehouse_update_local_var = NULL;

    char *address_city_local_str = NULL;

    // define the local variable for warehouse_update->address_country
    country_code_t *address_country_local_nonprim = NULL;

    char *address_street_local_str = NULL;

    char *address_zip_local_str = NULL;

    // define the local variable for warehouse_update->bin_locations
    _t *bin_locations_local_nonprim = NULL;

    char *code_local_str = NULL;

    // define the local variable for warehouse_update->is_active
    int *is_active_local_var = NULL;

    // define the local variable for warehouse_update->is_default
    int *is_default_local_var = NULL;

    char *name_local_str = NULL;

    char *notes_local_str = NULL;

    // warehouse_update->address_city
    cJSON *address_city = cJSON_GetObjectItemCaseSensitive(warehouse_updateJSON, "addressCity");
    if (cJSON_IsNull(address_city)) {
        address_city = NULL;
    }
    if (address_city) { 
    if(!cJSON_IsString(address_city) && !cJSON_IsNull(address_city))
    {
    goto end; //String
    }
    }

    // warehouse_update->address_country
    cJSON *address_country = cJSON_GetObjectItemCaseSensitive(warehouse_updateJSON, "addressCountry");
    if (cJSON_IsNull(address_country)) {
        address_country = NULL;
    }
    if (address_country) { 
    address_country_local_nonprim = country_code_parseFromJSON(address_country); //custom
    }

    // warehouse_update->address_street
    cJSON *address_street = cJSON_GetObjectItemCaseSensitive(warehouse_updateJSON, "addressStreet");
    if (cJSON_IsNull(address_street)) {
        address_street = NULL;
    }
    if (address_street) { 
    if(!cJSON_IsString(address_street) && !cJSON_IsNull(address_street))
    {
    goto end; //String
    }
    }

    // warehouse_update->address_zip
    cJSON *address_zip = cJSON_GetObjectItemCaseSensitive(warehouse_updateJSON, "addressZip");
    if (cJSON_IsNull(address_zip)) {
        address_zip = NULL;
    }
    if (address_zip) { 
    if(!cJSON_IsString(address_zip) && !cJSON_IsNull(address_zip))
    {
    goto end; //String
    }
    }

    // warehouse_update->bin_locations
    cJSON *bin_locations = cJSON_GetObjectItemCaseSensitive(warehouse_updateJSON, "binLocations");
    if (cJSON_IsNull(bin_locations)) {
        bin_locations = NULL;
    }
    if (bin_locations) { 
    bin_locations_local_nonprim = _parseFromJSON(bin_locations); //custom
    }

    // warehouse_update->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(warehouse_updateJSON, "code");
    if (cJSON_IsNull(code)) {
        code = NULL;
    }
    if (code) { 
    if(!cJSON_IsString(code) && !cJSON_IsNull(code))
    {
    goto end; //String
    }
    }

    // warehouse_update->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(warehouse_updateJSON, "isActive");
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

    // warehouse_update->is_default
    cJSON *is_default = cJSON_GetObjectItemCaseSensitive(warehouse_updateJSON, "isDefault");
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

    // warehouse_update->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(warehouse_updateJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // warehouse_update->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(warehouse_updateJSON, "notes");
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

    warehouse_update_local_var = warehouse_update_create_internal (
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

    if (!warehouse_update_local_var) {
        goto end;
    }

    return warehouse_update_local_var;
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
