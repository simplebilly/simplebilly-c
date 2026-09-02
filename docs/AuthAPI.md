# AuthAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AuthAPI_acceptInvite**](AuthAPI.md#AuthAPI_acceptInvite) | **POST** /auth/accept-invite | Accept an invite: create the account (or reuse an existing one) and join the inviting tenant. The invite token proves control of the mailbox.
[**AuthAPI_callRegister**](AuthAPI.md#AuthAPI_callRegister) | **POST** /auth/register | Register a new user account
[**AuthAPI_forgotPassword**](AuthAPI.md#AuthAPI_forgotPassword) | **POST** /auth/forgot-password | Send a password reset email to the user
[**AuthAPI_login**](AuthAPI.md#AuthAPI_login) | **POST** /auth/login | Authenticate a user with email + password (optional TOTP)
[**AuthAPI_logout**](AuthAPI.md#AuthAPI_logout) | **POST** /auth/logout | Log out the current user (kills the assay session)
[**AuthAPI_magicLinkLogin**](AuthAPI.md#AuthAPI_magicLinkLogin) | **POST** /auth/magic-link | Request a magic link login (sends an email with a one-time link)
[**AuthAPI_magicLinkVerify**](AuthAPI.md#AuthAPI_magicLinkVerify) | **POST** /auth/magic-link/verify | Verify a magic link token and log the user in
[**AuthAPI_resetPassword**](AuthAPI.md#AuthAPI_resetPassword) | **POST** /auth/reset-password | Reset the user&#39;s password using a reset token
[**AuthAPI_totpEnable**](AuthAPI.md#AuthAPI_totpEnable) | **POST** /auth/totp/enable | Enable TOTP two-factor authentication by verifying a code
[**AuthAPI_totpSetup**](AuthAPI.md#AuthAPI_totpSetup) | **GET** /auth/totp/setup | Set up TOTP two-factor authentication (generates secret + backup codes)
[**AuthAPI_verifyEmail**](AuthAPI.md#AuthAPI_verifyEmail) | **POST** /auth/verify-email | Verify a user&#39;s email address using a verification token


# **AuthAPI_acceptInvite**
```c
// Accept an invite: create the account (or reuse an existing one) and join the inviting tenant. The invite token proves control of the mailbox.
//
void AuthAPI_acceptInvite(apiClient_t *apiClient, accept_invite_request_t *accept_invite_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**accept_invite_request** | **[accept_invite_request_t](accept_invite_request.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthAPI_callRegister**
```c
// Register a new user account
//
auth_response_t* AuthAPI_callRegister(apiClient_t *apiClient, register_request_t *register_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**register_request** | **[register_request_t](register_request.md) \*** |  | 

### Return type

[auth_response_t](auth_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthAPI_forgotPassword**
```c
// Send a password reset email to the user
//
void AuthAPI_forgotPassword(apiClient_t *apiClient, forgot_password_request_t *forgot_password_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**forgot_password_request** | **[forgot_password_request_t](forgot_password_request.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthAPI_login**
```c
// Authenticate a user with email + password (optional TOTP)
//
auth_response_t* AuthAPI_login(apiClient_t *apiClient, login_request_t *login_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**login_request** | **[login_request_t](login_request.md) \*** |  | 

### Return type

[auth_response_t](auth_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthAPI_logout**
```c
// Log out the current user (kills the assay session)
//
void AuthAPI_logout(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthAPI_magicLinkLogin**
```c
// Request a magic link login (sends an email with a one-time link)
//
void AuthAPI_magicLinkLogin(apiClient_t *apiClient, magic_link_request_t *magic_link_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**magic_link_request** | **[magic_link_request_t](magic_link_request.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthAPI_magicLinkVerify**
```c
// Verify a magic link token and log the user in
//
auth_response_t* AuthAPI_magicLinkVerify(apiClient_t *apiClient, magic_link_verify_request_t *magic_link_verify_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**magic_link_verify_request** | **[magic_link_verify_request_t](magic_link_verify_request.md) \*** |  | 

### Return type

[auth_response_t](auth_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthAPI_resetPassword**
```c
// Reset the user's password using a reset token
//
void AuthAPI_resetPassword(apiClient_t *apiClient, reset_password_request_t *reset_password_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**reset_password_request** | **[reset_password_request_t](reset_password_request.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthAPI_totpEnable**
```c
// Enable TOTP two-factor authentication by verifying a code
//
void AuthAPI_totpEnable(apiClient_t *apiClient, totp_enable_request_t *totp_enable_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**totp_enable_request** | **[totp_enable_request_t](totp_enable_request.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthAPI_totpSetup**
```c
// Set up TOTP two-factor authentication (generates secret + backup codes)
//
totp_setup_response_t* AuthAPI_totpSetup(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[totp_setup_response_t](totp_setup_response.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthAPI_verifyEmail**
```c
// Verify a user's email address using a verification token
//
void AuthAPI_verifyEmail(apiClient_t *apiClient, verify_email_request_t *verify_email_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**verify_email_request** | **[verify_email_request_t](verify_email_request.md) \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

