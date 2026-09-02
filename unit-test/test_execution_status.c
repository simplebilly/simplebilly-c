#ifndef execution_status_TEST
#define execution_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define execution_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/execution_status.h"
execution_status_t* instantiate_execution_status(int include_optional);



execution_status_t* instantiate_execution_status(int include_optional) {
  execution_status_t* execution_status = NULL;
  if (include_optional) {
    execution_status = execution_status_create(
    );
  } else {
    execution_status = execution_status_create(
    );
  }

  return execution_status;
}


#ifdef execution_status_MAIN

void test_execution_status(int include_optional) {
    execution_status_t* execution_status_1 = instantiate_execution_status(include_optional);

	cJSON* jsonexecution_status_1 = execution_status_convertToJSON(execution_status_1);
	printf("execution_status :\n%s\n", cJSON_Print(jsonexecution_status_1));
	execution_status_t* execution_status_2 = execution_status_parseFromJSON(jsonexecution_status_1);
	cJSON* jsonexecution_status_2 = execution_status_convertToJSON(execution_status_2);
	printf("repeating execution_status:\n%s\n", cJSON_Print(jsonexecution_status_2));
}

int main() {
  test_execution_status(1);
  test_execution_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // execution_status_MAIN
#endif // execution_status_TEST
