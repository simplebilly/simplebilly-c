#ifndef budget_TEST
#define budget_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define budget_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/budget.h"
budget_t* instantiate_budget(int include_optional);



budget_t* instantiate_budget(int include_optional) {
  budget_t* budget = NULL;
  if (include_optional) {
    budget = budget_create(
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      56
    );
  } else {
    budget = budget_create(
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      56
    );
  }

  return budget;
}


#ifdef budget_MAIN

void test_budget(int include_optional) {
    budget_t* budget_1 = instantiate_budget(include_optional);

	cJSON* jsonbudget_1 = budget_convertToJSON(budget_1);
	printf("budget :\n%s\n", cJSON_Print(jsonbudget_1));
	budget_t* budget_2 = budget_parseFromJSON(jsonbudget_1);
	cJSON* jsonbudget_2 = budget_convertToJSON(budget_2);
	printf("repeating budget:\n%s\n", cJSON_Print(jsonbudget_2));
}

int main() {
  test_budget(1);
  test_budget(0);

  printf("Hello world \n");
  return 0;
}

#endif // budget_MAIN
#endif // budget_TEST
