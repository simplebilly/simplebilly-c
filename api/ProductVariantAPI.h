#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/generate_variants_request.h"
#include "../model/plugin_error.h"
#include "../model/product_variant.h"


product_variant_t*
ProductVariantAPI_createProductVariant(apiClient_t *apiClient, product_variant_t *product_variant);


void
ProductVariantAPI_deleteProductVariant(apiClient_t *apiClient, char *variant_id);


list_t*
ProductVariantAPI_generateProductVariants(apiClient_t *apiClient, generate_variants_request_t *generate_variants_request);


product_variant_t*
ProductVariantAPI_getProductVariant(apiClient_t *apiClient, char *variant_id);


list_t*
ProductVariantAPI_listProductVariants(apiClient_t *apiClient, int *page, int *page_size, char *product_id, int *is_active);


product_variant_t*
ProductVariantAPI_updateProductVariant(apiClient_t *apiClient, char *variant_id, body);


