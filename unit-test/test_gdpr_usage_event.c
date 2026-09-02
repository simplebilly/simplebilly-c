#ifndef gdpr_usage_event_TEST
#define gdpr_usage_event_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gdpr_usage_event_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gdpr_usage_event.h"
gdpr_usage_event_t* instantiate_gdpr_usage_event(int include_optional);



gdpr_usage_event_t* instantiate_gdpr_usage_event(int include_optional) {
  gdpr_usage_event_t* gdpr_usage_event = NULL;
  if (include_optional) {
    gdpr_usage_event = gdpr_usage_event_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      56,
      "0"
    );
  } else {
    gdpr_usage_event = gdpr_usage_event_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      56,
      "0"
    );
  }

  return gdpr_usage_event;
}


#ifdef gdpr_usage_event_MAIN

void test_gdpr_usage_event(int include_optional) {
    gdpr_usage_event_t* gdpr_usage_event_1 = instantiate_gdpr_usage_event(include_optional);

	cJSON* jsongdpr_usage_event_1 = gdpr_usage_event_convertToJSON(gdpr_usage_event_1);
	printf("gdpr_usage_event :\n%s\n", cJSON_Print(jsongdpr_usage_event_1));
	gdpr_usage_event_t* gdpr_usage_event_2 = gdpr_usage_event_parseFromJSON(jsongdpr_usage_event_1);
	cJSON* jsongdpr_usage_event_2 = gdpr_usage_event_convertToJSON(gdpr_usage_event_2);
	printf("repeating gdpr_usage_event:\n%s\n", cJSON_Print(jsongdpr_usage_event_2));
}

int main() {
  test_gdpr_usage_event(1);
  test_gdpr_usage_event(0);

  printf("Hello world \n");
  return 0;
}

#endif // gdpr_usage_event_MAIN
#endif // gdpr_usage_event_TEST
