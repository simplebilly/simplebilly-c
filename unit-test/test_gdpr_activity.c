#ifndef gdpr_activity_TEST
#define gdpr_activity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gdpr_activity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gdpr_activity.h"
gdpr_activity_t* instantiate_gdpr_activity(int include_optional);



gdpr_activity_t* instantiate_gdpr_activity(int include_optional) {
  gdpr_activity_t* gdpr_activity = NULL;
  if (include_optional) {
    gdpr_activity = gdpr_activity_create(
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0"
    );
  } else {
    gdpr_activity = gdpr_activity_create(
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0"
    );
  }

  return gdpr_activity;
}


#ifdef gdpr_activity_MAIN

void test_gdpr_activity(int include_optional) {
    gdpr_activity_t* gdpr_activity_1 = instantiate_gdpr_activity(include_optional);

	cJSON* jsongdpr_activity_1 = gdpr_activity_convertToJSON(gdpr_activity_1);
	printf("gdpr_activity :\n%s\n", cJSON_Print(jsongdpr_activity_1));
	gdpr_activity_t* gdpr_activity_2 = gdpr_activity_parseFromJSON(jsongdpr_activity_1);
	cJSON* jsongdpr_activity_2 = gdpr_activity_convertToJSON(gdpr_activity_2);
	printf("repeating gdpr_activity:\n%s\n", cJSON_Print(jsongdpr_activity_2));
}

int main() {
  test_gdpr_activity(1);
  test_gdpr_activity(0);

  printf("Hello world \n");
  return 0;
}

#endif // gdpr_activity_MAIN
#endif // gdpr_activity_TEST
