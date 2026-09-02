#ifndef service_assignment_status_TEST
#define service_assignment_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_assignment_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_assignment_status.h"
service_assignment_status_t* instantiate_service_assignment_status(int include_optional);



service_assignment_status_t* instantiate_service_assignment_status(int include_optional) {
  service_assignment_status_t* service_assignment_status = NULL;
  if (include_optional) {
    service_assignment_status = service_assignment_status_create(
    );
  } else {
    service_assignment_status = service_assignment_status_create(
    );
  }

  return service_assignment_status;
}


#ifdef service_assignment_status_MAIN

void test_service_assignment_status(int include_optional) {
    service_assignment_status_t* service_assignment_status_1 = instantiate_service_assignment_status(include_optional);

	cJSON* jsonservice_assignment_status_1 = service_assignment_status_convertToJSON(service_assignment_status_1);
	printf("service_assignment_status :\n%s\n", cJSON_Print(jsonservice_assignment_status_1));
	service_assignment_status_t* service_assignment_status_2 = service_assignment_status_parseFromJSON(jsonservice_assignment_status_1);
	cJSON* jsonservice_assignment_status_2 = service_assignment_status_convertToJSON(service_assignment_status_2);
	printf("repeating service_assignment_status:\n%s\n", cJSON_Print(jsonservice_assignment_status_2));
}

int main() {
  test_service_assignment_status(1);
  test_service_assignment_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // service_assignment_status_MAIN
#endif // service_assignment_status_TEST
