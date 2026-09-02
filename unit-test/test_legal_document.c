#ifndef legal_document_TEST
#define legal_document_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define legal_document_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/legal_document.h"
legal_document_t* instantiate_legal_document(int include_optional);



legal_document_t* instantiate_legal_document(int include_optional) {
  legal_document_t* legal_document = NULL;
  if (include_optional) {
    legal_document = legal_document_create(
      "0",
      simplebilly_api_legal_document__imprint,
      simplebilly_api_legal_document__DE,
      "0"
    );
  } else {
    legal_document = legal_document_create(
      "0",
      simplebilly_api_legal_document__imprint,
      simplebilly_api_legal_document__DE,
      "0"
    );
  }

  return legal_document;
}


#ifdef legal_document_MAIN

void test_legal_document(int include_optional) {
    legal_document_t* legal_document_1 = instantiate_legal_document(include_optional);

	cJSON* jsonlegal_document_1 = legal_document_convertToJSON(legal_document_1);
	printf("legal_document :\n%s\n", cJSON_Print(jsonlegal_document_1));
	legal_document_t* legal_document_2 = legal_document_parseFromJSON(jsonlegal_document_1);
	cJSON* jsonlegal_document_2 = legal_document_convertToJSON(legal_document_2);
	printf("repeating legal_document:\n%s\n", cJSON_Print(jsonlegal_document_2));
}

int main() {
  test_legal_document(1);
  test_legal_document(0);

  printf("Hello world \n");
  return 0;
}

#endif // legal_document_MAIN
#endif // legal_document_TEST
