#ifndef activity_create_TEST
#define activity_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_create.h"
activity_create_t* instantiate_activity_create(int include_optional);



activity_create_t* instantiate_activity_create(int include_optional) {
  activity_create_t* activity_create = NULL;
  if (include_optional) {
    activity_create = activity_create_create(
      call,
      "0",
      "0",
      "0",
      "2013-10-20",
      "2013-10-20",
      open,
      "0"
    );
  } else {
    activity_create = activity_create_create(
      call,
      "0",
      "0",
      "0",
      "2013-10-20",
      "2013-10-20",
      open,
      "0"
    );
  }

  return activity_create;
}


#ifdef activity_create_MAIN

void test_activity_create(int include_optional) {
    activity_create_t* activity_create_1 = instantiate_activity_create(include_optional);

	cJSON* jsonactivity_create_1 = activity_create_convertToJSON(activity_create_1);
	printf("activity_create :\n%s\n", cJSON_Print(jsonactivity_create_1));
	activity_create_t* activity_create_2 = activity_create_parseFromJSON(jsonactivity_create_1);
	cJSON* jsonactivity_create_2 = activity_create_convertToJSON(activity_create_2);
	printf("repeating activity_create:\n%s\n", cJSON_Print(jsonactivity_create_2));
}

int main() {
  test_activity_create(1);
  test_activity_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_create_MAIN
#endif // activity_create_TEST
