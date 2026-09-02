#ifndef workflow_action_TEST
#define workflow_action_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define workflow_action_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/workflow_action.h"
workflow_action_t* instantiate_workflow_action(int include_optional);



workflow_action_t* instantiate_workflow_action(int include_optional) {
  workflow_action_t* workflow_action = NULL;
  if (include_optional) {
    workflow_action = workflow_action_create(
      "0",
      "0",
      "0"
    );
  } else {
    workflow_action = workflow_action_create(
      "0",
      "0",
      "0"
    );
  }

  return workflow_action;
}


#ifdef workflow_action_MAIN

void test_workflow_action(int include_optional) {
    workflow_action_t* workflow_action_1 = instantiate_workflow_action(include_optional);

	cJSON* jsonworkflow_action_1 = workflow_action_convertToJSON(workflow_action_1);
	printf("workflow_action :\n%s\n", cJSON_Print(jsonworkflow_action_1));
	workflow_action_t* workflow_action_2 = workflow_action_parseFromJSON(jsonworkflow_action_1);
	cJSON* jsonworkflow_action_2 = workflow_action_convertToJSON(workflow_action_2);
	printf("repeating workflow_action:\n%s\n", cJSON_Print(jsonworkflow_action_2));
}

int main() {
  test_workflow_action(1);
  test_workflow_action(0);

  printf("Hello world \n");
  return 0;
}

#endif // workflow_action_MAIN
#endif // workflow_action_TEST
