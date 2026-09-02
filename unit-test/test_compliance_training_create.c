#ifndef compliance_training_create_TEST
#define compliance_training_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define compliance_training_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/compliance_training_create.h"
compliance_training_create_t* instantiate_compliance_training_create(int include_optional);



compliance_training_create_t* instantiate_compliance_training_create(int include_optional) {
  compliance_training_create_t* compliance_training_create = NULL;
  if (include_optional) {
    compliance_training_create = compliance_training_create_create(
      1,
      "0",
      "0",
      56,
      "0",
      simplebilly_api_compliance_training_create__builtin,
      "0",
      56
    );
  } else {
    compliance_training_create = compliance_training_create_create(
      1,
      "0",
      "0",
      56,
      "0",
      simplebilly_api_compliance_training_create__builtin,
      "0",
      56
    );
  }

  return compliance_training_create;
}


#ifdef compliance_training_create_MAIN

void test_compliance_training_create(int include_optional) {
    compliance_training_create_t* compliance_training_create_1 = instantiate_compliance_training_create(include_optional);

	cJSON* jsoncompliance_training_create_1 = compliance_training_create_convertToJSON(compliance_training_create_1);
	printf("compliance_training_create :\n%s\n", cJSON_Print(jsoncompliance_training_create_1));
	compliance_training_create_t* compliance_training_create_2 = compliance_training_create_parseFromJSON(jsoncompliance_training_create_1);
	cJSON* jsoncompliance_training_create_2 = compliance_training_create_convertToJSON(compliance_training_create_2);
	printf("repeating compliance_training_create:\n%s\n", cJSON_Print(jsoncompliance_training_create_2));
}

int main() {
  test_compliance_training_create(1);
  test_compliance_training_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // compliance_training_create_MAIN
#endif // compliance_training_create_TEST
