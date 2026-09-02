#ifndef silent_partner_TEST
#define silent_partner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define silent_partner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/silent_partner.h"
silent_partner_t* instantiate_silent_partner(int include_optional);



silent_partner_t* instantiate_silent_partner(int include_optional) {
  silent_partner_t* silent_partner = NULL;
  if (include_optional) {
    silent_partner = silent_partner_create(
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
    silent_partner = silent_partner_create(
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

  return silent_partner;
}


#ifdef silent_partner_MAIN

void test_silent_partner(int include_optional) {
    silent_partner_t* silent_partner_1 = instantiate_silent_partner(include_optional);

	cJSON* jsonsilent_partner_1 = silent_partner_convertToJSON(silent_partner_1);
	printf("silent_partner :\n%s\n", cJSON_Print(jsonsilent_partner_1));
	silent_partner_t* silent_partner_2 = silent_partner_parseFromJSON(jsonsilent_partner_1);
	cJSON* jsonsilent_partner_2 = silent_partner_convertToJSON(silent_partner_2);
	printf("repeating silent_partner:\n%s\n", cJSON_Print(jsonsilent_partner_2));
}

int main() {
  test_silent_partner(1);
  test_silent_partner(0);

  printf("Hello world \n");
  return 0;
}

#endif // silent_partner_MAIN
#endif // silent_partner_TEST
