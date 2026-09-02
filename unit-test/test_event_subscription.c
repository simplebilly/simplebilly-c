#ifndef event_subscription_TEST
#define event_subscription_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define event_subscription_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/event_subscription.h"
event_subscription_t* instantiate_event_subscription(int include_optional);



event_subscription_t* instantiate_event_subscription(int include_optional) {
  event_subscription_t* event_subscription = NULL;
  if (include_optional) {
    event_subscription = event_subscription_create(
      "0",
      "0",
      1,
      "0"
    );
  } else {
    event_subscription = event_subscription_create(
      "0",
      "0",
      1,
      "0"
    );
  }

  return event_subscription;
}


#ifdef event_subscription_MAIN

void test_event_subscription(int include_optional) {
    event_subscription_t* event_subscription_1 = instantiate_event_subscription(include_optional);

	cJSON* jsonevent_subscription_1 = event_subscription_convertToJSON(event_subscription_1);
	printf("event_subscription :\n%s\n", cJSON_Print(jsonevent_subscription_1));
	event_subscription_t* event_subscription_2 = event_subscription_parseFromJSON(jsonevent_subscription_1);
	cJSON* jsonevent_subscription_2 = event_subscription_convertToJSON(event_subscription_2);
	printf("repeating event_subscription:\n%s\n", cJSON_Print(jsonevent_subscription_2));
}

int main() {
  test_event_subscription(1);
  test_event_subscription(0);

  printf("Hello world \n");
  return 0;
}

#endif // event_subscription_MAIN
#endif // event_subscription_TEST
