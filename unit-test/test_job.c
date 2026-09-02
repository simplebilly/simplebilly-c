#ifndef job_TEST
#define job_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define job_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/job.h"
job_t* instantiate_job(int include_optional);



job_t* instantiate_job(int include_optional) {
  job_t* job = NULL;
  if (include_optional) {
    job = job_create(
      56,
      "0",
      56,
      null,
      "2013-10-20T19:20:30+01:00",
      pending
    );
  } else {
    job = job_create(
      56,
      "0",
      56,
      null,
      "2013-10-20T19:20:30+01:00",
      pending
    );
  }

  return job;
}


#ifdef job_MAIN

void test_job(int include_optional) {
    job_t* job_1 = instantiate_job(include_optional);

	cJSON* jsonjob_1 = job_convertToJSON(job_1);
	printf("job :\n%s\n", cJSON_Print(jsonjob_1));
	job_t* job_2 = job_parseFromJSON(jsonjob_1);
	cJSON* jsonjob_2 = job_convertToJSON(job_2);
	printf("repeating job:\n%s\n", cJSON_Print(jsonjob_2));
}

int main() {
  test_job(1);
  test_job(0);

  printf("Hello world \n");
  return 0;
}

#endif // job_MAIN
#endif // job_TEST
