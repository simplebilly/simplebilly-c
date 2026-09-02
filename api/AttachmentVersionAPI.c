#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "AttachmentVersionAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


attachment_version_t*
AttachmentVersionAPI_createAttachmentVersion(apiClient_t *apiClient, char *attachment_id, new_version_request_t *new_version_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/attachments/{attachment_id}/versions");

    if(!attachment_id)
        goto end;


    // Path Params
    long sizeOfPathParams_attachment_id = strlen(attachment_id)+3 + sizeof("{ attachment_id }") - 1;
    if(attachment_id == NULL) {
        goto end;
    }
    char* localVarToReplace_attachment_id = malloc(sizeOfPathParams_attachment_id);
    sprintf(localVarToReplace_attachment_id, "{%s}", "attachment_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_attachment_id, attachment_id);



    // Body Param
    cJSON *localVarSingleItemJSON_new_version_request = NULL;
    if (new_version_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_new_version_request = new_version_request_convertToJSON(new_version_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_new_version_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","New current version recorded");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    attachment_version_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AttachmentVersionAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = attachment_version_parseFromJSON(AttachmentVersionAPIlocalVarJSON);
        cJSON_Delete(AttachmentVersionAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_attachment_id);
    if (localVarSingleItemJSON_new_version_request) {
        cJSON_Delete(localVarSingleItemJSON_new_version_request);
        localVarSingleItemJSON_new_version_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

list_t*
AttachmentVersionAPI_listAttachmentVersions(apiClient_t *apiClient, char *attachment_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/attachments/{attachment_id}/versions");

    if(!attachment_id)
        goto end;


    // Path Params
    long sizeOfPathParams_attachment_id = strlen(attachment_id)+3 + sizeof("{ attachment_id }") - 1;
    if(attachment_id == NULL) {
        goto end;
    }
    char* localVarToReplace_attachment_id = malloc(sizeOfPathParams_attachment_id);
    sprintf(localVarToReplace_attachment_id, "{%s}", "attachment_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_attachment_id, attachment_id);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AttachmentVersionAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(AttachmentVersionAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, AttachmentVersionAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( AttachmentVersionAPIlocalVarJSON);
        cJSON_Delete( VarJSON);
    }
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_attachment_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

attachment_t*
AttachmentVersionAPI_restoreAttachmentVersion(apiClient_t *apiClient, char *attachment_id, char *version_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/api/v1/attachments/{attachment_id}/versions/{version_id}/restore");

    if(!attachment_id)
        goto end;
    if(!version_id)
        goto end;


    // Path Params
    long sizeOfPathParams_attachment_id = strlen(attachment_id)+3 + strlen(version_id)+3 + sizeof("{ attachment_id }") - 1;
    if(attachment_id == NULL) {
        goto end;
    }
    char* localVarToReplace_attachment_id = malloc(sizeOfPathParams_attachment_id);
    sprintf(localVarToReplace_attachment_id, "{%s}", "attachment_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_attachment_id, attachment_id);

    // Path Params
    long sizeOfPathParams_version_id = strlen(attachment_id)+3 + strlen(version_id)+3 + sizeof("{ version_id }") - 1;
    if(version_id == NULL) {
        goto end;
    }
    char* localVarToReplace_version_id = malloc(sizeOfPathParams_version_id);
    sprintf(localVarToReplace_version_id, "{%s}", "version_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_version_id, version_id);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Attachment restored");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal server error");
    //}
    //nonprimitive not container
    attachment_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AttachmentVersionAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = attachment_parseFromJSON(AttachmentVersionAPIlocalVarJSON);
        cJSON_Delete(AttachmentVersionAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_attachment_id);
    free(localVarToReplace_version_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

