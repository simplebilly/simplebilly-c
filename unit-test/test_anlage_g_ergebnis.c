#ifndef anlage_g_ergebnis_TEST
#define anlage_g_ergebnis_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define anlage_g_ergebnis_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/anlage_g_ergebnis.h"
anlage_g_ergebnis_t* instantiate_anlage_g_ergebnis(int include_optional);



anlage_g_ergebnis_t* instantiate_anlage_g_ergebnis(int include_optional) {
  anlage_g_ergebnis_t* anlage_g_ergebnis = NULL;
  if (include_optional) {
    anlage_g_ergebnis = anlage_g_ergebnis_create(
      "0",
      "0",
      "0",
      1,
      56,
      list_createList()
    );
  } else {
    anlage_g_ergebnis = anlage_g_ergebnis_create(
      "0",
      "0",
      "0",
      1,
      56,
      list_createList()
    );
  }

  return anlage_g_ergebnis;
}


#ifdef anlage_g_ergebnis_MAIN

void test_anlage_g_ergebnis(int include_optional) {
    anlage_g_ergebnis_t* anlage_g_ergebnis_1 = instantiate_anlage_g_ergebnis(include_optional);

	cJSON* jsonanlage_g_ergebnis_1 = anlage_g_ergebnis_convertToJSON(anlage_g_ergebnis_1);
	printf("anlage_g_ergebnis :\n%s\n", cJSON_Print(jsonanlage_g_ergebnis_1));
	anlage_g_ergebnis_t* anlage_g_ergebnis_2 = anlage_g_ergebnis_parseFromJSON(jsonanlage_g_ergebnis_1);
	cJSON* jsonanlage_g_ergebnis_2 = anlage_g_ergebnis_convertToJSON(anlage_g_ergebnis_2);
	printf("repeating anlage_g_ergebnis:\n%s\n", cJSON_Print(jsonanlage_g_ergebnis_2));
}

int main() {
  test_anlage_g_ergebnis(1);
  test_anlage_g_ergebnis(0);

  printf("Hello world \n");
  return 0;
}

#endif // anlage_g_ergebnis_MAIN
#endif // anlage_g_ergebnis_TEST
