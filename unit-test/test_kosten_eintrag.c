#ifndef kosten_eintrag_TEST
#define kosten_eintrag_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define kosten_eintrag_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/kosten_eintrag.h"
kosten_eintrag_t* instantiate_kosten_eintrag(int include_optional);



kosten_eintrag_t* instantiate_kosten_eintrag(int include_optional) {
  kosten_eintrag_t* kosten_eintrag = NULL;
  if (include_optional) {
    kosten_eintrag = kosten_eintrag_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    kosten_eintrag = kosten_eintrag_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return kosten_eintrag;
}


#ifdef kosten_eintrag_MAIN

void test_kosten_eintrag(int include_optional) {
    kosten_eintrag_t* kosten_eintrag_1 = instantiate_kosten_eintrag(include_optional);

	cJSON* jsonkosten_eintrag_1 = kosten_eintrag_convertToJSON(kosten_eintrag_1);
	printf("kosten_eintrag :\n%s\n", cJSON_Print(jsonkosten_eintrag_1));
	kosten_eintrag_t* kosten_eintrag_2 = kosten_eintrag_parseFromJSON(jsonkosten_eintrag_1);
	cJSON* jsonkosten_eintrag_2 = kosten_eintrag_convertToJSON(kosten_eintrag_2);
	printf("repeating kosten_eintrag:\n%s\n", cJSON_Print(jsonkosten_eintrag_2));
}

int main() {
  test_kosten_eintrag(1);
  test_kosten_eintrag(0);

  printf("Hello world \n");
  return 0;
}

#endif // kosten_eintrag_MAIN
#endif // kosten_eintrag_TEST
