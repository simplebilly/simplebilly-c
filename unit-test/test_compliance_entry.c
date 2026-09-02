#ifndef compliance_entry_TEST
#define compliance_entry_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define compliance_entry_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/compliance_entry.h"
compliance_entry_t* instantiate_compliance_entry(int include_optional);



compliance_entry_t* instantiate_compliance_entry(int include_optional) {
  compliance_entry_t* compliance_entry = NULL;
  if (include_optional) {
    compliance_entry = compliance_entry_create(
      "0",
      "0",
      list_createList()
    );
  } else {
    compliance_entry = compliance_entry_create(
      "0",
      "0",
      list_createList()
    );
  }

  return compliance_entry;
}


#ifdef compliance_entry_MAIN

void test_compliance_entry(int include_optional) {
    compliance_entry_t* compliance_entry_1 = instantiate_compliance_entry(include_optional);

	cJSON* jsoncompliance_entry_1 = compliance_entry_convertToJSON(compliance_entry_1);
	printf("compliance_entry :\n%s\n", cJSON_Print(jsoncompliance_entry_1));
	compliance_entry_t* compliance_entry_2 = compliance_entry_parseFromJSON(jsoncompliance_entry_1);
	cJSON* jsoncompliance_entry_2 = compliance_entry_convertToJSON(compliance_entry_2);
	printf("repeating compliance_entry:\n%s\n", cJSON_Print(jsoncompliance_entry_2));
}

int main() {
  test_compliance_entry(1);
  test_compliance_entry(0);

  printf("Hello world \n");
  return 0;
}

#endif // compliance_entry_MAIN
#endif // compliance_entry_TEST
