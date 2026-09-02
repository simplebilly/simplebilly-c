#ifndef compliance_training_TEST
#define compliance_training_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define compliance_training_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/compliance_training.h"
compliance_training_t* instantiate_compliance_training(int include_optional);



compliance_training_t* instantiate_compliance_training(int include_optional) {
  compliance_training_t* compliance_training = NULL;
  if (include_optional) {
    compliance_training = compliance_training_create(
      1,
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      56,
      "0",
      simplebilly_api_compliance_training__builtin,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      56
    );
  } else {
    compliance_training = compliance_training_create(
      1,
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      56,
      "0",
      simplebilly_api_compliance_training__builtin,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      56
    );
  }

  return compliance_training;
}


#ifdef compliance_training_MAIN

void test_compliance_training(int include_optional) {
    compliance_training_t* compliance_training_1 = instantiate_compliance_training(include_optional);

	cJSON* jsoncompliance_training_1 = compliance_training_convertToJSON(compliance_training_1);
	printf("compliance_training :\n%s\n", cJSON_Print(jsoncompliance_training_1));
	compliance_training_t* compliance_training_2 = compliance_training_parseFromJSON(jsoncompliance_training_1);
	cJSON* jsoncompliance_training_2 = compliance_training_convertToJSON(compliance_training_2);
	printf("repeating compliance_training:\n%s\n", cJSON_Print(jsoncompliance_training_2));
}

int main() {
  test_compliance_training(1);
  test_compliance_training(0);

  printf("Hello world \n");
  return 0;
}

#endif // compliance_training_MAIN
#endif // compliance_training_TEST
