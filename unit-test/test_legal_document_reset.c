#ifndef legal_document_reset_TEST
#define legal_document_reset_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define legal_document_reset_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/legal_document_reset.h"
legal_document_reset_t* instantiate_legal_document_reset(int include_optional);



legal_document_reset_t* instantiate_legal_document_reset(int include_optional) {
  legal_document_reset_t* legal_document_reset = NULL;
  if (include_optional) {
    legal_document_reset = legal_document_reset_create(
      "0",
      "0"
    );
  } else {
    legal_document_reset = legal_document_reset_create(
      "0",
      "0"
    );
  }

  return legal_document_reset;
}


#ifdef legal_document_reset_MAIN

void test_legal_document_reset(int include_optional) {
    legal_document_reset_t* legal_document_reset_1 = instantiate_legal_document_reset(include_optional);

	cJSON* jsonlegal_document_reset_1 = legal_document_reset_convertToJSON(legal_document_reset_1);
	printf("legal_document_reset :\n%s\n", cJSON_Print(jsonlegal_document_reset_1));
	legal_document_reset_t* legal_document_reset_2 = legal_document_reset_parseFromJSON(jsonlegal_document_reset_1);
	cJSON* jsonlegal_document_reset_2 = legal_document_reset_convertToJSON(legal_document_reset_2);
	printf("repeating legal_document_reset:\n%s\n", cJSON_Print(jsonlegal_document_reset_2));
}

int main() {
  test_legal_document_reset(1);
  test_legal_document_reset(0);

  printf("Hello world \n");
  return 0;
}

#endif // legal_document_reset_MAIN
#endif // legal_document_reset_TEST
