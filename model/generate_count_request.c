#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "generate_count_request.h"



static generate_count_request_t *generate_count_request_create_internal(
    char *notes,
    list_t *product_ids,
    char *warehouse_id
    ) {
    generate_count_request_t *generate_count_request_local_var = malloc(sizeof(generate_count_request_t));
    if (!generate_count_request_local_var) {
        return NULL;
    }
    memset(generate_count_request_local_var, 0, sizeof(generate_count_request_t));
    generate_count_request_local_var->_library_owned = 1;
    generate_count_request_local_var->notes = notes;
    generate_count_request_local_var->product_ids = product_ids;
    generate_count_request_local_var->warehouse_id = warehouse_id;
    return generate_count_request_local_var;
}

__attribute__((deprecated)) generate_count_request_t *generate_count_request_create(
    char *notes,
    list_t *product_ids,
    char *warehouse_id
    ) {
    generate_count_request_t *result = generate_count_request_create_internal (
        notes,
        product_ids,
        warehouse_id
        );
    if (!result) {
    }
    return result;
}

void generate_count_request_free(generate_count_request_t *generate_count_request) {
    if(NULL == generate_count_request){
        return ;
    }
    if(generate_count_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "generate_count_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (generate_count_request->notes) {
        free(generate_count_request->notes);
        generate_count_request->notes = NULL;
    }
    if (generate_count_request->product_ids) {
        list_ForEach(listEntry, generate_count_request->product_ids) {
            free(listEntry->data);
        }
        list_freeList(generate_count_request->product_ids);
        generate_count_request->product_ids = NULL;
    }
    if (generate_count_request->warehouse_id) {
        free(generate_count_request->warehouse_id);
        generate_count_request->warehouse_id = NULL;
    }
    free(generate_count_request);
}

cJSON *generate_count_request_convertToJSON(generate_count_request_t *generate_count_request) {
    cJSON *item = cJSON_CreateObject();

    // generate_count_request->notes
    if(generate_count_request->notes) {
    if(cJSON_AddStringToObject(item, "notes", generate_count_request->notes) == NULL) {
    goto fail; //String
    }
    }


    // generate_count_request->product_ids
    if(generate_count_request->product_ids) {
    cJSON *product_ids = cJSON_AddArrayToObject(item, "productIds");
    if(product_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *product_idsListEntry;
    list_ForEach(product_idsListEntry, generate_count_request->product_ids) {
    if(cJSON_AddStringToObject(product_ids, "", product_idsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // generate_count_request->warehouse_id
    if (!generate_count_request->warehouse_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "warehouseId", generate_count_request->warehouse_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

generate_count_request_t *generate_count_request_parseFromJSON(cJSON *generate_count_requestJSON){

    generate_count_request_t *generate_count_request_local_var = NULL;

    char *notes_local_str = NULL;

    // define the local list for generate_count_request->product_ids
    list_t *product_idsList = NULL;

    char *warehouse_id_local_str = NULL;

    // generate_count_request->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(generate_count_requestJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // generate_count_request->product_ids
    cJSON *product_ids = cJSON_GetObjectItemCaseSensitive(generate_count_requestJSON, "productIds");
    if (cJSON_IsNull(product_ids)) {
        product_ids = NULL;
    }
    if (product_ids) { 
    cJSON *product_ids_local = NULL;
    if(!cJSON_IsArray(product_ids)) {
        goto end;//primitive container
    }
    product_idsList = list_createList();

    cJSON_ArrayForEach(product_ids_local, product_ids)
    {
        if(!cJSON_IsString(product_ids_local))
        {
            goto end;
        }
        list_addElement(product_idsList , strdup(product_ids_local->valuestring));
    }
    }

    // generate_count_request->warehouse_id
    cJSON *warehouse_id = cJSON_GetObjectItemCaseSensitive(generate_count_requestJSON, "warehouseId");
    if (cJSON_IsNull(warehouse_id)) {
        warehouse_id = NULL;
    }
    if (!warehouse_id) {
        goto end;
    }

    
    if(!cJSON_IsString(warehouse_id))
    {
    goto end; //String
    }


    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (warehouse_id && !cJSON_IsNull(warehouse_id)) warehouse_id_local_str = strdup(warehouse_id->valuestring);

    generate_count_request_local_var = generate_count_request_create_internal (
        notes_local_str,
        product_ids ? product_idsList : NULL,
        warehouse_id_local_str
        );

    if (!generate_count_request_local_var) {
        goto end;
    }

    return generate_count_request_local_var;
end:
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (product_idsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, product_idsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(product_idsList);
        product_idsList = NULL;
    }
    if (warehouse_id_local_str) {
        free(warehouse_id_local_str);
        warehouse_id_local_str = NULL;
    }
    return NULL;

}
