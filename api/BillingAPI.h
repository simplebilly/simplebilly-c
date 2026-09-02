#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_response_subscription_overview.h"
#include "../model/api_response_vec_plan.h"
#include "../model/quota_override.h"


// All canonical plans (free/starter/business/enterprise) — the single source of truth lives in `crate::saasy::plans`, matching marketing.
//
api_response_vec_plan_t*
BillingAPI_getPlans(apiClient_t *apiClient);


// Effective limits + current usage for the calling tenant.
//
void
BillingAPI_getQuotaApi(apiClient_t *apiClient);


api_response_subscription_overview_t*
BillingAPI_getSubscriptionApi(apiClient_t *apiClient);


void
BillingAPI_getUsageApi(apiClient_t *apiClient, char *meter);


// Paddle Billing subscription webhook. Verifies the `Paddle-Signature` header (HMAC-SHA256 over `\"{ts}:{raw_body}\"` with the webhook secret), then updates `billing_info` and `tenants.plan` for the tenant identified by the subscription `custom_data` (JSON `{\"tenant_id\": \"...\"}` or a bare tenant UUID).
//
void
BillingAPI_paddleSubscriptionWebhook(apiClient_t *apiClient);


// Write the per-tenant quota override (`admin:settings`). An empty object clears the override.
//
void
BillingAPI_putQuotaApi(apiClient_t *apiClient, quota_override_t *quota_override);


