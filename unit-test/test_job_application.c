#ifndef job_application_TEST
#define job_application_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define job_application_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/job_application.h"
job_application_t* instantiate_job_application(int include_optional);



job_application_t* instantiate_job_application(int include_optional) {
  job_application_t* job_application = NULL;
  if (include_optional) {
    job_application = job_application_create(
      "0",
      "0",
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      new
    );
  } else {
    job_application = job_application_create(
      "0",
      "0",
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      new
    );
  }

  return job_application;
}


#ifdef job_application_MAIN

void test_job_application(int include_optional) {
    job_application_t* job_application_1 = instantiate_job_application(include_optional);

	cJSON* jsonjob_application_1 = job_application_convertToJSON(job_application_1);
	printf("job_application :\n%s\n", cJSON_Print(jsonjob_application_1));
	job_application_t* job_application_2 = job_application_parseFromJSON(jsonjob_application_1);
	cJSON* jsonjob_application_2 = job_application_convertToJSON(job_application_2);
	printf("repeating job_application:\n%s\n", cJSON_Print(jsonjob_application_2));
}

int main() {
  test_job_application(1);
  test_job_application(0);

  printf("Hello world \n");
  return 0;
}

#endif // job_application_MAIN
#endif // job_application_TEST
