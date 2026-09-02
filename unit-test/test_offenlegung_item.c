#ifndef offenlegung_item_TEST
#define offenlegung_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define offenlegung_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/offenlegung_item.h"
offenlegung_item_t* instantiate_offenlegung_item(int include_optional);



offenlegung_item_t* instantiate_offenlegung_item(int include_optional) {
  offenlegung_item_t* offenlegung_item = NULL;
  if (include_optional) {
    offenlegung_item = offenlegung_item_create(
      1,
      "0",
      "0"
    );
  } else {
    offenlegung_item = offenlegung_item_create(
      1,
      "0",
      "0"
    );
  }

  return offenlegung_item;
}


#ifdef offenlegung_item_MAIN

void test_offenlegung_item(int include_optional) {
    offenlegung_item_t* offenlegung_item_1 = instantiate_offenlegung_item(include_optional);

	cJSON* jsonoffenlegung_item_1 = offenlegung_item_convertToJSON(offenlegung_item_1);
	printf("offenlegung_item :\n%s\n", cJSON_Print(jsonoffenlegung_item_1));
	offenlegung_item_t* offenlegung_item_2 = offenlegung_item_parseFromJSON(jsonoffenlegung_item_1);
	cJSON* jsonoffenlegung_item_2 = offenlegung_item_convertToJSON(offenlegung_item_2);
	printf("repeating offenlegung_item:\n%s\n", cJSON_Print(jsonoffenlegung_item_2));
}

int main() {
  test_offenlegung_item(1);
  test_offenlegung_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // offenlegung_item_MAIN
#endif // offenlegung_item_TEST
