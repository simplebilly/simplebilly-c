#ifndef severity_TEST
#define severity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define severity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/severity.h"
severity_t* instantiate_severity(int include_optional);



severity_t* instantiate_severity(int include_optional) {
  severity_t* severity = NULL;
  if (include_optional) {
    severity = severity_create(
    );
  } else {
    severity = severity_create(
    );
  }

  return severity;
}


#ifdef severity_MAIN

void test_severity(int include_optional) {
    severity_t* severity_1 = instantiate_severity(include_optional);

	cJSON* jsonseverity_1 = severity_convertToJSON(severity_1);
	printf("severity :\n%s\n", cJSON_Print(jsonseverity_1));
	severity_t* severity_2 = severity_parseFromJSON(jsonseverity_1);
	cJSON* jsonseverity_2 = severity_convertToJSON(severity_2);
	printf("repeating severity:\n%s\n", cJSON_Print(jsonseverity_2));
}

int main() {
  test_severity(1);
  test_severity(0);

  printf("Hello world \n");
  return 0;
}

#endif // severity_MAIN
#endif // severity_TEST
