#ifndef pn_l_item_TEST
#define pn_l_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pn_l_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pn_l_item.h"
pn_l_item_t* instantiate_pn_l_item(int include_optional);



pn_l_item_t* instantiate_pn_l_item(int include_optional) {
  pn_l_item_t* pn_l_item = NULL;
  if (include_optional) {
    pn_l_item = pn_l_item_create(
      "0",
      "0",
      "0"
    );
  } else {
    pn_l_item = pn_l_item_create(
      "0",
      "0",
      "0"
    );
  }

  return pn_l_item;
}


#ifdef pn_l_item_MAIN

void test_pn_l_item(int include_optional) {
    pn_l_item_t* pn_l_item_1 = instantiate_pn_l_item(include_optional);

	cJSON* jsonpn_l_item_1 = pn_l_item_convertToJSON(pn_l_item_1);
	printf("pn_l_item :\n%s\n", cJSON_Print(jsonpn_l_item_1));
	pn_l_item_t* pn_l_item_2 = pn_l_item_parseFromJSON(jsonpn_l_item_1);
	cJSON* jsonpn_l_item_2 = pn_l_item_convertToJSON(pn_l_item_2);
	printf("repeating pn_l_item:\n%s\n", cJSON_Print(jsonpn_l_item_2));
}

int main() {
  test_pn_l_item(1);
  test_pn_l_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // pn_l_item_MAIN
#endif // pn_l_item_TEST
