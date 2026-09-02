#ifndef gu_v_item_TEST
#define gu_v_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gu_v_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gu_v_item.h"
gu_v_item_t* instantiate_gu_v_item(int include_optional);



gu_v_item_t* instantiate_gu_v_item(int include_optional) {
  gu_v_item_t* gu_v_item = NULL;
  if (include_optional) {
    gu_v_item = gu_v_item_create(
      "0",
      "0",
      "0"
    );
  } else {
    gu_v_item = gu_v_item_create(
      "0",
      "0",
      "0"
    );
  }

  return gu_v_item;
}


#ifdef gu_v_item_MAIN

void test_gu_v_item(int include_optional) {
    gu_v_item_t* gu_v_item_1 = instantiate_gu_v_item(include_optional);

	cJSON* jsongu_v_item_1 = gu_v_item_convertToJSON(gu_v_item_1);
	printf("gu_v_item :\n%s\n", cJSON_Print(jsongu_v_item_1));
	gu_v_item_t* gu_v_item_2 = gu_v_item_parseFromJSON(jsongu_v_item_1);
	cJSON* jsongu_v_item_2 = gu_v_item_convertToJSON(gu_v_item_2);
	printf("repeating gu_v_item:\n%s\n", cJSON_Print(jsongu_v_item_2));
}

int main() {
  test_gu_v_item(1);
  test_gu_v_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // gu_v_item_MAIN
#endif // gu_v_item_TEST
