#ifndef job_posting_create_TEST
#define job_posting_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define job_posting_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/job_posting_create.h"
job_posting_create_t* instantiate_job_posting_create(int include_optional);



job_posting_create_t* instantiate_job_posting_create(int include_optional) {
  job_posting_create_t* job_posting_create = NULL;
  if (include_optional) {
    job_posting_create = job_posting_create_create(
      "0",
      "0",
      "0",
      fulltime,
      "0",
      1,
      null,
      "0",
      56,
      56,
      draft,
      "0"
    );
  } else {
    job_posting_create = job_posting_create_create(
      "0",
      "0",
      "0",
      fulltime,
      "0",
      1,
      null,
      "0",
      56,
      56,
      draft,
      "0"
    );
  }

  return job_posting_create;
}


#ifdef job_posting_create_MAIN

void test_job_posting_create(int include_optional) {
    job_posting_create_t* job_posting_create_1 = instantiate_job_posting_create(include_optional);

	cJSON* jsonjob_posting_create_1 = job_posting_create_convertToJSON(job_posting_create_1);
	printf("job_posting_create :\n%s\n", cJSON_Print(jsonjob_posting_create_1));
	job_posting_create_t* job_posting_create_2 = job_posting_create_parseFromJSON(jsonjob_posting_create_1);
	cJSON* jsonjob_posting_create_2 = job_posting_create_convertToJSON(job_posting_create_2);
	printf("repeating job_posting_create:\n%s\n", cJSON_Print(jsonjob_posting_create_2));
}

int main() {
  test_job_posting_create(1);
  test_job_posting_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // job_posting_create_MAIN
#endif // job_posting_create_TEST
