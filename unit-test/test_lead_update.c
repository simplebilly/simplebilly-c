#ifndef lead_update_TEST
#define lead_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lead_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lead_update.h"
lead_update_t* instantiate_lead_update(int include_optional);



lead_update_t* instantiate_lead_update(int include_optional) {
  lead_update_t* lead_update = NULL;
  if (include_optional) {
    lead_update = lead_update_create(
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      56,
      "0",
      new,
      null,
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    lead_update = lead_update_create(
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      56,
      "0",
      new,
      null,
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return lead_update;
}


#ifdef lead_update_MAIN

void test_lead_update(int include_optional) {
    lead_update_t* lead_update_1 = instantiate_lead_update(include_optional);

	cJSON* jsonlead_update_1 = lead_update_convertToJSON(lead_update_1);
	printf("lead_update :\n%s\n", cJSON_Print(jsonlead_update_1));
	lead_update_t* lead_update_2 = lead_update_parseFromJSON(jsonlead_update_1);
	cJSON* jsonlead_update_2 = lead_update_convertToJSON(lead_update_2);
	printf("repeating lead_update:\n%s\n", cJSON_Print(jsonlead_update_2));
}

int main() {
  test_lead_update(1);
  test_lead_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // lead_update_MAIN
#endif // lead_update_TEST
