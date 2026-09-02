#ifndef workflow_TEST
#define workflow_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define workflow_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/workflow.h"
workflow_t* instantiate_workflow(int include_optional);



workflow_t* instantiate_workflow(int include_optional) {
  workflow_t* workflow = NULL;
  if (include_optional) {
    workflow = workflow_create(
      null,
      1,
      "0",
      "0"
    );
  } else {
    workflow = workflow_create(
      null,
      1,
      "0",
      "0"
    );
  }

  return workflow;
}


#ifdef workflow_MAIN

void test_workflow(int include_optional) {
    workflow_t* workflow_1 = instantiate_workflow(include_optional);

	cJSON* jsonworkflow_1 = workflow_convertToJSON(workflow_1);
	printf("workflow :\n%s\n", cJSON_Print(jsonworkflow_1));
	workflow_t* workflow_2 = workflow_parseFromJSON(jsonworkflow_1);
	cJSON* jsonworkflow_2 = workflow_convertToJSON(workflow_2);
	printf("repeating workflow:\n%s\n", cJSON_Print(jsonworkflow_2));
}

int main() {
  test_workflow(1);
  test_workflow(0);

  printf("Hello world \n");
  return 0;
}

#endif // workflow_MAIN
#endif // workflow_TEST
