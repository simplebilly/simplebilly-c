#ifndef kosten_vorschau_TEST
#define kosten_vorschau_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define kosten_vorschau_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/kosten_vorschau.h"
kosten_vorschau_t* instantiate_kosten_vorschau(int include_optional);



kosten_vorschau_t* instantiate_kosten_vorschau(int include_optional) {
  kosten_vorschau_t* kosten_vorschau = NULL;
  if (include_optional) {
    kosten_vorschau = kosten_vorschau_create(
      list_createList(),
      "0"
    );
  } else {
    kosten_vorschau = kosten_vorschau_create(
      list_createList(),
      "0"
    );
  }

  return kosten_vorschau;
}


#ifdef kosten_vorschau_MAIN

void test_kosten_vorschau(int include_optional) {
    kosten_vorschau_t* kosten_vorschau_1 = instantiate_kosten_vorschau(include_optional);

	cJSON* jsonkosten_vorschau_1 = kosten_vorschau_convertToJSON(kosten_vorschau_1);
	printf("kosten_vorschau :\n%s\n", cJSON_Print(jsonkosten_vorschau_1));
	kosten_vorschau_t* kosten_vorschau_2 = kosten_vorschau_parseFromJSON(jsonkosten_vorschau_1);
	cJSON* jsonkosten_vorschau_2 = kosten_vorschau_convertToJSON(kosten_vorschau_2);
	printf("repeating kosten_vorschau:\n%s\n", cJSON_Print(jsonkosten_vorschau_2));
}

int main() {
  test_kosten_vorschau(1);
  test_kosten_vorschau(0);

  printf("Hello world \n");
  return 0;
}

#endif // kosten_vorschau_MAIN
#endif // kosten_vorschau_TEST
