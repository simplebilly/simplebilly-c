#ifndef job_posting_update_TEST
#define job_posting_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define job_posting_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/job_posting_update.h"
job_posting_update_t* instantiate_job_posting_update(int include_optional);



job_posting_update_t* instantiate_job_posting_update(int include_optional) {
  job_posting_update_t* job_posting_update = NULL;
  if (include_optional) {
    job_posting_update = job_posting_update_create(
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
    job_posting_update = job_posting_update_create(
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

  return job_posting_update;
}


#ifdef job_posting_update_MAIN

void test_job_posting_update(int include_optional) {
    job_posting_update_t* job_posting_update_1 = instantiate_job_posting_update(include_optional);

	cJSON* jsonjob_posting_update_1 = job_posting_update_convertToJSON(job_posting_update_1);
	printf("job_posting_update :\n%s\n", cJSON_Print(jsonjob_posting_update_1));
	job_posting_update_t* job_posting_update_2 = job_posting_update_parseFromJSON(jsonjob_posting_update_1);
	cJSON* jsonjob_posting_update_2 = job_posting_update_convertToJSON(job_posting_update_2);
	printf("repeating job_posting_update:\n%s\n", cJSON_Print(jsonjob_posting_update_2));
}

int main() {
  test_job_posting_update(1);
  test_job_posting_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // job_posting_update_MAIN
#endif // job_posting_update_TEST
