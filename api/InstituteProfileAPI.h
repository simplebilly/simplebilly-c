#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/institute_profile.h"
#include "../model/institute_profile_update.h"
#include "../model/plugin_error.h"


// Current institute profile (created with defaults when missing).
//
institute_profile_t*
InstituteProfileAPI_getInstituteProfile(apiClient_t *apiClient);


// Update the institute profile (institute_type and/or kapitalmarktorientiert).
//
institute_profile_t*
InstituteProfileAPI_updateInstituteProfile(apiClient_t *apiClient, institute_profile_update_t *institute_profile_update);


