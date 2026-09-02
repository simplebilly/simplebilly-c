#ifndef recurring_template_update_TEST
#define recurring_template_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define recurring_template_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/recurring_template_update.h"
recurring_template_update_t* instantiate_recurring_template_update(int include_optional);



recurring_template_update_t* instantiate_recurring_template_update(int include_optional) {
  recurring_template_update_t* recurring_template_update = NULL;
  if (include_optional) {
    recurring_template_update = recurring_template_update_create(
      "2013-10-20",
      "0",
      ACTIVE,
      1,
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20",
      invoice,
      null
    );
  } else {
    recurring_template_update = recurring_template_update_create(
      "2013-10-20",
      "0",
      ACTIVE,
      1,
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20",
      invoice,
      null
    );
  }

  return recurring_template_update;
}


#ifdef recurring_template_update_MAIN

void test_recurring_template_update(int include_optional) {
    recurring_template_update_t* recurring_template_update_1 = instantiate_recurring_template_update(include_optional);

	cJSON* jsonrecurring_template_update_1 = recurring_template_update_convertToJSON(recurring_template_update_1);
	printf("recurring_template_update :\n%s\n", cJSON_Print(jsonrecurring_template_update_1));
	recurring_template_update_t* recurring_template_update_2 = recurring_template_update_parseFromJSON(jsonrecurring_template_update_1);
	cJSON* jsonrecurring_template_update_2 = recurring_template_update_convertToJSON(recurring_template_update_2);
	printf("repeating recurring_template_update:\n%s\n", cJSON_Print(jsonrecurring_template_update_2));
}

int main() {
  test_recurring_template_update(1);
  test_recurring_template_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // recurring_template_update_MAIN
#endif // recurring_template_update_TEST
