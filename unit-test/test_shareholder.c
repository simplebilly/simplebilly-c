#ifndef shareholder_TEST
#define shareholder_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shareholder_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shareholder.h"
shareholder_t* instantiate_shareholder(int include_optional);



shareholder_t* instantiate_shareholder(int include_optional) {
  shareholder_t* shareholder = NULL;
  if (include_optional) {
    shareholder = shareholder_create(
      "0",
      "2013-10-20",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    shareholder = shareholder_create(
      "0",
      "2013-10-20",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return shareholder;
}


#ifdef shareholder_MAIN

void test_shareholder(int include_optional) {
    shareholder_t* shareholder_1 = instantiate_shareholder(include_optional);

	cJSON* jsonshareholder_1 = shareholder_convertToJSON(shareholder_1);
	printf("shareholder :\n%s\n", cJSON_Print(jsonshareholder_1));
	shareholder_t* shareholder_2 = shareholder_parseFromJSON(jsonshareholder_1);
	cJSON* jsonshareholder_2 = shareholder_convertToJSON(shareholder_2);
	printf("repeating shareholder:\n%s\n", cJSON_Print(jsonshareholder_2));
}

int main() {
  test_shareholder(1);
  test_shareholder(0);

  printf("Hello world \n");
  return 0;
}

#endif // shareholder_MAIN
#endif // shareholder_TEST
