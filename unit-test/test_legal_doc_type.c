#ifndef legal_doc_type_TEST
#define legal_doc_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define legal_doc_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/legal_doc_type.h"
legal_doc_type_t* instantiate_legal_doc_type(int include_optional);



legal_doc_type_t* instantiate_legal_doc_type(int include_optional) {
  legal_doc_type_t* legal_doc_type = NULL;
  if (include_optional) {
    legal_doc_type = legal_doc_type_create(
    );
  } else {
    legal_doc_type = legal_doc_type_create(
    );
  }

  return legal_doc_type;
}


#ifdef legal_doc_type_MAIN

void test_legal_doc_type(int include_optional) {
    legal_doc_type_t* legal_doc_type_1 = instantiate_legal_doc_type(include_optional);

	cJSON* jsonlegal_doc_type_1 = legal_doc_type_convertToJSON(legal_doc_type_1);
	printf("legal_doc_type :\n%s\n", cJSON_Print(jsonlegal_doc_type_1));
	legal_doc_type_t* legal_doc_type_2 = legal_doc_type_parseFromJSON(jsonlegal_doc_type_1);
	cJSON* jsonlegal_doc_type_2 = legal_doc_type_convertToJSON(legal_doc_type_2);
	printf("repeating legal_doc_type:\n%s\n", cJSON_Print(jsonlegal_doc_type_2));
}

int main() {
  test_legal_doc_type(1);
  test_legal_doc_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // legal_doc_type_MAIN
#endif // legal_doc_type_TEST
