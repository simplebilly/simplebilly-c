#ifndef shareholder_update_TEST
#define shareholder_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shareholder_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shareholder_update.h"
shareholder_update_t* instantiate_shareholder_update(int include_optional);



shareholder_update_t* instantiate_shareholder_update(int include_optional) {
  shareholder_update_t* shareholder_update = NULL;
  if (include_optional) {
    shareholder_update = shareholder_update_create(
      "0",
      "2013-10-20",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    shareholder_update = shareholder_update_create(
      "0",
      "2013-10-20",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return shareholder_update;
}


#ifdef shareholder_update_MAIN

void test_shareholder_update(int include_optional) {
    shareholder_update_t* shareholder_update_1 = instantiate_shareholder_update(include_optional);

	cJSON* jsonshareholder_update_1 = shareholder_update_convertToJSON(shareholder_update_1);
	printf("shareholder_update :\n%s\n", cJSON_Print(jsonshareholder_update_1));
	shareholder_update_t* shareholder_update_2 = shareholder_update_parseFromJSON(jsonshareholder_update_1);
	cJSON* jsonshareholder_update_2 = shareholder_update_convertToJSON(shareholder_update_2);
	printf("repeating shareholder_update:\n%s\n", cJSON_Print(jsonshareholder_update_2));
}

int main() {
  test_shareholder_update(1);
  test_shareholder_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // shareholder_update_MAIN
#endif // shareholder_update_TEST
