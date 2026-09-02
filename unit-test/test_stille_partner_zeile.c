#ifndef stille_partner_zeile_TEST
#define stille_partner_zeile_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stille_partner_zeile_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stille_partner_zeile.h"
stille_partner_zeile_t* instantiate_stille_partner_zeile(int include_optional);



stille_partner_zeile_t* instantiate_stille_partner_zeile(int include_optional) {
  stille_partner_zeile_t* stille_partner_zeile = NULL;
  if (include_optional) {
    stille_partner_zeile = stille_partner_zeile_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    stille_partner_zeile = stille_partner_zeile_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return stille_partner_zeile;
}


#ifdef stille_partner_zeile_MAIN

void test_stille_partner_zeile(int include_optional) {
    stille_partner_zeile_t* stille_partner_zeile_1 = instantiate_stille_partner_zeile(include_optional);

	cJSON* jsonstille_partner_zeile_1 = stille_partner_zeile_convertToJSON(stille_partner_zeile_1);
	printf("stille_partner_zeile :\n%s\n", cJSON_Print(jsonstille_partner_zeile_1));
	stille_partner_zeile_t* stille_partner_zeile_2 = stille_partner_zeile_parseFromJSON(jsonstille_partner_zeile_1);
	cJSON* jsonstille_partner_zeile_2 = stille_partner_zeile_convertToJSON(stille_partner_zeile_2);
	printf("repeating stille_partner_zeile:\n%s\n", cJSON_Print(jsonstille_partner_zeile_2));
}

int main() {
  test_stille_partner_zeile(1);
  test_stille_partner_zeile(0);

  printf("Hello world \n");
  return 0;
}

#endif // stille_partner_zeile_MAIN
#endif // stille_partner_zeile_TEST
