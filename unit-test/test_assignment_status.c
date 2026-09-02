#ifndef assignment_status_TEST
#define assignment_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assignment_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assignment_status.h"
assignment_status_t* instantiate_assignment_status(int include_optional);



assignment_status_t* instantiate_assignment_status(int include_optional) {
  assignment_status_t* assignment_status = NULL;
  if (include_optional) {
    assignment_status = assignment_status_create(
    );
  } else {
    assignment_status = assignment_status_create(
    );
  }

  return assignment_status;
}


#ifdef assignment_status_MAIN

void test_assignment_status(int include_optional) {
    assignment_status_t* assignment_status_1 = instantiate_assignment_status(include_optional);

	cJSON* jsonassignment_status_1 = assignment_status_convertToJSON(assignment_status_1);
	printf("assignment_status :\n%s\n", cJSON_Print(jsonassignment_status_1));
	assignment_status_t* assignment_status_2 = assignment_status_parseFromJSON(jsonassignment_status_1);
	cJSON* jsonassignment_status_2 = assignment_status_convertToJSON(assignment_status_2);
	printf("repeating assignment_status:\n%s\n", cJSON_Print(jsonassignment_status_2));
}

int main() {
  test_assignment_status(1);
  test_assignment_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // assignment_status_MAIN
#endif // assignment_status_TEST
