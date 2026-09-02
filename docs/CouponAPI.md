# CouponAPI

All URIs are relative to *https://demo.simplebilly.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**CouponAPI_couponRestore**](CouponAPI.md#CouponAPI_couponRestore) | **POST** /api/v1/coupons/{coupon_id}/restore | 
[**CouponAPI_createCoupon**](CouponAPI.md#CouponAPI_createCoupon) | **POST** /api/v1/coupons | 
[**CouponAPI_deleteCoupon**](CouponAPI.md#CouponAPI_deleteCoupon) | **DELETE** /api/v1/coupons/{coupon_id} | 
[**CouponAPI_getCoupon**](CouponAPI.md#CouponAPI_getCoupon) | **GET** /api/v1/coupons/{coupon_id} | 
[**CouponAPI_listCoupons**](CouponAPI.md#CouponAPI_listCoupons) | **GET** /api/v1/coupons/ | 
[**CouponAPI_updateCoupon**](CouponAPI.md#CouponAPI_updateCoupon) | **PUT** /api/v1/coupons/{coupon_id} | 


# **CouponAPI_couponRestore**
```c
coupon_t* CouponAPI_couponRestore(apiClient_t *apiClient, char *coupon_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**coupon_id** | **char \*** |  | 

### Return type

[coupon_t](coupon.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CouponAPI_createCoupon**
```c
coupon_t* CouponAPI_createCoupon(apiClient_t *apiClient, coupon_create_t *coupon_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**coupon_create** | **[coupon_create_t](coupon_create.md) \*** |  | 

### Return type

[coupon_t](coupon.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CouponAPI_deleteCoupon**
```c
void CouponAPI_deleteCoupon(apiClient_t *apiClient, char *coupon_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**coupon_id** | **char \*** |  | 

### Return type

void

### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CouponAPI_getCoupon**
```c
coupon_t* CouponAPI_getCoupon(apiClient_t *apiClient, char *coupon_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**coupon_id** | **char \*** |  | 

### Return type

[coupon_t](coupon.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CouponAPI_listCoupons**
```c
list_t* CouponAPI_listCoupons(apiClient_t *apiClient, int *page, int *page_size, int *is_active, char *code, char *discount_type);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page** | **int \*** |  | [optional] 
**page_size** | **int \*** |  | [optional] 
**is_active** | **int \*** |  | [optional] 
**code** | **char \*** |  | [optional] 
**discount_type** | **char \*** |  | [optional] 

### Return type

[list_t](coupon.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CouponAPI_updateCoupon**
```c
coupon_t* CouponAPI_updateCoupon(apiClient_t *apiClient, char *coupon_id, coupon_update_t *coupon_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**coupon_id** | **char \*** |  | 
**coupon_update** | **[coupon_update_t](coupon_update.md) \*** |  | 

### Return type

[coupon_t](coupon.md) *


### Authorization

[bearer_token](../README.md#bearer_token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

