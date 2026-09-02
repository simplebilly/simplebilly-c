#ifndef recurring_template_TEST
#define recurring_template_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define recurring_template_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/recurring_template.h"
recurring_template_t* instantiate_recurring_template(int include_optional);



recurring_template_t* instantiate_recurring_template(int include_optional) {
  recurring_template_t* recurring_template = NULL;
  if (include_optional) {
    recurring_template = recurring_template_create(
      "0",
      "0",
      "2013-10-20",
      "0",
      "0",
      1,
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20",
      "0",
      "0",
      "0",
      null
    );
  } else {
    recurring_template = recurring_template_create(
      "0",
      "0",
      "2013-10-20",
      "0",
      "0",
      1,
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20",
      "0",
      "0",
      "0",
      null
    );
  }

  return recurring_template;
}


#ifdef recurring_template_MAIN

void test_recurring_template(int include_optional) {
    recurring_template_t* recurring_template_1 = instantiate_recurring_template(include_optional);

	cJSON* jsonrecurring_template_1 = recurring_template_convertToJSON(recurring_template_1);
	printf("recurring_template :\n%s\n", cJSON_Print(jsonrecurring_template_1));
	recurring_template_t* recurring_template_2 = recurring_template_parseFromJSON(jsonrecurring_template_1);
	cJSON* jsonrecurring_template_2 = recurring_template_convertToJSON(recurring_template_2);
	printf("repeating recurring_template:\n%s\n", cJSON_Print(jsonrecurring_template_2));
}

int main() {
  test_recurring_template(1);
  test_recurring_template(0);

  printf("Hello world \n");
  return 0;
}

#endif // recurring_template_MAIN
#endif // recurring_template_TEST
