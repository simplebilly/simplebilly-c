#ifndef datev_import_response_TEST
#define datev_import_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define datev_import_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/datev_import_response.h"
datev_import_response_t* instantiate_datev_import_response(int include_optional);



datev_import_response_t* instantiate_datev_import_response(int include_optional) {
  datev_import_response_t* datev_import_response = NULL;
  if (include_optional) {
    datev_import_response = datev_import_response_create(
      0,
      "0",
      list_createList()
    );
  } else {
    datev_import_response = datev_import_response_create(
      0,
      "0",
      list_createList()
    );
  }

  return datev_import_response;
}


#ifdef datev_import_response_MAIN

void test_datev_import_response(int include_optional) {
    datev_import_response_t* datev_import_response_1 = instantiate_datev_import_response(include_optional);

	cJSON* jsondatev_import_response_1 = datev_import_response_convertToJSON(datev_import_response_1);
	printf("datev_import_response :\n%s\n", cJSON_Print(jsondatev_import_response_1));
	datev_import_response_t* datev_import_response_2 = datev_import_response_parseFromJSON(jsondatev_import_response_1);
	cJSON* jsondatev_import_response_2 = datev_import_response_convertToJSON(datev_import_response_2);
	printf("repeating datev_import_response:\n%s\n", cJSON_Print(jsondatev_import_response_2));
}

int main() {
  test_datev_import_response(1);
  test_datev_import_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // datev_import_response_MAIN
#endif // datev_import_response_TEST
