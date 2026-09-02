#ifndef gewerbesteuer_ergebnis_TEST
#define gewerbesteuer_ergebnis_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gewerbesteuer_ergebnis_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gewerbesteuer_ergebnis.h"
gewerbesteuer_ergebnis_t* instantiate_gewerbesteuer_ergebnis(int include_optional);



gewerbesteuer_ergebnis_t* instantiate_gewerbesteuer_ergebnis(int include_optional) {
  gewerbesteuer_ergebnis_t* gewerbesteuer_ergebnis = NULL;
  if (include_optional) {
    gewerbesteuer_ergebnis = gewerbesteuer_ergebnis_create(
      "0",
      "0",
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    gewerbesteuer_ergebnis = gewerbesteuer_ergebnis_create(
      "0",
      "0",
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return gewerbesteuer_ergebnis;
}


#ifdef gewerbesteuer_ergebnis_MAIN

void test_gewerbesteuer_ergebnis(int include_optional) {
    gewerbesteuer_ergebnis_t* gewerbesteuer_ergebnis_1 = instantiate_gewerbesteuer_ergebnis(include_optional);

	cJSON* jsongewerbesteuer_ergebnis_1 = gewerbesteuer_ergebnis_convertToJSON(gewerbesteuer_ergebnis_1);
	printf("gewerbesteuer_ergebnis :\n%s\n", cJSON_Print(jsongewerbesteuer_ergebnis_1));
	gewerbesteuer_ergebnis_t* gewerbesteuer_ergebnis_2 = gewerbesteuer_ergebnis_parseFromJSON(jsongewerbesteuer_ergebnis_1);
	cJSON* jsongewerbesteuer_ergebnis_2 = gewerbesteuer_ergebnis_convertToJSON(gewerbesteuer_ergebnis_2);
	printf("repeating gewerbesteuer_ergebnis:\n%s\n", cJSON_Print(jsongewerbesteuer_ergebnis_2));
}

int main() {
  test_gewerbesteuer_ergebnis(1);
  test_gewerbesteuer_ergebnis(0);

  printf("Hello world \n");
  return 0;
}

#endif // gewerbesteuer_ergebnis_MAIN
#endif // gewerbesteuer_ergebnis_TEST
