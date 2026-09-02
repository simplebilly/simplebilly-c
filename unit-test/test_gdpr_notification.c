#ifndef gdpr_notification_TEST
#define gdpr_notification_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gdpr_notification_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gdpr_notification.h"
gdpr_notification_t* instantiate_gdpr_notification(int include_optional);



gdpr_notification_t* instantiate_gdpr_notification(int include_optional) {
  gdpr_notification_t* gdpr_notification = NULL;
  if (include_optional) {
    gdpr_notification = gdpr_notification_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      1,
      "0",
      "0",
      "0"
    );
  } else {
    gdpr_notification = gdpr_notification_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      1,
      "0",
      "0",
      "0"
    );
  }

  return gdpr_notification;
}


#ifdef gdpr_notification_MAIN

void test_gdpr_notification(int include_optional) {
    gdpr_notification_t* gdpr_notification_1 = instantiate_gdpr_notification(include_optional);

	cJSON* jsongdpr_notification_1 = gdpr_notification_convertToJSON(gdpr_notification_1);
	printf("gdpr_notification :\n%s\n", cJSON_Print(jsongdpr_notification_1));
	gdpr_notification_t* gdpr_notification_2 = gdpr_notification_parseFromJSON(jsongdpr_notification_1);
	cJSON* jsongdpr_notification_2 = gdpr_notification_convertToJSON(gdpr_notification_2);
	printf("repeating gdpr_notification:\n%s\n", cJSON_Print(jsongdpr_notification_2));
}

int main() {
  test_gdpr_notification(1);
  test_gdpr_notification(0);

  printf("Hello world \n");
  return 0;
}

#endif // gdpr_notification_MAIN
#endif // gdpr_notification_TEST
