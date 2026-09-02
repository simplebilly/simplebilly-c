#ifndef create_emission_target_TEST
#define create_emission_target_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_emission_target_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_emission_target.h"
create_emission_target_t* instantiate_create_emission_target(int include_optional);



create_emission_target_t* instantiate_create_emission_target(int include_optional) {
  create_emission_target_t* create_emission_target = NULL;
  if (include_optional) {
    create_emission_target = create_emission_target_create(
      "0",
      56,
      "0",
      "0",
      "0",
      56
    );
  } else {
    create_emission_target = create_emission_target_create(
      "0",
      56,
      "0",
      "0",
      "0",
      56
    );
  }

  return create_emission_target;
}


#ifdef create_emission_target_MAIN

void test_create_emission_target(int include_optional) {
    create_emission_target_t* create_emission_target_1 = instantiate_create_emission_target(include_optional);

	cJSON* jsoncreate_emission_target_1 = create_emission_target_convertToJSON(create_emission_target_1);
	printf("create_emission_target :\n%s\n", cJSON_Print(jsoncreate_emission_target_1));
	create_emission_target_t* create_emission_target_2 = create_emission_target_parseFromJSON(jsoncreate_emission_target_1);
	cJSON* jsoncreate_emission_target_2 = create_emission_target_convertToJSON(create_emission_target_2);
	printf("repeating create_emission_target:\n%s\n", cJSON_Print(jsoncreate_emission_target_2));
}

int main() {
  test_create_emission_target(1);
  test_create_emission_target(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_emission_target_MAIN
#endif // create_emission_target_TEST
