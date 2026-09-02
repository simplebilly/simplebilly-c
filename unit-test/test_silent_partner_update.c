#ifndef silent_partner_update_TEST
#define silent_partner_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define silent_partner_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/silent_partner_update.h"
silent_partner_update_t* instantiate_silent_partner_update(int include_optional);



silent_partner_update_t* instantiate_silent_partner_update(int include_optional) {
  silent_partner_update_t* silent_partner_update = NULL;
  if (include_optional) {
    silent_partner_update = silent_partner_update_create(
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
    silent_partner_update = silent_partner_update_create(
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

  return silent_partner_update;
}


#ifdef silent_partner_update_MAIN

void test_silent_partner_update(int include_optional) {
    silent_partner_update_t* silent_partner_update_1 = instantiate_silent_partner_update(include_optional);

	cJSON* jsonsilent_partner_update_1 = silent_partner_update_convertToJSON(silent_partner_update_1);
	printf("silent_partner_update :\n%s\n", cJSON_Print(jsonsilent_partner_update_1));
	silent_partner_update_t* silent_partner_update_2 = silent_partner_update_parseFromJSON(jsonsilent_partner_update_1);
	cJSON* jsonsilent_partner_update_2 = silent_partner_update_convertToJSON(silent_partner_update_2);
	printf("repeating silent_partner_update:\n%s\n", cJSON_Print(jsonsilent_partner_update_2));
}

int main() {
  test_silent_partner_update(1);
  test_silent_partner_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // silent_partner_update_MAIN
#endif // silent_partner_update_TEST
