#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/product_attribute.h"
#include "../model/product_attribute_create.h"
#include "../model/product_attribute_update.h"


product_attribute_t*
ProductAttributeAPI_createProductAttribute(apiClient_t *apiClient, product_attribute_create_t *product_attribute_create);


void
ProductAttributeAPI_deleteProductAttribute(apiClient_t *apiClient, char *attribute_id);


product_attribute_t*
ProductAttributeAPI_getProductAttribute(apiClient_t *apiClient, char *attribute_id);


list_t*
ProductAttributeAPI_listProductAttributes(apiClient_t *apiClient, int *page, int *page_size, char *product_id, int *is_filterable, char *search);


product_attribute_t*
ProductAttributeAPI_updateProductAttribute(apiClient_t *apiClient, char *attribute_id, product_attribute_update_t *product_attribute_update);


