#ifndef legal_document_upsert_TEST
#define legal_document_upsert_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define legal_document_upsert_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/legal_document_upsert.h"
legal_document_upsert_t* instantiate_legal_document_upsert(int include_optional);



legal_document_upsert_t* instantiate_legal_document_upsert(int include_optional) {
  legal_document_upsert_t* legal_document_upsert = NULL;
  if (include_optional) {
    legal_document_upsert = legal_document_upsert_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    legal_document_upsert = legal_document_upsert_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return legal_document_upsert;
}


#ifdef legal_document_upsert_MAIN

void test_legal_document_upsert(int include_optional) {
    legal_document_upsert_t* legal_document_upsert_1 = instantiate_legal_document_upsert(include_optional);

	cJSON* jsonlegal_document_upsert_1 = legal_document_upsert_convertToJSON(legal_document_upsert_1);
	printf("legal_document_upsert :\n%s\n", cJSON_Print(jsonlegal_document_upsert_1));
	legal_document_upsert_t* legal_document_upsert_2 = legal_document_upsert_parseFromJSON(jsonlegal_document_upsert_1);
	cJSON* jsonlegal_document_upsert_2 = legal_document_upsert_convertToJSON(legal_document_upsert_2);
	printf("repeating legal_document_upsert:\n%s\n", cJSON_Print(jsonlegal_document_upsert_2));
}

int main() {
  test_legal_document_upsert(1);
  test_legal_document_upsert(0);

  printf("Hello world \n");
  return 0;
}

#endif // legal_document_upsert_MAIN
#endif // legal_document_upsert_TEST
