#ifndef shareholder_create_TEST
#define shareholder_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shareholder_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shareholder_create.h"
shareholder_create_t* instantiate_shareholder_create(int include_optional);



shareholder_create_t* instantiate_shareholder_create(int include_optional) {
  shareholder_create_t* shareholder_create = NULL;
  if (include_optional) {
    shareholder_create = shareholder_create_create(
      "0",
      "2013-10-20",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    shareholder_create = shareholder_create_create(
      "0",
      "2013-10-20",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return shareholder_create;
}


#ifdef shareholder_create_MAIN

void test_shareholder_create(int include_optional) {
    shareholder_create_t* shareholder_create_1 = instantiate_shareholder_create(include_optional);

	cJSON* jsonshareholder_create_1 = shareholder_create_convertToJSON(shareholder_create_1);
	printf("shareholder_create :\n%s\n", cJSON_Print(jsonshareholder_create_1));
	shareholder_create_t* shareholder_create_2 = shareholder_create_parseFromJSON(jsonshareholder_create_1);
	cJSON* jsonshareholder_create_2 = shareholder_create_convertToJSON(shareholder_create_2);
	printf("repeating shareholder_create:\n%s\n", cJSON_Print(jsonshareholder_create_2));
}

int main() {
  test_shareholder_create(1);
  test_shareholder_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // shareholder_create_MAIN
#endif // shareholder_create_TEST
