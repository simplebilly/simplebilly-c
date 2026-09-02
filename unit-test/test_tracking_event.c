#ifndef tracking_event_TEST
#define tracking_event_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tracking_event_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tracking_event.h"
tracking_event_t* instantiate_tracking_event(int include_optional);



tracking_event_t* instantiate_tracking_event(int include_optional) {
  tracking_event_t* tracking_event = NULL;
  if (include_optional) {
    tracking_event = tracking_event_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    tracking_event = tracking_event_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return tracking_event;
}


#ifdef tracking_event_MAIN

void test_tracking_event(int include_optional) {
    tracking_event_t* tracking_event_1 = instantiate_tracking_event(include_optional);

	cJSON* jsontracking_event_1 = tracking_event_convertToJSON(tracking_event_1);
	printf("tracking_event :\n%s\n", cJSON_Print(jsontracking_event_1));
	tracking_event_t* tracking_event_2 = tracking_event_parseFromJSON(jsontracking_event_1);
	cJSON* jsontracking_event_2 = tracking_event_convertToJSON(tracking_event_2);
	printf("repeating tracking_event:\n%s\n", cJSON_Print(jsontracking_event_2));
}

int main() {
  test_tracking_event(1);
  test_tracking_event(0);

  printf("Hello world \n");
  return 0;
}

#endif // tracking_event_MAIN
#endif // tracking_event_TEST
