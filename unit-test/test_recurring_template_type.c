#ifndef recurring_template_type_TEST
#define recurring_template_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define recurring_template_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/recurring_template_type.h"
recurring_template_type_t* instantiate_recurring_template_type(int include_optional);



recurring_template_type_t* instantiate_recurring_template_type(int include_optional) {
  recurring_template_type_t* recurring_template_type = NULL;
  if (include_optional) {
    recurring_template_type = recurring_template_type_create(
    );
  } else {
    recurring_template_type = recurring_template_type_create(
    );
  }

  return recurring_template_type;
}


#ifdef recurring_template_type_MAIN

void test_recurring_template_type(int include_optional) {
    recurring_template_type_t* recurring_template_type_1 = instantiate_recurring_template_type(include_optional);

	cJSON* jsonrecurring_template_type_1 = recurring_template_type_convertToJSON(recurring_template_type_1);
	printf("recurring_template_type :\n%s\n", cJSON_Print(jsonrecurring_template_type_1));
	recurring_template_type_t* recurring_template_type_2 = recurring_template_type_parseFromJSON(jsonrecurring_template_type_1);
	cJSON* jsonrecurring_template_type_2 = recurring_template_type_convertToJSON(recurring_template_type_2);
	printf("repeating recurring_template_type:\n%s\n", cJSON_Print(jsonrecurring_template_type_2));
}

int main() {
  test_recurring_template_type(1);
  test_recurring_template_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // recurring_template_type_MAIN
#endif // recurring_template_type_TEST
