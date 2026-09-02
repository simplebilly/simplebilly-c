#ifndef vat_item_TEST
#define vat_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define vat_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/vat_item.h"
vat_item_t* instantiate_vat_item(int include_optional);



vat_item_t* instantiate_vat_item(int include_optional) {
  vat_item_t* vat_item = NULL;
  if (include_optional) {
    vat_item = vat_item_create(
      "0",
      "0",
      "0"
    );
  } else {
    vat_item = vat_item_create(
      "0",
      "0",
      "0"
    );
  }

  return vat_item;
}


#ifdef vat_item_MAIN

void test_vat_item(int include_optional) {
    vat_item_t* vat_item_1 = instantiate_vat_item(include_optional);

	cJSON* jsonvat_item_1 = vat_item_convertToJSON(vat_item_1);
	printf("vat_item :\n%s\n", cJSON_Print(jsonvat_item_1));
	vat_item_t* vat_item_2 = vat_item_parseFromJSON(jsonvat_item_1);
	cJSON* jsonvat_item_2 = vat_item_convertToJSON(vat_item_2);
	printf("repeating vat_item:\n%s\n", cJSON_Print(jsonvat_item_2));
}

int main() {
  test_vat_item(1);
  test_vat_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // vat_item_MAIN
#endif // vat_item_TEST
