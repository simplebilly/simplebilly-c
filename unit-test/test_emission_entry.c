#ifndef emission_entry_TEST
#define emission_entry_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define emission_entry_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/emission_entry.h"
emission_entry_t* instantiate_emission_entry(int include_optional);



emission_entry_t* instantiate_emission_entry(int include_optional) {
  emission_entry_t* emission_entry = NULL;
  if (include_optional) {
    emission_entry = emission_entry_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      activity,
      1,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      56
    );
  } else {
    emission_entry = emission_entry_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      activity,
      1,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      56
    );
  }

  return emission_entry;
}


#ifdef emission_entry_MAIN

void test_emission_entry(int include_optional) {
    emission_entry_t* emission_entry_1 = instantiate_emission_entry(include_optional);

	cJSON* jsonemission_entry_1 = emission_entry_convertToJSON(emission_entry_1);
	printf("emission_entry :\n%s\n", cJSON_Print(jsonemission_entry_1));
	emission_entry_t* emission_entry_2 = emission_entry_parseFromJSON(jsonemission_entry_1);
	cJSON* jsonemission_entry_2 = emission_entry_convertToJSON(emission_entry_2);
	printf("repeating emission_entry:\n%s\n", cJSON_Print(jsonemission_entry_2));
}

int main() {
  test_emission_entry(1);
  test_emission_entry(0);

  printf("Hello world \n");
  return 0;
}

#endif // emission_entry_MAIN
#endif // emission_entry_TEST
