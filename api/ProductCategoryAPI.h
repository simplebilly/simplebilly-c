#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/plugin_error.h"
#include "../model/product_category.h"


product_category_t*
ProductCategoryAPI_createProductCategory(apiClient_t *apiClient, product_category_t *product_category);


void
ProductCategoryAPI_deleteProductCategory(apiClient_t *apiClient, char *category_id);


product_category_t*
ProductCategoryAPI_getProductCategory(apiClient_t *apiClient, char *category_id);


list_t*
ProductCategoryAPI_listProductCategories(apiClient_t *apiClient);


product_category_t*
ProductCategoryAPI_updateProductCategory(apiClient_t *apiClient, char *category_id, body);


