#ifndef jahres_ust_ergebnis_TEST
#define jahres_ust_ergebnis_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define jahres_ust_ergebnis_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/jahres_ust_ergebnis.h"
jahres_ust_ergebnis_t* instantiate_jahres_ust_ergebnis(int include_optional);



jahres_ust_ergebnis_t* instantiate_jahres_ust_ergebnis(int include_optional) {
  jahres_ust_ergebnis_t* jahres_ust_ergebnis = NULL;
  if (include_optional) {
    jahres_ust_ergebnis = jahres_ust_ergebnis_create(
      "0",
      56,
      1,
      1,
      56,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
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
    jahres_ust_ergebnis = jahres_ust_ergebnis_create(
      "0",
      56,
      1,
      1,
      56,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
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

  return jahres_ust_ergebnis;
}


#ifdef jahres_ust_ergebnis_MAIN

void test_jahres_ust_ergebnis(int include_optional) {
    jahres_ust_ergebnis_t* jahres_ust_ergebnis_1 = instantiate_jahres_ust_ergebnis(include_optional);

	cJSON* jsonjahres_ust_ergebnis_1 = jahres_ust_ergebnis_convertToJSON(jahres_ust_ergebnis_1);
	printf("jahres_ust_ergebnis :\n%s\n", cJSON_Print(jsonjahres_ust_ergebnis_1));
	jahres_ust_ergebnis_t* jahres_ust_ergebnis_2 = jahres_ust_ergebnis_parseFromJSON(jsonjahres_ust_ergebnis_1);
	cJSON* jsonjahres_ust_ergebnis_2 = jahres_ust_ergebnis_convertToJSON(jahres_ust_ergebnis_2);
	printf("repeating jahres_ust_ergebnis:\n%s\n", cJSON_Print(jsonjahres_ust_ergebnis_2));
}

int main() {
  test_jahres_ust_ergebnis(1);
  test_jahres_ust_ergebnis(0);

  printf("Hello world \n");
  return 0;
}

#endif // jahres_ust_ergebnis_MAIN
#endif // jahres_ust_ergebnis_TEST
