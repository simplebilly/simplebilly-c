#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/declaration.h"
#include "../model/declaration_create.h"
#include "../model/declaration_update.h"
#include "../model/plugin_error.h"


declaration_t*
DeclarationAPI_createDeclaration(apiClient_t *apiClient, declaration_create_t *declaration_create);


declaration_t*
DeclarationAPI_declarationRestore(apiClient_t *apiClient, char *id);


void
DeclarationAPI_deleteDeclaration(apiClient_t *apiClient, char *id);


declaration_t*
DeclarationAPI_getDeclaration(apiClient_t *apiClient, char *id);


list_t*
DeclarationAPI_getDeclarations(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


declaration_t*
DeclarationAPI_updateDeclaration(apiClient_t *apiClient, char *id, declaration_update_t *declaration_update);


