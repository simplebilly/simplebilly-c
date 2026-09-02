#ifndef service_assignment_TEST
#define service_assignment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_assignment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_assignment.h"
service_assignment_t* instantiate_service_assignment(int include_optional);



service_assignment_t* instantiate_service_assignment(int include_optional) {
  service_assignment_t* service_assignment = NULL;
  if (include_optional) {
    service_assignment = service_assignment_create(
      "0",
      "0",
      "0",
      "2013-10-20",
      "0",
      "0",
      planned
    );
  } else {
    service_assignment = service_assignment_create(
      "0",
      "0",
      "0",
      "2013-10-20",
      "0",
      "0",
      planned
    );
  }

  return service_assignment;
}


#ifdef service_assignment_MAIN

void test_service_assignment(int include_optional) {
    service_assignment_t* service_assignment_1 = instantiate_service_assignment(include_optional);

	cJSON* jsonservice_assignment_1 = service_assignment_convertToJSON(service_assignment_1);
	printf("service_assignment :\n%s\n", cJSON_Print(jsonservice_assignment_1));
	service_assignment_t* service_assignment_2 = service_assignment_parseFromJSON(jsonservice_assignment_1);
	cJSON* jsonservice_assignment_2 = service_assignment_convertToJSON(service_assignment_2);
	printf("repeating service_assignment:\n%s\n", cJSON_Print(jsonservice_assignment_2));
}

int main() {
  test_service_assignment(1);
  test_service_assignment(0);

  printf("Hello world \n");
  return 0;
}

#endif // service_assignment_MAIN
#endif // service_assignment_TEST
