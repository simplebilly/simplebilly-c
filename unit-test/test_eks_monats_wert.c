#ifndef eks_monats_wert_TEST
#define eks_monats_wert_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define eks_monats_wert_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/eks_monats_wert.h"
eks_monats_wert_t* instantiate_eks_monats_wert(int include_optional);



eks_monats_wert_t* instantiate_eks_monats_wert(int include_optional) {
  eks_monats_wert_t* eks_monats_wert = NULL;
  if (include_optional) {
    eks_monats_wert = eks_monats_wert_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    eks_monats_wert = eks_monats_wert_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return eks_monats_wert;
}


#ifdef eks_monats_wert_MAIN

void test_eks_monats_wert(int include_optional) {
    eks_monats_wert_t* eks_monats_wert_1 = instantiate_eks_monats_wert(include_optional);

	cJSON* jsoneks_monats_wert_1 = eks_monats_wert_convertToJSON(eks_monats_wert_1);
	printf("eks_monats_wert :\n%s\n", cJSON_Print(jsoneks_monats_wert_1));
	eks_monats_wert_t* eks_monats_wert_2 = eks_monats_wert_parseFromJSON(jsoneks_monats_wert_1);
	cJSON* jsoneks_monats_wert_2 = eks_monats_wert_convertToJSON(eks_monats_wert_2);
	printf("repeating eks_monats_wert:\n%s\n", cJSON_Print(jsoneks_monats_wert_2));
}

int main() {
  test_eks_monats_wert(1);
  test_eks_monats_wert(0);

  printf("Hello world \n");
  return 0;
}

#endif // eks_monats_wert_MAIN
#endif // eks_monats_wert_TEST
