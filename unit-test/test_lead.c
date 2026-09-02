#ifndef lead_TEST
#define lead_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lead_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lead.h"
lead_t* instantiate_lead(int include_optional);



lead_t* instantiate_lead(int include_optional) {
  lead_t* lead = NULL;
  if (include_optional) {
    lead = lead_create(
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
      simplebilly_api_lead__new,
      null,
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    lead = lead_create(
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
      simplebilly_api_lead__new,
      null,
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return lead;
}


#ifdef lead_MAIN

void test_lead(int include_optional) {
    lead_t* lead_1 = instantiate_lead(include_optional);

	cJSON* jsonlead_1 = lead_convertToJSON(lead_1);
	printf("lead :\n%s\n", cJSON_Print(jsonlead_1));
	lead_t* lead_2 = lead_parseFromJSON(jsonlead_1);
	cJSON* jsonlead_2 = lead_convertToJSON(lead_2);
	printf("repeating lead:\n%s\n", cJSON_Print(jsonlead_2));
}

int main() {
  test_lead(1);
  test_lead(0);

  printf("Hello world \n");
  return 0;
}

#endif // lead_MAIN
#endif // lead_TEST
