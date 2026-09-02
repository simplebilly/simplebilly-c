#ifndef anlage_s_ergebnis_TEST
#define anlage_s_ergebnis_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define anlage_s_ergebnis_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/anlage_s_ergebnis.h"
anlage_s_ergebnis_t* instantiate_anlage_s_ergebnis(int include_optional);



anlage_s_ergebnis_t* instantiate_anlage_s_ergebnis(int include_optional) {
  anlage_s_ergebnis_t* anlage_s_ergebnis = NULL;
  if (include_optional) {
    anlage_s_ergebnis = anlage_s_ergebnis_create(
      "0",
      56,
      list_createList()
    );
  } else {
    anlage_s_ergebnis = anlage_s_ergebnis_create(
      "0",
      56,
      list_createList()
    );
  }

  return anlage_s_ergebnis;
}


#ifdef anlage_s_ergebnis_MAIN

void test_anlage_s_ergebnis(int include_optional) {
    anlage_s_ergebnis_t* anlage_s_ergebnis_1 = instantiate_anlage_s_ergebnis(include_optional);

	cJSON* jsonanlage_s_ergebnis_1 = anlage_s_ergebnis_convertToJSON(anlage_s_ergebnis_1);
	printf("anlage_s_ergebnis :\n%s\n", cJSON_Print(jsonanlage_s_ergebnis_1));
	anlage_s_ergebnis_t* anlage_s_ergebnis_2 = anlage_s_ergebnis_parseFromJSON(jsonanlage_s_ergebnis_1);
	cJSON* jsonanlage_s_ergebnis_2 = anlage_s_ergebnis_convertToJSON(anlage_s_ergebnis_2);
	printf("repeating anlage_s_ergebnis:\n%s\n", cJSON_Print(jsonanlage_s_ergebnis_2));
}

int main() {
  test_anlage_s_ergebnis(1);
  test_anlage_s_ergebnis(0);

  printf("Hello world \n");
  return 0;
}

#endif // anlage_s_ergebnis_MAIN
#endif // anlage_s_ergebnis_TEST
