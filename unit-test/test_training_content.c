#ifndef training_content_TEST
#define training_content_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define training_content_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/training_content.h"
training_content_t* instantiate_training_content(int include_optional);

#include "test_contact_info.c"


training_content_t* instantiate_training_content(int include_optional) {
  training_content_t* training_content = NULL;
  if (include_optional) {
    training_content = training_content_create(
      "0",
       // false, not to have infinite recursion
      instantiate_contact_info(0),
      56,
      list_createList(),
      list_createList(),
      "0",
      "0"
    );
  } else {
    training_content = training_content_create(
      "0",
      NULL,
      56,
      list_createList(),
      list_createList(),
      "0",
      "0"
    );
  }

  return training_content;
}


#ifdef training_content_MAIN

void test_training_content(int include_optional) {
    training_content_t* training_content_1 = instantiate_training_content(include_optional);

	cJSON* jsontraining_content_1 = training_content_convertToJSON(training_content_1);
	printf("training_content :\n%s\n", cJSON_Print(jsontraining_content_1));
	training_content_t* training_content_2 = training_content_parseFromJSON(jsontraining_content_1);
	cJSON* jsontraining_content_2 = training_content_convertToJSON(training_content_2);
	printf("repeating training_content:\n%s\n", cJSON_Print(jsontraining_content_2));
}

int main() {
  test_training_content(1);
  test_training_content(0);

  printf("Hello world \n");
  return 0;
}

#endif // training_content_MAIN
#endif // training_content_TEST
