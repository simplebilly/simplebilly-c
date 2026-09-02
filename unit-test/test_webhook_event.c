#ifndef webhook_event_TEST
#define webhook_event_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define webhook_event_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/webhook_event.h"
webhook_event_t* instantiate_webhook_event(int include_optional);



webhook_event_t* instantiate_webhook_event(int include_optional) {
  webhook_event_t* webhook_event = NULL;
  if (include_optional) {
    webhook_event = webhook_event_create(
      56,
      "0",
      inbound,
      "0",
      "0",
      null,
      accepted
    );
  } else {
    webhook_event = webhook_event_create(
      56,
      "0",
      inbound,
      "0",
      "0",
      null,
      accepted
    );
  }

  return webhook_event;
}


#ifdef webhook_event_MAIN

void test_webhook_event(int include_optional) {
    webhook_event_t* webhook_event_1 = instantiate_webhook_event(include_optional);

	cJSON* jsonwebhook_event_1 = webhook_event_convertToJSON(webhook_event_1);
	printf("webhook_event :\n%s\n", cJSON_Print(jsonwebhook_event_1));
	webhook_event_t* webhook_event_2 = webhook_event_parseFromJSON(jsonwebhook_event_1);
	cJSON* jsonwebhook_event_2 = webhook_event_convertToJSON(webhook_event_2);
	printf("repeating webhook_event:\n%s\n", cJSON_Print(jsonwebhook_event_2));
}

int main() {
  test_webhook_event(1);
  test_webhook_event(0);

  printf("Hello world \n");
  return 0;
}

#endif // webhook_event_MAIN
#endif // webhook_event_TEST
