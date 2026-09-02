#ifndef bwa_summary_TEST
#define bwa_summary_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bwa_summary_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bwa_summary.h"
bwa_summary_t* instantiate_bwa_summary(int include_optional);



bwa_summary_t* instantiate_bwa_summary(int include_optional) {
  bwa_summary_t* bwa_summary = NULL;
  if (include_optional) {
    bwa_summary = bwa_summary_create(
      "0",
      "0",
      56,
      "0",
      56,
      "0",
      1.337
    );
  } else {
    bwa_summary = bwa_summary_create(
      "0",
      "0",
      56,
      "0",
      56,
      "0",
      1.337
    );
  }

  return bwa_summary;
}


#ifdef bwa_summary_MAIN

void test_bwa_summary(int include_optional) {
    bwa_summary_t* bwa_summary_1 = instantiate_bwa_summary(include_optional);

	cJSON* jsonbwa_summary_1 = bwa_summary_convertToJSON(bwa_summary_1);
	printf("bwa_summary :\n%s\n", cJSON_Print(jsonbwa_summary_1));
	bwa_summary_t* bwa_summary_2 = bwa_summary_parseFromJSON(jsonbwa_summary_1);
	cJSON* jsonbwa_summary_2 = bwa_summary_convertToJSON(bwa_summary_2);
	printf("repeating bwa_summary:\n%s\n", cJSON_Print(jsonbwa_summary_2));
}

int main() {
  test_bwa_summary(1);
  test_bwa_summary(0);

  printf("Hello world \n");
  return 0;
}

#endif // bwa_summary_MAIN
#endif // bwa_summary_TEST
