#ifndef activity_type_TEST
#define activity_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_type.h"
activity_type_t* instantiate_activity_type(int include_optional);



activity_type_t* instantiate_activity_type(int include_optional) {
  activity_type_t* activity_type = NULL;
  if (include_optional) {
    activity_type = activity_type_create(
    );
  } else {
    activity_type = activity_type_create(
    );
  }

  return activity_type;
}


#ifdef activity_type_MAIN

void test_activity_type(int include_optional) {
    activity_type_t* activity_type_1 = instantiate_activity_type(include_optional);

	cJSON* jsonactivity_type_1 = activity_type_convertToJSON(activity_type_1);
	printf("activity_type :\n%s\n", cJSON_Print(jsonactivity_type_1));
	activity_type_t* activity_type_2 = activity_type_parseFromJSON(jsonactivity_type_1);
	cJSON* jsonactivity_type_2 = activity_type_convertToJSON(activity_type_2);
	printf("repeating activity_type:\n%s\n", cJSON_Print(jsonactivity_type_2));
}

int main() {
  test_activity_type(1);
  test_activity_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_type_MAIN
#endif // activity_type_TEST
