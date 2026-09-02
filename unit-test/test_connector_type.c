#ifndef connector_type_TEST
#define connector_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define connector_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/connector_type.h"
connector_type_t* instantiate_connector_type(int include_optional);



connector_type_t* instantiate_connector_type(int include_optional) {
  connector_type_t* connector_type = NULL;
  if (include_optional) {
    connector_type = connector_type_create(
    );
  } else {
    connector_type = connector_type_create(
    );
  }

  return connector_type;
}


#ifdef connector_type_MAIN

void test_connector_type(int include_optional) {
    connector_type_t* connector_type_1 = instantiate_connector_type(include_optional);

	cJSON* jsonconnector_type_1 = connector_type_convertToJSON(connector_type_1);
	printf("connector_type :\n%s\n", cJSON_Print(jsonconnector_type_1));
	connector_type_t* connector_type_2 = connector_type_parseFromJSON(jsonconnector_type_1);
	cJSON* jsonconnector_type_2 = connector_type_convertToJSON(connector_type_2);
	printf("repeating connector_type:\n%s\n", cJSON_Print(jsonconnector_type_2));
}

int main() {
  test_connector_type(1);
  test_connector_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // connector_type_MAIN
#endif // connector_type_TEST
