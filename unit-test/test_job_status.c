#ifndef job_status_TEST
#define job_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define job_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/job_status.h"
job_status_t* instantiate_job_status(int include_optional);



job_status_t* instantiate_job_status(int include_optional) {
  job_status_t* job_status = NULL;
  if (include_optional) {
    job_status = job_status_create(
    );
  } else {
    job_status = job_status_create(
    );
  }

  return job_status;
}


#ifdef job_status_MAIN

void test_job_status(int include_optional) {
    job_status_t* job_status_1 = instantiate_job_status(include_optional);

	cJSON* jsonjob_status_1 = job_status_convertToJSON(job_status_1);
	printf("job_status :\n%s\n", cJSON_Print(jsonjob_status_1));
	job_status_t* job_status_2 = job_status_parseFromJSON(jsonjob_status_1);
	cJSON* jsonjob_status_2 = job_status_convertToJSON(job_status_2);
	printf("repeating job_status:\n%s\n", cJSON_Print(jsonjob_status_2));
}

int main() {
  test_job_status(1);
  test_job_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // job_status_MAIN
#endif // job_status_TEST
