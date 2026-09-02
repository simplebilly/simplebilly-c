#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "balance_sheet.h"



static balance_sheet_t *balance_sheet_create_internal(
    list_t *assets,
    int *balanced,
    list_t *equity_liabilities,
    char *total_assets,
    char *total_equity_liabilities
    ) {
    balance_sheet_t *balance_sheet_local_var = malloc(sizeof(balance_sheet_t));
    if (!balance_sheet_local_var) {
        return NULL;
    }
    memset(balance_sheet_local_var, 0, sizeof(balance_sheet_t));
    balance_sheet_local_var->_library_owned = 1;
    balance_sheet_local_var->assets = assets;
    balance_sheet_local_var->balanced = balanced;
    balance_sheet_local_var->equity_liabilities = equity_liabilities;
    balance_sheet_local_var->total_assets = total_assets;
    balance_sheet_local_var->total_equity_liabilities = total_equity_liabilities;
    return balance_sheet_local_var;
}

__attribute__((deprecated)) balance_sheet_t *balance_sheet_create(
    list_t *assets,
    int *balanced,
    list_t *equity_liabilities,
    char *total_assets,
    char *total_equity_liabilities
    ) {
    int *balanced_copy = NULL;
    if (balanced) {
        balanced_copy = malloc(sizeof(int));
        if (balanced_copy) *balanced_copy = *balanced;
    }
    balance_sheet_t *result = balance_sheet_create_internal (
        assets,
        balanced_copy,
        equity_liabilities,
        total_assets,
        total_equity_liabilities
        );
    if (!result) {
        free(balanced_copy);
    }
    return result;
}

void balance_sheet_free(balance_sheet_t *balance_sheet) {
    if(NULL == balance_sheet){
        return ;
    }
    if(balance_sheet->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "balance_sheet_free");
        return ;
    }
    listEntry_t *listEntry;
    if (balance_sheet->assets) {
        list_ForEach(listEntry, balance_sheet->assets) {
            balance_item_free(listEntry->data);
        }
        list_freeList(balance_sheet->assets);
        balance_sheet->assets = NULL;
    }
    if (balance_sheet->balanced) {
        free(balance_sheet->balanced);
        balance_sheet->balanced = NULL;
    }
    if (balance_sheet->equity_liabilities) {
        list_ForEach(listEntry, balance_sheet->equity_liabilities) {
            balance_item_free(listEntry->data);
        }
        list_freeList(balance_sheet->equity_liabilities);
        balance_sheet->equity_liabilities = NULL;
    }
    if (balance_sheet->total_assets) {
        free(balance_sheet->total_assets);
        balance_sheet->total_assets = NULL;
    }
    if (balance_sheet->total_equity_liabilities) {
        free(balance_sheet->total_equity_liabilities);
        balance_sheet->total_equity_liabilities = NULL;
    }
    free(balance_sheet);
}

cJSON *balance_sheet_convertToJSON(balance_sheet_t *balance_sheet) {
    cJSON *item = cJSON_CreateObject();

    // balance_sheet->assets
    if (!balance_sheet->assets) {
        goto fail;
    }
    cJSON *assets = cJSON_AddArrayToObject(item, "assets");
    if(assets == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *assetsListEntry;
    if (balance_sheet->assets) {
    list_ForEach(assetsListEntry, balance_sheet->assets) {
    cJSON *itemLocal = balance_item_convertToJSON(assetsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(assets, itemLocal);
    }
    }


    // balance_sheet->balanced
    if (!balance_sheet->balanced) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "balanced", *balance_sheet->balanced) == NULL) {
    goto fail; //Bool
    }


    // balance_sheet->equity_liabilities
    if (!balance_sheet->equity_liabilities) {
        goto fail;
    }
    cJSON *equity_liabilities = cJSON_AddArrayToObject(item, "equity_liabilities");
    if(equity_liabilities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *equity_liabilitiesListEntry;
    if (balance_sheet->equity_liabilities) {
    list_ForEach(equity_liabilitiesListEntry, balance_sheet->equity_liabilities) {
    cJSON *itemLocal = balance_item_convertToJSON(equity_liabilitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(equity_liabilities, itemLocal);
    }
    }


    // balance_sheet->total_assets
    if (!balance_sheet->total_assets) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_assets", balance_sheet->total_assets) == NULL) {
    goto fail; //String
    }


    // balance_sheet->total_equity_liabilities
    if (!balance_sheet->total_equity_liabilities) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_equity_liabilities", balance_sheet->total_equity_liabilities) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

balance_sheet_t *balance_sheet_parseFromJSON(cJSON *balance_sheetJSON){

    balance_sheet_t *balance_sheet_local_var = NULL;

    // define the local list for balance_sheet->assets
    list_t *assetsList = NULL;

    // define the local variable for balance_sheet->balanced
    int *balanced_local_var = NULL;

    // define the local list for balance_sheet->equity_liabilities
    list_t *equity_liabilitiesList = NULL;

    char *total_assets_local_str = NULL;

    char *total_equity_liabilities_local_str = NULL;

    // balance_sheet->assets
    cJSON *assets = cJSON_GetObjectItemCaseSensitive(balance_sheetJSON, "assets");
    if (cJSON_IsNull(assets)) {
        assets = NULL;
    }
    if (!assets) {
        goto end;
    }

    
    cJSON *assets_local_nonprimitive = NULL;
    if(!cJSON_IsArray(assets)){
        goto end; //nonprimitive container
    }

    assetsList = list_createList();

    cJSON_ArrayForEach(assets_local_nonprimitive,assets )
    {
        if(!cJSON_IsObject(assets_local_nonprimitive)){
            goto end;
        }
        balance_item_t *assetsItem = balance_item_parseFromJSON(assets_local_nonprimitive);

        list_addElement(assetsList, assetsItem);
    }

    // balance_sheet->balanced
    cJSON *balanced = cJSON_GetObjectItemCaseSensitive(balance_sheetJSON, "balanced");
    if (cJSON_IsNull(balanced)) {
        balanced = NULL;
    }
    if (!balanced) {
        goto end;
    }

    
    if(!cJSON_IsBool(balanced))
    {
    goto end; //Bool
    }
    balanced_local_var = malloc(sizeof(int));
    if(!balanced_local_var)
    {
        goto end;
    }
    *balanced_local_var = balanced->valueint;

    // balance_sheet->equity_liabilities
    cJSON *equity_liabilities = cJSON_GetObjectItemCaseSensitive(balance_sheetJSON, "equity_liabilities");
    if (cJSON_IsNull(equity_liabilities)) {
        equity_liabilities = NULL;
    }
    if (!equity_liabilities) {
        goto end;
    }

    
    cJSON *equity_liabilities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(equity_liabilities)){
        goto end; //nonprimitive container
    }

    equity_liabilitiesList = list_createList();

    cJSON_ArrayForEach(equity_liabilities_local_nonprimitive,equity_liabilities )
    {
        if(!cJSON_IsObject(equity_liabilities_local_nonprimitive)){
            goto end;
        }
        balance_item_t *equity_liabilitiesItem = balance_item_parseFromJSON(equity_liabilities_local_nonprimitive);

        list_addElement(equity_liabilitiesList, equity_liabilitiesItem);
    }

    // balance_sheet->total_assets
    cJSON *total_assets = cJSON_GetObjectItemCaseSensitive(balance_sheetJSON, "total_assets");
    if (cJSON_IsNull(total_assets)) {
        total_assets = NULL;
    }
    if (!total_assets) {
        goto end;
    }

    
    if(!cJSON_IsString(total_assets))
    {
    goto end; //String
    }

    // balance_sheet->total_equity_liabilities
    cJSON *total_equity_liabilities = cJSON_GetObjectItemCaseSensitive(balance_sheetJSON, "total_equity_liabilities");
    if (cJSON_IsNull(total_equity_liabilities)) {
        total_equity_liabilities = NULL;
    }
    if (!total_equity_liabilities) {
        goto end;
    }

    
    if(!cJSON_IsString(total_equity_liabilities))
    {
    goto end; //String
    }


    if (total_assets && !cJSON_IsNull(total_assets)) total_assets_local_str = strdup(total_assets->valuestring);
    if (total_equity_liabilities && !cJSON_IsNull(total_equity_liabilities)) total_equity_liabilities_local_str = strdup(total_equity_liabilities->valuestring);

    balance_sheet_local_var = balance_sheet_create_internal (
        assetsList,
        balanced_local_var,
        equity_liabilitiesList,
        total_assets_local_str,
        total_equity_liabilities_local_str
        );

    if (!balance_sheet_local_var) {
        goto end;
    }

    return balance_sheet_local_var;
end:
    if (assetsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, assetsList) {
            balance_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(assetsList);
        assetsList = NULL;
    }
    if (balanced_local_var) {
        free(balanced_local_var);
        balanced_local_var = NULL;
    }
    if (equity_liabilitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, equity_liabilitiesList) {
            balance_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(equity_liabilitiesList);
        equity_liabilitiesList = NULL;
    }
    if (total_assets_local_str) {
        free(total_assets_local_str);
        total_assets_local_str = NULL;
    }
    if (total_equity_liabilities_local_str) {
        free(total_equity_liabilities_local_str);
        total_equity_liabilities_local_str = NULL;
    }
    return NULL;

}
