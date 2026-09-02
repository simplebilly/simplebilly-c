#ifndef service_job_create_TEST
#define service_job_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_job_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_job_create.h"
service_job_create_t* instantiate_service_job_create(int include_optional);



service_job_create_t* instantiate_service_job_create(int include_optional) {
  service_job_create_t* service_job_create = NULL;
  if (include_optional) {
    service_job_create = service_job_create_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      1.337,
      1.337,
      "0",
      pending
    );
  } else {
    service_job_create = service_job_create_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      1.337,
      1.337,
      "0",
      pending
    );
  }

  return service_job_create;
}


#ifdef service_job_create_MAIN

void test_service_job_create(int include_optional) {
    service_job_create_t* service_job_create_1 = instantiate_service_job_create(include_optional);

	cJSON* jsonservice_job_create_1 = service_job_create_convertToJSON(service_job_create_1);
	printf("service_job_create :\n%s\n", cJSON_Print(jsonservice_job_create_1));
	service_job_create_t* service_job_create_2 = service_job_create_parseFromJSON(jsonservice_job_create_1);
	cJSON* jsonservice_job_create_2 = service_job_create_convertToJSON(service_job_create_2);
	printf("repeating service_job_create:\n%s\n", cJSON_Print(jsonservice_job_create_2));
}

int main() {
  test_service_job_create(1);
  test_service_job_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // service_job_create_MAIN
#endif // service_job_create_TEST
