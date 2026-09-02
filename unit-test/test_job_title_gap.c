#ifndef job_title_gap_TEST
#define job_title_gap_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define job_title_gap_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/job_title_gap.h"
job_title_gap_t* instantiate_job_title_gap(int include_optional);



job_title_gap_t* instantiate_job_title_gap(int include_optional) {
  job_title_gap_t* job_title_gap = NULL;
  if (include_optional) {
    job_title_gap = job_title_gap_create(
      0,
      "0",
      "0",
      "0",
      1.337,
      1.337
    );
  } else {
    job_title_gap = job_title_gap_create(
      0,
      "0",
      "0",
      "0",
      1.337,
      1.337
    );
  }

  return job_title_gap;
}


#ifdef job_title_gap_MAIN

void test_job_title_gap(int include_optional) {
    job_title_gap_t* job_title_gap_1 = instantiate_job_title_gap(include_optional);

	cJSON* jsonjob_title_gap_1 = job_title_gap_convertToJSON(job_title_gap_1);
	printf("job_title_gap :\n%s\n", cJSON_Print(jsonjob_title_gap_1));
	job_title_gap_t* job_title_gap_2 = job_title_gap_parseFromJSON(jsonjob_title_gap_1);
	cJSON* jsonjob_title_gap_2 = job_title_gap_convertToJSON(job_title_gap_2);
	printf("repeating job_title_gap:\n%s\n", cJSON_Print(jsonjob_title_gap_2));
}

int main() {
  test_job_title_gap(1);
  test_job_title_gap(0);

  printf("Hello world \n");
  return 0;
}

#endif // job_title_gap_MAIN
#endif // job_title_gap_TEST
