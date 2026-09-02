#ifndef webhook_event_status_TEST
#define webhook_event_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define webhook_event_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/webhook_event_status.h"
webhook_event_status_t* instantiate_webhook_event_status(int include_optional);



webhook_event_status_t* instantiate_webhook_event_status(int include_optional) {
  webhook_event_status_t* webhook_event_status = NULL;
  if (include_optional) {
    webhook_event_status = webhook_event_status_create(
    );
  } else {
    webhook_event_status = webhook_event_status_create(
    );
  }

  return webhook_event_status;
}


#ifdef webhook_event_status_MAIN

void test_webhook_event_status(int include_optional) {
    webhook_event_status_t* webhook_event_status_1 = instantiate_webhook_event_status(include_optional);

	cJSON* jsonwebhook_event_status_1 = webhook_event_status_convertToJSON(webhook_event_status_1);
	printf("webhook_event_status :\n%s\n", cJSON_Print(jsonwebhook_event_status_1));
	webhook_event_status_t* webhook_event_status_2 = webhook_event_status_parseFromJSON(jsonwebhook_event_status_1);
	cJSON* jsonwebhook_event_status_2 = webhook_event_status_convertToJSON(webhook_event_status_2);
	printf("repeating webhook_event_status:\n%s\n", cJSON_Print(jsonwebhook_event_status_2));
}

int main() {
  test_webhook_event_status(1);
  test_webhook_event_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // webhook_event_status_MAIN
#endif // webhook_event_status_TEST
