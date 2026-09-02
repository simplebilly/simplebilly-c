#ifndef training_assignment_update_TEST
#define training_assignment_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define training_assignment_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/training_assignment_update.h"
training_assignment_update_t* instantiate_training_assignment_update(int include_optional);



training_assignment_update_t* instantiate_training_assignment_update(int include_optional) {
  training_assignment_update_t* training_assignment_update = NULL;
  if (include_optional) {
    training_assignment_update = training_assignment_update_create(
      "0",
      "2013-10-20",
      "0",
      "0",
      required,
      "0"
    );
  } else {
    training_assignment_update = training_assignment_update_create(
      "0",
      "2013-10-20",
      "0",
      "0",
      required,
      "0"
    );
  }

  return training_assignment_update;
}


#ifdef training_assignment_update_MAIN

void test_training_assignment_update(int include_optional) {
    training_assignment_update_t* training_assignment_update_1 = instantiate_training_assignment_update(include_optional);

	cJSON* jsontraining_assignment_update_1 = training_assignment_update_convertToJSON(training_assignment_update_1);
	printf("training_assignment_update :\n%s\n", cJSON_Print(jsontraining_assignment_update_1));
	training_assignment_update_t* training_assignment_update_2 = training_assignment_update_parseFromJSON(jsontraining_assignment_update_1);
	cJSON* jsontraining_assignment_update_2 = training_assignment_update_convertToJSON(training_assignment_update_2);
	printf("repeating training_assignment_update:\n%s\n", cJSON_Print(jsontraining_assignment_update_2));
}

int main() {
  test_training_assignment_update(1);
  test_training_assignment_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // training_assignment_update_MAIN
#endif // training_assignment_update_TEST
