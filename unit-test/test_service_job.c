#ifndef service_job_TEST
#define service_job_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_job_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_job.h"
service_job_t* instantiate_service_job(int include_optional);



service_job_t* instantiate_service_job(int include_optional) {
  service_job_t* service_job = NULL;
  if (include_optional) {
    service_job = service_job_create(
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
    service_job = service_job_create(
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

  return service_job;
}


#ifdef service_job_MAIN

void test_service_job(int include_optional) {
    service_job_t* service_job_1 = instantiate_service_job(include_optional);

	cJSON* jsonservice_job_1 = service_job_convertToJSON(service_job_1);
	printf("service_job :\n%s\n", cJSON_Print(jsonservice_job_1));
	service_job_t* service_job_2 = service_job_parseFromJSON(jsonservice_job_1);
	cJSON* jsonservice_job_2 = service_job_convertToJSON(service_job_2);
	printf("repeating service_job:\n%s\n", cJSON_Print(jsonservice_job_2));
}

int main() {
  test_service_job(1);
  test_service_job(0);

  printf("Hello world \n");
  return 0;
}

#endif // service_job_MAIN
#endif // service_job_TEST
