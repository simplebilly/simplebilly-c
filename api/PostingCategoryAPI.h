#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/plugin_error.h"
#include "../model/posting_category.h"


posting_category_t*
PostingCategoryAPI_createPostingCategory(apiClient_t *apiClient, body);


void
PostingCategoryAPI_deletePostingCategory(apiClient_t *apiClient, char *category_id);


list_t*
PostingCategoryAPI_listPostingCategories(apiClient_t *apiClient);


void
PostingCategoryAPI_seedPostingCategories(apiClient_t *apiClient, char *skr_version);


posting_category_t*
PostingCategoryAPI_updatePostingCategory(apiClient_t *apiClient, char *category_id, body);


