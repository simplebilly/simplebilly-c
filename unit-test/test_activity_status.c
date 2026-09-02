#ifndef activity_status_TEST
#define activity_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_status.h"
activity_status_t* instantiate_activity_status(int include_optional);



activity_status_t* instantiate_activity_status(int include_optional) {
  activity_status_t* activity_status = NULL;
  if (include_optional) {
    activity_status = activity_status_create(
    );
  } else {
    activity_status = activity_status_create(
    );
  }

  return activity_status;
}


#ifdef activity_status_MAIN

void test_activity_status(int include_optional) {
    activity_status_t* activity_status_1 = instantiate_activity_status(include_optional);

	cJSON* jsonactivity_status_1 = activity_status_convertToJSON(activity_status_1);
	printf("activity_status :\n%s\n", cJSON_Print(jsonactivity_status_1));
	activity_status_t* activity_status_2 = activity_status_parseFromJSON(jsonactivity_status_1);
	cJSON* jsonactivity_status_2 = activity_status_convertToJSON(activity_status_2);
	printf("repeating activity_status:\n%s\n", cJSON_Print(jsonactivity_status_2));
}

int main() {
  test_activity_status(1);
  test_activity_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_status_MAIN
#endif // activity_status_TEST
