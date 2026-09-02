#ifndef training_assignment_create_TEST
#define training_assignment_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define training_assignment_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/training_assignment_create.h"
training_assignment_create_t* instantiate_training_assignment_create(int include_optional);



training_assignment_create_t* instantiate_training_assignment_create(int include_optional) {
  training_assignment_create_t* training_assignment_create = NULL;
  if (include_optional) {
    training_assignment_create = training_assignment_create_create(
      "0",
      "2013-10-20",
      "0",
      "0",
      simplebilly_api_training_assignment_create__required,
      "0"
    );
  } else {
    training_assignment_create = training_assignment_create_create(
      "0",
      "2013-10-20",
      "0",
      "0",
      simplebilly_api_training_assignment_create__required,
      "0"
    );
  }

  return training_assignment_create;
}


#ifdef training_assignment_create_MAIN

void test_training_assignment_create(int include_optional) {
    training_assignment_create_t* training_assignment_create_1 = instantiate_training_assignment_create(include_optional);

	cJSON* jsontraining_assignment_create_1 = training_assignment_create_convertToJSON(training_assignment_create_1);
	printf("training_assignment_create :\n%s\n", cJSON_Print(jsontraining_assignment_create_1));
	training_assignment_create_t* training_assignment_create_2 = training_assignment_create_parseFromJSON(jsontraining_assignment_create_1);
	cJSON* jsontraining_assignment_create_2 = training_assignment_create_convertToJSON(training_assignment_create_2);
	printf("repeating training_assignment_create:\n%s\n", cJSON_Print(jsontraining_assignment_create_2));
}

int main() {
  test_training_assignment_create(1);
  test_training_assignment_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // training_assignment_create_MAIN
#endif // training_assignment_create_TEST
