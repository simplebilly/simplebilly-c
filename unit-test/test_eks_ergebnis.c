#ifndef eks_ergebnis_TEST
#define eks_ergebnis_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define eks_ergebnis_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/eks_ergebnis.h"
eks_ergebnis_t* instantiate_eks_ergebnis(int include_optional);



eks_ergebnis_t* instantiate_eks_ergebnis(int include_optional) {
  eks_ergebnis_t* eks_ergebnis = NULL;
  if (include_optional) {
    eks_ergebnis = eks_ergebnis_create(
      "0",
      list_createList(),
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    eks_ergebnis = eks_ergebnis_create(
      "0",
      list_createList(),
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return eks_ergebnis;
}


#ifdef eks_ergebnis_MAIN

void test_eks_ergebnis(int include_optional) {
    eks_ergebnis_t* eks_ergebnis_1 = instantiate_eks_ergebnis(include_optional);

	cJSON* jsoneks_ergebnis_1 = eks_ergebnis_convertToJSON(eks_ergebnis_1);
	printf("eks_ergebnis :\n%s\n", cJSON_Print(jsoneks_ergebnis_1));
	eks_ergebnis_t* eks_ergebnis_2 = eks_ergebnis_parseFromJSON(jsoneks_ergebnis_1);
	cJSON* jsoneks_ergebnis_2 = eks_ergebnis_convertToJSON(eks_ergebnis_2);
	printf("repeating eks_ergebnis:\n%s\n", cJSON_Print(jsoneks_ergebnis_2));
}

int main() {
  test_eks_ergebnis(1);
  test_eks_ergebnis(0);

  printf("Hello world \n");
  return 0;
}

#endif // eks_ergebnis_MAIN
#endif // eks_ergebnis_TEST
