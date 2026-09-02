#ifndef training_assignment_TEST
#define training_assignment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define training_assignment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/training_assignment.h"
training_assignment_t* instantiate_training_assignment(int include_optional);



training_assignment_t* instantiate_training_assignment(int include_optional) {
  training_assignment_t* training_assignment = NULL;
  if (include_optional) {
    training_assignment = training_assignment_create(
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20",
      "0",
      "0",
      "0",
      simplebilly_api_training_assignment__required,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    training_assignment = training_assignment_create(
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20",
      "0",
      "0",
      "0",
      simplebilly_api_training_assignment__required,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return training_assignment;
}


#ifdef training_assignment_MAIN

void test_training_assignment(int include_optional) {
    training_assignment_t* training_assignment_1 = instantiate_training_assignment(include_optional);

	cJSON* jsontraining_assignment_1 = training_assignment_convertToJSON(training_assignment_1);
	printf("training_assignment :\n%s\n", cJSON_Print(jsontraining_assignment_1));
	training_assignment_t* training_assignment_2 = training_assignment_parseFromJSON(jsontraining_assignment_1);
	cJSON* jsontraining_assignment_2 = training_assignment_convertToJSON(training_assignment_2);
	printf("repeating training_assignment:\n%s\n", cJSON_Print(jsontraining_assignment_2));
}

int main() {
  test_training_assignment(1);
  test_training_assignment(0);

  printf("Hello world \n");
  return 0;
}

#endif // training_assignment_MAIN
#endif // training_assignment_TEST
