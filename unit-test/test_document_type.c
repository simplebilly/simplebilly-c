#ifndef document_type_TEST
#define document_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define document_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/document_type.h"
document_type_t* instantiate_document_type(int include_optional);



document_type_t* instantiate_document_type(int include_optional) {
  document_type_t* document_type = NULL;
  if (include_optional) {
    document_type = document_type_create(
    );
  } else {
    document_type = document_type_create(
    );
  }

  return document_type;
}


#ifdef document_type_MAIN

void test_document_type(int include_optional) {
    document_type_t* document_type_1 = instantiate_document_type(include_optional);

	cJSON* jsondocument_type_1 = document_type_convertToJSON(document_type_1);
	printf("document_type :\n%s\n", cJSON_Print(jsondocument_type_1));
	document_type_t* document_type_2 = document_type_parseFromJSON(jsondocument_type_1);
	cJSON* jsondocument_type_2 = document_type_convertToJSON(document_type_2);
	printf("repeating document_type:\n%s\n", cJSON_Print(jsondocument_type_2));
}

int main() {
  test_document_type(1);
  test_document_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // document_type_MAIN
#endif // document_type_TEST
