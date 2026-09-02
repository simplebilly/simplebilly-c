#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/coupon.h"
#include "../model/coupon_create.h"
#include "../model/coupon_update.h"
#include "../model/plugin_error.h"


coupon_t*
CouponAPI_couponRestore(apiClient_t *apiClient, char *coupon_id);


coupon_t*
CouponAPI_createCoupon(apiClient_t *apiClient, coupon_create_t *coupon_create);


void
CouponAPI_deleteCoupon(apiClient_t *apiClient, char *coupon_id);


coupon_t*
CouponAPI_getCoupon(apiClient_t *apiClient, char *coupon_id);


list_t*
CouponAPI_listCoupons(apiClient_t *apiClient, int *page, int *page_size, int *is_active, char *code, char *discount_type);


coupon_t*
CouponAPI_updateCoupon(apiClient_t *apiClient, char *coupon_id, coupon_update_t *coupon_update);


