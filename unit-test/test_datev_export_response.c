#ifndef datev_export_response_TEST
#define datev_export_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define datev_export_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/datev_export_response.h"
datev_export_response_t* instantiate_datev_export_response(int include_optional);



datev_export_response_t* instantiate_datev_export_response(int include_optional) {
  datev_export_response_t* datev_export_response = NULL;
  if (include_optional) {
    datev_export_response = datev_export_response_create(
      0,
      "0",
      "0"
    );
  } else {
    datev_export_response = datev_export_response_create(
      0,
      "0",
      "0"
    );
  }

  return datev_export_response;
}


#ifdef datev_export_response_MAIN

void test_datev_export_response(int include_optional) {
    datev_export_response_t* datev_export_response_1 = instantiate_datev_export_response(include_optional);

	cJSON* jsondatev_export_response_1 = datev_export_response_convertToJSON(datev_export_response_1);
	printf("datev_export_response :\n%s\n", cJSON_Print(jsondatev_export_response_1));
	datev_export_response_t* datev_export_response_2 = datev_export_response_parseFromJSON(jsondatev_export_response_1);
	cJSON* jsondatev_export_response_2 = datev_export_response_convertToJSON(datev_export_response_2);
	printf("repeating datev_export_response:\n%s\n", cJSON_Print(jsondatev_export_response_2));
}

int main() {
  test_datev_export_response(1);
  test_datev_export_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // datev_export_response_MAIN
#endif // datev_export_response_TEST
