#ifndef recurring_template_create_TEST
#define recurring_template_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define recurring_template_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/recurring_template_create.h"
recurring_template_create_t* instantiate_recurring_template_create(int include_optional);



recurring_template_create_t* instantiate_recurring_template_create(int include_optional) {
  recurring_template_create_t* recurring_template_create = NULL;
  if (include_optional) {
    recurring_template_create = recurring_template_create_create(
      "2013-10-20",
      "0",
      simplebilly_api_recurring_template_create__ACTIVE,
      1,
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20",
      simplebilly_api_recurring_template_create__invoice,
      null
    );
  } else {
    recurring_template_create = recurring_template_create_create(
      "2013-10-20",
      "0",
      simplebilly_api_recurring_template_create__ACTIVE,
      1,
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20",
      simplebilly_api_recurring_template_create__invoice,
      null
    );
  }

  return recurring_template_create;
}


#ifdef recurring_template_create_MAIN

void test_recurring_template_create(int include_optional) {
    recurring_template_create_t* recurring_template_create_1 = instantiate_recurring_template_create(include_optional);

	cJSON* jsonrecurring_template_create_1 = recurring_template_create_convertToJSON(recurring_template_create_1);
	printf("recurring_template_create :\n%s\n", cJSON_Print(jsonrecurring_template_create_1));
	recurring_template_create_t* recurring_template_create_2 = recurring_template_create_parseFromJSON(jsonrecurring_template_create_1);
	cJSON* jsonrecurring_template_create_2 = recurring_template_create_convertToJSON(recurring_template_create_2);
	printf("repeating recurring_template_create:\n%s\n", cJSON_Print(jsonrecurring_template_create_2));
}

int main() {
  test_recurring_template_create(1);
  test_recurring_template_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // recurring_template_create_MAIN
#endif // recurring_template_create_TEST
