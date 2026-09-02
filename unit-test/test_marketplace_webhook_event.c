#ifndef marketplace_webhook_event_TEST
#define marketplace_webhook_event_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define marketplace_webhook_event_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/marketplace_webhook_event.h"
marketplace_webhook_event_t* instantiate_marketplace_webhook_event(int include_optional);



marketplace_webhook_event_t* instantiate_marketplace_webhook_event(int include_optional) {
  marketplace_webhook_event_t* marketplace_webhook_event = NULL;
  if (include_optional) {
    marketplace_webhook_event = marketplace_webhook_event_create(
      "0",
      null,
      "0",
      null,
      "0",
      1,
      "0"
    );
  } else {
    marketplace_webhook_event = marketplace_webhook_event_create(
      "0",
      null,
      "0",
      null,
      "0",
      1,
      "0"
    );
  }

  return marketplace_webhook_event;
}


#ifdef marketplace_webhook_event_MAIN

void test_marketplace_webhook_event(int include_optional) {
    marketplace_webhook_event_t* marketplace_webhook_event_1 = instantiate_marketplace_webhook_event(include_optional);

	cJSON* jsonmarketplace_webhook_event_1 = marketplace_webhook_event_convertToJSON(marketplace_webhook_event_1);
	printf("marketplace_webhook_event :\n%s\n", cJSON_Print(jsonmarketplace_webhook_event_1));
	marketplace_webhook_event_t* marketplace_webhook_event_2 = marketplace_webhook_event_parseFromJSON(jsonmarketplace_webhook_event_1);
	cJSON* jsonmarketplace_webhook_event_2 = marketplace_webhook_event_convertToJSON(marketplace_webhook_event_2);
	printf("repeating marketplace_webhook_event:\n%s\n", cJSON_Print(jsonmarketplace_webhook_event_2));
}

int main() {
  test_marketplace_webhook_event(1);
  test_marketplace_webhook_event(0);

  printf("Hello world \n");
  return 0;
}

#endif // marketplace_webhook_event_MAIN
#endif // marketplace_webhook_event_TEST
