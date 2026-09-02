#ifndef job_posting_filter_TEST
#define job_posting_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define job_posting_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/job_posting_filter.h"
job_posting_filter_t* instantiate_job_posting_filter(int include_optional);



job_posting_filter_t* instantiate_job_posting_filter(int include_optional) {
  job_posting_filter_t* job_posting_filter = NULL;
  if (include_optional) {
    job_posting_filter = job_posting_filter_create(
      0,
      0,
      "0"
    );
  } else {
    job_posting_filter = job_posting_filter_create(
      0,
      0,
      "0"
    );
  }

  return job_posting_filter;
}


#ifdef job_posting_filter_MAIN

void test_job_posting_filter(int include_optional) {
    job_posting_filter_t* job_posting_filter_1 = instantiate_job_posting_filter(include_optional);

	cJSON* jsonjob_posting_filter_1 = job_posting_filter_convertToJSON(job_posting_filter_1);
	printf("job_posting_filter :\n%s\n", cJSON_Print(jsonjob_posting_filter_1));
	job_posting_filter_t* job_posting_filter_2 = job_posting_filter_parseFromJSON(jsonjob_posting_filter_1);
	cJSON* jsonjob_posting_filter_2 = job_posting_filter_convertToJSON(job_posting_filter_2);
	printf("repeating job_posting_filter:\n%s\n", cJSON_Print(jsonjob_posting_filter_2));
}

int main() {
  test_job_posting_filter(1);
  test_job_posting_filter(0);

  printf("Hello world \n");
  return 0;
}

#endif // job_posting_filter_MAIN
#endif // job_posting_filter_TEST
