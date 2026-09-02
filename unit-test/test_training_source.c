#ifndef training_source_TEST
#define training_source_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define training_source_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/training_source.h"
training_source_t* instantiate_training_source(int include_optional);



training_source_t* instantiate_training_source(int include_optional) {
  training_source_t* training_source = NULL;
  if (include_optional) {
    training_source = training_source_create(
    );
  } else {
    training_source = training_source_create(
    );
  }

  return training_source;
}


#ifdef training_source_MAIN

void test_training_source(int include_optional) {
    training_source_t* training_source_1 = instantiate_training_source(include_optional);

	cJSON* jsontraining_source_1 = training_source_convertToJSON(training_source_1);
	printf("training_source :\n%s\n", cJSON_Print(jsontraining_source_1));
	training_source_t* training_source_2 = training_source_parseFromJSON(jsontraining_source_1);
	cJSON* jsontraining_source_2 = training_source_convertToJSON(training_source_2);
	printf("repeating training_source:\n%s\n", cJSON_Print(jsontraining_source_2));
}

int main() {
  test_training_source(1);
  test_training_source(0);

  printf("Hello world \n");
  return 0;
}

#endif // training_source_MAIN
#endif // training_source_TEST
