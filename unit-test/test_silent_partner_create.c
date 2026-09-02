#ifndef silent_partner_create_TEST
#define silent_partner_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define silent_partner_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/silent_partner_create.h"
silent_partner_create_t* instantiate_silent_partner_create(int include_optional);



silent_partner_create_t* instantiate_silent_partner_create(int include_optional) {
  silent_partner_create_t* silent_partner_create = NULL;
  if (include_optional) {
    silent_partner_create = silent_partner_create_create(
      "2013-10-20",
      "0",
      "0",
      "0",
      typisch,
      1,
      "0",
      "0",
      "0",
      1
    );
  } else {
    silent_partner_create = silent_partner_create_create(
      "2013-10-20",
      "0",
      "0",
      "0",
      typisch,
      1,
      "0",
      "0",
      "0",
      1
    );
  }

  return silent_partner_create;
}


#ifdef silent_partner_create_MAIN

void test_silent_partner_create(int include_optional) {
    silent_partner_create_t* silent_partner_create_1 = instantiate_silent_partner_create(include_optional);

	cJSON* jsonsilent_partner_create_1 = silent_partner_create_convertToJSON(silent_partner_create_1);
	printf("silent_partner_create :\n%s\n", cJSON_Print(jsonsilent_partner_create_1));
	silent_partner_create_t* silent_partner_create_2 = silent_partner_create_parseFromJSON(jsonsilent_partner_create_1);
	cJSON* jsonsilent_partner_create_2 = silent_partner_create_convertToJSON(silent_partner_create_2);
	printf("repeating silent_partner_create:\n%s\n", cJSON_Print(jsonsilent_partner_create_2));
}

int main() {
  test_silent_partner_create(1);
  test_silent_partner_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // silent_partner_create_MAIN
#endif // silent_partner_create_TEST
