#ifndef webhook_subscription_TEST
#define webhook_subscription_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define webhook_subscription_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/webhook_subscription.h"
webhook_subscription_t* instantiate_webhook_subscription(int include_optional);



webhook_subscription_t* instantiate_webhook_subscription(int include_optional) {
  webhook_subscription_t* webhook_subscription = NULL;
  if (include_optional) {
    webhook_subscription = webhook_subscription_create(
      "0",
      1,
      "0",
      "0",
      "0"
    );
  } else {
    webhook_subscription = webhook_subscription_create(
      "0",
      1,
      "0",
      "0",
      "0"
    );
  }

  return webhook_subscription;
}


#ifdef webhook_subscription_MAIN

void test_webhook_subscription(int include_optional) {
    webhook_subscription_t* webhook_subscription_1 = instantiate_webhook_subscription(include_optional);

	cJSON* jsonwebhook_subscription_1 = webhook_subscription_convertToJSON(webhook_subscription_1);
	printf("webhook_subscription :\n%s\n", cJSON_Print(jsonwebhook_subscription_1));
	webhook_subscription_t* webhook_subscription_2 = webhook_subscription_parseFromJSON(jsonwebhook_subscription_1);
	cJSON* jsonwebhook_subscription_2 = webhook_subscription_convertToJSON(webhook_subscription_2);
	printf("repeating webhook_subscription:\n%s\n", cJSON_Print(jsonwebhook_subscription_2));
}

int main() {
  test_webhook_subscription(1);
  test_webhook_subscription(0);

  printf("Hello world \n");
  return 0;
}

#endif // webhook_subscription_MAIN
#endif // webhook_subscription_TEST
