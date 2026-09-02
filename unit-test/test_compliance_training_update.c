#ifndef compliance_training_update_TEST
#define compliance_training_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define compliance_training_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/compliance_training_update.h"
compliance_training_update_t* instantiate_compliance_training_update(int include_optional);



compliance_training_update_t* instantiate_compliance_training_update(int include_optional) {
  compliance_training_update_t* compliance_training_update = NULL;
  if (include_optional) {
    compliance_training_update = compliance_training_update_create(
      1,
      "0",
      "0",
      56,
      "0",
      builtin,
      "0",
      56
    );
  } else {
    compliance_training_update = compliance_training_update_create(
      1,
      "0",
      "0",
      56,
      "0",
      builtin,
      "0",
      56
    );
  }

  return compliance_training_update;
}


#ifdef compliance_training_update_MAIN

void test_compliance_training_update(int include_optional) {
    compliance_training_update_t* compliance_training_update_1 = instantiate_compliance_training_update(include_optional);

	cJSON* jsoncompliance_training_update_1 = compliance_training_update_convertToJSON(compliance_training_update_1);
	printf("compliance_training_update :\n%s\n", cJSON_Print(jsoncompliance_training_update_1));
	compliance_training_update_t* compliance_training_update_2 = compliance_training_update_parseFromJSON(jsoncompliance_training_update_1);
	cJSON* jsoncompliance_training_update_2 = compliance_training_update_convertToJSON(compliance_training_update_2);
	printf("repeating compliance_training_update:\n%s\n", cJSON_Print(jsoncompliance_training_update_2));
}

int main() {
  test_compliance_training_update(1);
  test_compliance_training_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // compliance_training_update_MAIN
#endif // compliance_training_update_TEST
