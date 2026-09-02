#ifndef budget_goal_request_TEST
#define budget_goal_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define budget_goal_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/budget_goal_request.h"
budget_goal_request_t* instantiate_budget_goal_request(int include_optional);



budget_goal_request_t* instantiate_budget_goal_request(int include_optional) {
  budget_goal_request_t* budget_goal_request = NULL;
  if (include_optional) {
    budget_goal_request = budget_goal_request_create(
      "0",
      56
    );
  } else {
    budget_goal_request = budget_goal_request_create(
      "0",
      56
    );
  }

  return budget_goal_request;
}


#ifdef budget_goal_request_MAIN

void test_budget_goal_request(int include_optional) {
    budget_goal_request_t* budget_goal_request_1 = instantiate_budget_goal_request(include_optional);

	cJSON* jsonbudget_goal_request_1 = budget_goal_request_convertToJSON(budget_goal_request_1);
	printf("budget_goal_request :\n%s\n", cJSON_Print(jsonbudget_goal_request_1));
	budget_goal_request_t* budget_goal_request_2 = budget_goal_request_parseFromJSON(jsonbudget_goal_request_1);
	cJSON* jsonbudget_goal_request_2 = budget_goal_request_convertToJSON(budget_goal_request_2);
	printf("repeating budget_goal_request:\n%s\n", cJSON_Print(jsonbudget_goal_request_2));
}

int main() {
  test_budget_goal_request(1);
  test_budget_goal_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // budget_goal_request_MAIN
#endif // budget_goal_request_TEST
