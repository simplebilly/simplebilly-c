#ifndef workflow_enabled_update_TEST
#define workflow_enabled_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define workflow_enabled_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/workflow_enabled_update.h"
workflow_enabled_update_t* instantiate_workflow_enabled_update(int include_optional);



workflow_enabled_update_t* instantiate_workflow_enabled_update(int include_optional) {
  workflow_enabled_update_t* workflow_enabled_update = NULL;
  if (include_optional) {
    workflow_enabled_update = workflow_enabled_update_create(
      1
    );
  } else {
    workflow_enabled_update = workflow_enabled_update_create(
      1
    );
  }

  return workflow_enabled_update;
}


#ifdef workflow_enabled_update_MAIN

void test_workflow_enabled_update(int include_optional) {
    workflow_enabled_update_t* workflow_enabled_update_1 = instantiate_workflow_enabled_update(include_optional);

	cJSON* jsonworkflow_enabled_update_1 = workflow_enabled_update_convertToJSON(workflow_enabled_update_1);
	printf("workflow_enabled_update :\n%s\n", cJSON_Print(jsonworkflow_enabled_update_1));
	workflow_enabled_update_t* workflow_enabled_update_2 = workflow_enabled_update_parseFromJSON(jsonworkflow_enabled_update_1);
	cJSON* jsonworkflow_enabled_update_2 = workflow_enabled_update_convertToJSON(workflow_enabled_update_2);
	printf("repeating workflow_enabled_update:\n%s\n", cJSON_Print(jsonworkflow_enabled_update_2));
}

int main() {
  test_workflow_enabled_update(1);
  test_workflow_enabled_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // workflow_enabled_update_MAIN
#endif // workflow_enabled_update_TEST
