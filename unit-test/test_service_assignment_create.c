#ifndef service_assignment_create_TEST
#define service_assignment_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_assignment_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_assignment_create.h"
service_assignment_create_t* instantiate_service_assignment_create(int include_optional);



service_assignment_create_t* instantiate_service_assignment_create(int include_optional) {
  service_assignment_create_t* service_assignment_create = NULL;
  if (include_optional) {
    service_assignment_create = service_assignment_create_create(
      "0",
      "0",
      "0",
      "2013-10-20",
      "0",
      "0",
      planned
    );
  } else {
    service_assignment_create = service_assignment_create_create(
      "0",
      "0",
      "0",
      "2013-10-20",
      "0",
      "0",
      planned
    );
  }

  return service_assignment_create;
}


#ifdef service_assignment_create_MAIN

void test_service_assignment_create(int include_optional) {
    service_assignment_create_t* service_assignment_create_1 = instantiate_service_assignment_create(include_optional);

	cJSON* jsonservice_assignment_create_1 = service_assignment_create_convertToJSON(service_assignment_create_1);
	printf("service_assignment_create :\n%s\n", cJSON_Print(jsonservice_assignment_create_1));
	service_assignment_create_t* service_assignment_create_2 = service_assignment_create_parseFromJSON(jsonservice_assignment_create_1);
	cJSON* jsonservice_assignment_create_2 = service_assignment_create_convertToJSON(service_assignment_create_2);
	printf("repeating service_assignment_create:\n%s\n", cJSON_Print(jsonservice_assignment_create_2));
}

int main() {
  test_service_assignment_create(1);
  test_service_assignment_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // service_assignment_create_MAIN
#endif // service_assignment_create_TEST
