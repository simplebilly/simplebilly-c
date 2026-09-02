#ifndef timeline_event_TEST
#define timeline_event_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define timeline_event_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/timeline_event.h"
timeline_event_t* instantiate_timeline_event(int include_optional);



timeline_event_t* instantiate_timeline_event(int include_optional) {
  timeline_event_t* timeline_event = NULL;
  if (include_optional) {
    timeline_event = timeline_event_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    timeline_event = timeline_event_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return timeline_event;
}


#ifdef timeline_event_MAIN

void test_timeline_event(int include_optional) {
    timeline_event_t* timeline_event_1 = instantiate_timeline_event(include_optional);

	cJSON* jsontimeline_event_1 = timeline_event_convertToJSON(timeline_event_1);
	printf("timeline_event :\n%s\n", cJSON_Print(jsontimeline_event_1));
	timeline_event_t* timeline_event_2 = timeline_event_parseFromJSON(jsontimeline_event_1);
	cJSON* jsontimeline_event_2 = timeline_event_convertToJSON(timeline_event_2);
	printf("repeating timeline_event:\n%s\n", cJSON_Print(jsontimeline_event_2));
}

int main() {
  test_timeline_event(1);
  test_timeline_event(0);

  printf("Hello world \n");
  return 0;
}

#endif // timeline_event_MAIN
#endif // timeline_event_TEST
