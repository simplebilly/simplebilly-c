#ifndef job_posting_TEST
#define job_posting_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define job_posting_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/job_posting.h"
job_posting_t* instantiate_job_posting(int include_optional);



job_posting_t* instantiate_job_posting(int include_optional) {
  job_posting_t* job_posting = NULL;
  if (include_optional) {
    job_posting = job_posting_create(
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
    job_posting = job_posting_create(
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

  return job_posting;
}


#ifdef job_posting_MAIN

void test_job_posting(int include_optional) {
    job_posting_t* job_posting_1 = instantiate_job_posting(include_optional);

	cJSON* jsonjob_posting_1 = job_posting_convertToJSON(job_posting_1);
	printf("job_posting :\n%s\n", cJSON_Print(jsonjob_posting_1));
	job_posting_t* job_posting_2 = job_posting_parseFromJSON(jsonjob_posting_1);
	cJSON* jsonjob_posting_2 = job_posting_convertToJSON(job_posting_2);
	printf("repeating job_posting:\n%s\n", cJSON_Print(jsonjob_posting_2));
}

int main() {
  test_job_posting(1);
  test_job_posting(0);

  printf("Hello world \n");
  return 0;
}

#endif // job_posting_MAIN
#endif // job_posting_TEST
