#ifndef gdpr_export_TEST
#define gdpr_export_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gdpr_export_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gdpr_export.h"
gdpr_export_t* instantiate_gdpr_export(int include_optional);

#include "test_gdpr_user.c"


gdpr_export_t* instantiate_gdpr_export(int include_optional) {
  gdpr_export_t* gdpr_export = NULL;
  if (include_optional) {
    gdpr_export = gdpr_export_create(
      list_createList(),
      list_createList(),
      list_createList(),
      "2013-10-20T19:20:30+01:00",
      1,
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_gdpr_user(0)
    );
  } else {
    gdpr_export = gdpr_export_create(
      list_createList(),
      list_createList(),
      list_createList(),
      "2013-10-20T19:20:30+01:00",
      1,
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      NULL
    );
  }

  return gdpr_export;
}


#ifdef gdpr_export_MAIN

void test_gdpr_export(int include_optional) {
    gdpr_export_t* gdpr_export_1 = instantiate_gdpr_export(include_optional);

	cJSON* jsongdpr_export_1 = gdpr_export_convertToJSON(gdpr_export_1);
	printf("gdpr_export :\n%s\n", cJSON_Print(jsongdpr_export_1));
	gdpr_export_t* gdpr_export_2 = gdpr_export_parseFromJSON(jsongdpr_export_1);
	cJSON* jsongdpr_export_2 = gdpr_export_convertToJSON(gdpr_export_2);
	printf("repeating gdpr_export:\n%s\n", cJSON_Print(jsongdpr_export_2));
}

int main() {
  test_gdpr_export(1);
  test_gdpr_export(0);

  printf("Hello world \n");
  return 0;
}

#endif // gdpr_export_MAIN
#endif // gdpr_export_TEST
