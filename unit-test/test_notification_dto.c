#ifndef notification_dto_TEST
#define notification_dto_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define notification_dto_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/notification_dto.h"
notification_dto_t* instantiate_notification_dto(int include_optional);



notification_dto_t* instantiate_notification_dto(int include_optional) {
  notification_dto_t* notification_dto = NULL;
  if (include_optional) {
    notification_dto = notification_dto_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      1,
      "0",
      1,
      "0",
      "0",
      "0"
    );
  } else {
    notification_dto = notification_dto_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      1,
      "0",
      1,
      "0",
      "0",
      "0"
    );
  }

  return notification_dto;
}


#ifdef notification_dto_MAIN

void test_notification_dto(int include_optional) {
    notification_dto_t* notification_dto_1 = instantiate_notification_dto(include_optional);

	cJSON* jsonnotification_dto_1 = notification_dto_convertToJSON(notification_dto_1);
	printf("notification_dto :\n%s\n", cJSON_Print(jsonnotification_dto_1));
	notification_dto_t* notification_dto_2 = notification_dto_parseFromJSON(jsonnotification_dto_1);
	cJSON* jsonnotification_dto_2 = notification_dto_convertToJSON(notification_dto_2);
	printf("repeating notification_dto:\n%s\n", cJSON_Print(jsonnotification_dto_2));
}

int main() {
  test_notification_dto(1);
  test_notification_dto(0);

  printf("Hello world \n");
  return 0;
}

#endif // notification_dto_MAIN
#endif // notification_dto_TEST
