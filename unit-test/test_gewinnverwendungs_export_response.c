#ifndef gewinnverwendungs_export_response_TEST
#define gewinnverwendungs_export_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gewinnverwendungs_export_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gewinnverwendungs_export_response.h"
gewinnverwendungs_export_response_t* instantiate_gewinnverwendungs_export_response(int include_optional);



gewinnverwendungs_export_response_t* instantiate_gewinnverwendungs_export_response(int include_optional) {
  gewinnverwendungs_export_response_t* gewinnverwendungs_export_response = NULL;
  if (include_optional) {
    gewinnverwendungs_export_response = gewinnverwendungs_export_response_create(
      "0",
      "0"
    );
  } else {
    gewinnverwendungs_export_response = gewinnverwendungs_export_response_create(
      "0",
      "0"
    );
  }

  return gewinnverwendungs_export_response;
}


#ifdef gewinnverwendungs_export_response_MAIN

void test_gewinnverwendungs_export_response(int include_optional) {
    gewinnverwendungs_export_response_t* gewinnverwendungs_export_response_1 = instantiate_gewinnverwendungs_export_response(include_optional);

	cJSON* jsongewinnverwendungs_export_response_1 = gewinnverwendungs_export_response_convertToJSON(gewinnverwendungs_export_response_1);
	printf("gewinnverwendungs_export_response :\n%s\n", cJSON_Print(jsongewinnverwendungs_export_response_1));
	gewinnverwendungs_export_response_t* gewinnverwendungs_export_response_2 = gewinnverwendungs_export_response_parseFromJSON(jsongewinnverwendungs_export_response_1);
	cJSON* jsongewinnverwendungs_export_response_2 = gewinnverwendungs_export_response_convertToJSON(gewinnverwendungs_export_response_2);
	printf("repeating gewinnverwendungs_export_response:\n%s\n", cJSON_Print(jsongewinnverwendungs_export_response_2));
}

int main() {
  test_gewinnverwendungs_export_response(1);
  test_gewinnverwendungs_export_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // gewinnverwendungs_export_response_MAIN
#endif // gewinnverwendungs_export_response_TEST
