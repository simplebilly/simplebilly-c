#ifndef create_emission_entry_TEST
#define create_emission_entry_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_emission_entry_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_emission_entry.h"
create_emission_entry_t* instantiate_create_emission_entry(int include_optional);



create_emission_entry_t* instantiate_create_emission_entry(int include_optional) {
  create_emission_entry_t* create_emission_entry = NULL;
  if (include_optional) {
    create_emission_entry = create_emission_entry_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      56
    );
  } else {
    create_emission_entry = create_emission_entry_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      56
    );
  }

  return create_emission_entry;
}


#ifdef create_emission_entry_MAIN

void test_create_emission_entry(int include_optional) {
    create_emission_entry_t* create_emission_entry_1 = instantiate_create_emission_entry(include_optional);

	cJSON* jsoncreate_emission_entry_1 = create_emission_entry_convertToJSON(create_emission_entry_1);
	printf("create_emission_entry :\n%s\n", cJSON_Print(jsoncreate_emission_entry_1));
	create_emission_entry_t* create_emission_entry_2 = create_emission_entry_parseFromJSON(jsoncreate_emission_entry_1);
	cJSON* jsoncreate_emission_entry_2 = create_emission_entry_convertToJSON(create_emission_entry_2);
	printf("repeating create_emission_entry:\n%s\n", cJSON_Print(jsoncreate_emission_entry_2));
}

int main() {
  test_create_emission_entry(1);
  test_create_emission_entry(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_emission_entry_MAIN
#endif // create_emission_entry_TEST
