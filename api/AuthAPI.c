#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "AuthAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Accept an invite: create the account (or reuse an existing one) and join the inviting tenant. The invite token proves control of the mailbox.
//
void
AuthAPI_acceptInvite(apiClient_t *apiClient, accept_invite_request_t *accept_invite_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/auth/accept-invite");





    // Body Param
    cJSON *localVarSingleItemJSON_accept_invite_request = NULL;
    if (accept_invite_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_accept_invite_request = accept_invite_request_convertToJSON(accept_invite_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_accept_invite_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Invitation accepted");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Weak password or privacy policy not accepted");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Invalid or expired invite token");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_accept_invite_request) {
        cJSON_Delete(localVarSingleItemJSON_accept_invite_request);
        localVarSingleItemJSON_accept_invite_request = NULL;
    }
    free(localVarBodyParameters);

}

// Register a new user account
//
auth_response_t*
AuthAPI_callRegister(apiClient_t *apiClient, register_request_t *register_request)
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
    char *localVarPath = strdup("/auth/register");





    // Body Param
    cJSON *localVarSingleItemJSON_register_request = NULL;
    if (register_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_register_request = register_request_convertToJSON(register_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_register_request);
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","User registered, verification email sent");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 409) {
    //    printf("%s\n","User already exists");
    //}
    //nonprimitive not container
    auth_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AuthAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = auth_response_parseFromJSON(AuthAPIlocalVarJSON);
        cJSON_Delete(AuthAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_register_request) {
        cJSON_Delete(localVarSingleItemJSON_register_request);
        localVarSingleItemJSON_register_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Send a password reset email to the user
//
void
AuthAPI_forgotPassword(apiClient_t *apiClient, forgot_password_request_t *forgot_password_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/auth/forgot-password");





    // Body Param
    cJSON *localVarSingleItemJSON_forgot_password_request = NULL;
    if (forgot_password_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_forgot_password_request = forgot_password_request_convertToJSON(forgot_password_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_forgot_password_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Password reset email sent if the account exists");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","User not found");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_forgot_password_request) {
        cJSON_Delete(localVarSingleItemJSON_forgot_password_request);
        localVarSingleItemJSON_forgot_password_request = NULL;
    }
    free(localVarBodyParameters);

}

// Authenticate a user with email + password (optional TOTP)
//
auth_response_t*
AuthAPI_login(apiClient_t *apiClient, login_request_t *login_request)
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
    char *localVarPath = strdup("/auth/login");





    // Body Param
    cJSON *localVarSingleItemJSON_login_request = NULL;
    if (login_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_login_request = login_request_convertToJSON(login_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_login_request);
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Login successful, returns JWT tokens");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Invalid credentials");
    //}
    //nonprimitive not container
    auth_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AuthAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = auth_response_parseFromJSON(AuthAPIlocalVarJSON);
        cJSON_Delete(AuthAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_login_request) {
        cJSON_Delete(localVarSingleItemJSON_login_request);
        localVarSingleItemJSON_login_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Log out the current user (kills the assay session)
//
void
AuthAPI_logout(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/auth/logout");




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
    //    printf("%s\n","Logged out successfully");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    
    free(localVarPath);

}

// Request a magic link login (sends an email with a one-time link)
//
void
AuthAPI_magicLinkLogin(apiClient_t *apiClient, magic_link_request_t *magic_link_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/auth/magic-link");





    // Body Param
    cJSON *localVarSingleItemJSON_magic_link_request = NULL;
    if (magic_link_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_magic_link_request = magic_link_request_convertToJSON(magic_link_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_magic_link_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Magic link email sent if the account exists");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","User not found");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_magic_link_request) {
        cJSON_Delete(localVarSingleItemJSON_magic_link_request);
        localVarSingleItemJSON_magic_link_request = NULL;
    }
    free(localVarBodyParameters);

}

// Verify a magic link token and log the user in
//
auth_response_t*
AuthAPI_magicLinkVerify(apiClient_t *apiClient, magic_link_verify_request_t *magic_link_verify_request)
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
    char *localVarPath = strdup("/auth/magic-link/verify");





    // Body Param
    cJSON *localVarSingleItemJSON_magic_link_verify_request = NULL;
    if (magic_link_verify_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_magic_link_verify_request = magic_link_verify_request_convertToJSON(magic_link_verify_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_magic_link_verify_request);
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Magic link verified, returns JWT tokens");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Invalid or expired token");
    //}
    //nonprimitive not container
    auth_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AuthAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = auth_response_parseFromJSON(AuthAPIlocalVarJSON);
        cJSON_Delete(AuthAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_magic_link_verify_request) {
        cJSON_Delete(localVarSingleItemJSON_magic_link_verify_request);
        localVarSingleItemJSON_magic_link_verify_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Reset the user's password using a reset token
//
void
AuthAPI_resetPassword(apiClient_t *apiClient, reset_password_request_t *reset_password_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/auth/reset-password");





    // Body Param
    cJSON *localVarSingleItemJSON_reset_password_request = NULL;
    if (reset_password_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_reset_password_request = reset_password_request_convertToJSON(reset_password_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_reset_password_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Password reset successfully");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Invalid or expired token");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_reset_password_request) {
        cJSON_Delete(localVarSingleItemJSON_reset_password_request);
        localVarSingleItemJSON_reset_password_request = NULL;
    }
    free(localVarBodyParameters);

}

// Enable TOTP two-factor authentication by verifying a code
//
void
AuthAPI_totpEnable(apiClient_t *apiClient, totp_enable_request_t *totp_enable_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/auth/totp/enable");





    // Body Param
    cJSON *localVarSingleItemJSON_totp_enable_request = NULL;
    if (totp_enable_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_totp_enable_request = totp_enable_request_convertToJSON(totp_enable_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_totp_enable_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","TOTP enabled successfully");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Invalid TOTP code");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_totp_enable_request) {
        cJSON_Delete(localVarSingleItemJSON_totp_enable_request);
        localVarSingleItemJSON_totp_enable_request = NULL;
    }
    free(localVarBodyParameters);

}

// Set up TOTP two-factor authentication (generates secret + backup codes)
//
totp_setup_response_t*
AuthAPI_totpSetup(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/auth/totp/setup");




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
    //    printf("%s\n","TOTP setup data");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 409) {
    //    printf("%s\n","TOTP already enabled");
    //}
    //nonprimitive not container
    totp_setup_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AuthAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = totp_setup_response_parseFromJSON(AuthAPIlocalVarJSON);
        cJSON_Delete(AuthAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Verify a user's email address using a verification token
//
void
AuthAPI_verifyEmail(apiClient_t *apiClient, verify_email_request_t *verify_email_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/auth/verify-email");





    // Body Param
    cJSON *localVarSingleItemJSON_verify_email_request = NULL;
    if (verify_email_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_verify_email_request = verify_email_request_convertToJSON(verify_email_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_verify_email_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Email verified successfully");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Invalid or expired token");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_verify_email_request) {
        cJSON_Delete(localVarSingleItemJSON_verify_email_request);
        localVarSingleItemJSON_verify_email_request = NULL;
    }
    free(localVarBodyParameters);

}

