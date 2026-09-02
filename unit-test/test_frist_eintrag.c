#ifndef frist_eintrag_TEST
#define frist_eintrag_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define frist_eintrag_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/frist_eintrag.h"
frist_eintrag_t* instantiate_frist_eintrag(int include_optional);



frist_eintrag_t* instantiate_frist_eintrag(int include_optional) {
  frist_eintrag_t* frist_eintrag = NULL;
  if (include_optional) {
    frist_eintrag = frist_eintrag_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    frist_eintrag = frist_eintrag_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return frist_eintrag;
}


#ifdef frist_eintrag_MAIN

void test_frist_eintrag(int include_optional) {
    frist_eintrag_t* frist_eintrag_1 = instantiate_frist_eintrag(include_optional);

	cJSON* jsonfrist_eintrag_1 = frist_eintrag_convertToJSON(frist_eintrag_1);
	printf("frist_eintrag :\n%s\n", cJSON_Print(jsonfrist_eintrag_1));
	frist_eintrag_t* frist_eintrag_2 = frist_eintrag_parseFromJSON(jsonfrist_eintrag_1);
	cJSON* jsonfrist_eintrag_2 = frist_eintrag_convertToJSON(frist_eintrag_2);
	printf("repeating frist_eintrag:\n%s\n", cJSON_Print(jsonfrist_eintrag_2));
}

int main() {
  test_frist_eintrag(1);
  test_frist_eintrag(0);

  printf("Hello world \n");
  return 0;
}

#endif // frist_eintrag_MAIN
#endif // frist_eintrag_TEST
