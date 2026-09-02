/*
 * subscription_overview.h
 *
 * Tenant subscription overview for the billing page: current plan, status, period end, trial state, effective limits, current usage and feature flags. Backed by Paddle Billing webhook data written into &#x60;billing_info&#x60; + &#x60;tenants.plan&#x60;, and by the canonical plans in &#x60;crate::saasy::plans&#x60;.  JSON contract (camelCase, matches the frontend): &#x60;plan&#x60;, &#x60;planName&#x60;, &#x60;priceEur&#x60;, &#x60;status&#x60;, &#x60;currentPeriodEnd&#x60;, &#x60;manageUrl&#x60;, &#x60;trialEndsAt&#x60;, &#x60;isTrialing&#x60;, &#x60;limits:{maxUsers,maxInvoicesPerMonth,maxConnectors}&#x60;, &#x60;usage:{users,invoicesThisMonth,connectors,overageSeats}&#x60;, &#x60;features:{taxAutomations,fancyReports,erp}&#x60;.
 */

#ifndef _subscription_overview_H_
#define _subscription_overview_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct subscription_overview_t subscription_overview_t;

#include "plan_features.h"
#include "plan_limits.h"
#include "usage_snapshot.h"



typedef struct subscription_overview_t {
    char *current_period_end; //date time
    struct plan_features_t *features; //model
    int *is_trialing; //boolean
    struct plan_limits_t *limits; //model
    char *manage_url; // string
    char *plan; // string
    char *plan_name; // string
    double *price_eur; //numeric
    int *quantity; //numeric
    char *status; // string
    char *subscription_id; // string
    char *trial_ends_at; //date time
    struct usage_snapshot_t *usage; //model

    int _library_owned; // Is the library responsible for freeing this object?
} subscription_overview_t;

__attribute__((deprecated)) subscription_overview_t *subscription_overview_create(
    char *current_period_end,
    plan_features_t *features,
    int *is_trialing,
    plan_limits_t *limits,
    char *manage_url,
    char *plan,
    char *plan_name,
    double *price_eur,
    int *quantity,
    char *status,
    char *subscription_id,
    char *trial_ends_at,
    usage_snapshot_t *usage
);

void subscription_overview_free(subscription_overview_t *subscription_overview);

subscription_overview_t *subscription_overview_parseFromJSON(cJSON *subscription_overviewJSON);

cJSON *subscription_overview_convertToJSON(subscription_overview_t *subscription_overview);

#endif /* _subscription_overview_H_ */

