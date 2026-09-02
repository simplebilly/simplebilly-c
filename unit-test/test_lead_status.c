#ifndef lead_status_TEST
#define lead_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lead_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lead_status.h"
lead_status_t* instantiate_lead_status(int include_optional);



lead_status_t* instantiate_lead_status(int include_optional) {
  lead_status_t* lead_status = NULL;
  if (include_optional) {
    lead_status = lead_status_create(
    );
  } else {
    lead_status = lead_status_create(
    );
  }

  return lead_status;
}


#ifdef lead_status_MAIN

void test_lead_status(int include_optional) {
    lead_status_t* lead_status_1 = instantiate_lead_status(include_optional);

	cJSON* jsonlead_status_1 = lead_status_convertToJSON(lead_status_1);
	printf("lead_status :\n%s\n", cJSON_Print(jsonlead_status_1));
	lead_status_t* lead_status_2 = lead_status_parseFromJSON(jsonlead_status_1);
	cJSON* jsonlead_status_2 = lead_status_convertToJSON(lead_status_2);
	printf("repeating lead_status:\n%s\n", cJSON_Print(jsonlead_status_2));
}

int main() {
  test_lead_status(1);
  test_lead_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // lead_status_MAIN
#endif // lead_status_TEST
