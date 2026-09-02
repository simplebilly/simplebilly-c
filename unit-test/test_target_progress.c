#ifndef target_progress_TEST
#define target_progress_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define target_progress_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/target_progress.h"
target_progress_t* instantiate_target_progress(int include_optional);



target_progress_t* instantiate_target_progress(int include_optional) {
  target_progress_t* target_progress = NULL;
  if (include_optional) {
    target_progress = target_progress_create(
      1.337,
      56,
      "0",
      "0",
      1.337,
      "0",
      1.337,
      56
    );
  } else {
    target_progress = target_progress_create(
      1.337,
      56,
      "0",
      "0",
      1.337,
      "0",
      1.337,
      56
    );
  }

  return target_progress;
}


#ifdef target_progress_MAIN

void test_target_progress(int include_optional) {
    target_progress_t* target_progress_1 = instantiate_target_progress(include_optional);

	cJSON* jsontarget_progress_1 = target_progress_convertToJSON(target_progress_1);
	printf("target_progress :\n%s\n", cJSON_Print(jsontarget_progress_1));
	target_progress_t* target_progress_2 = target_progress_parseFromJSON(jsontarget_progress_1);
	cJSON* jsontarget_progress_2 = target_progress_convertToJSON(target_progress_2);
	printf("repeating target_progress:\n%s\n", cJSON_Print(jsontarget_progress_2));
}

int main() {
  test_target_progress(1);
  test_target_progress(0);

  printf("Hello world \n");
  return 0;
}

#endif // target_progress_MAIN
#endif // target_progress_TEST
