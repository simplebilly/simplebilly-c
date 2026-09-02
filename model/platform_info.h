/*
 * platform_info.h
 *
 * Public metadata for one registered plugin (admin UI). Maps 1:1 from [&#x60;plugin_core::PluginInfo&#x60;] (same field shape as before).
 */

#ifndef _platform_info_H_
#define _platform_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct platform_info_t platform_info_t;

#include "changelog_entry.h"
#include "config_field_info.h"
#include "plugin_pricing.h"



typedef struct platform_info_t {
    char *author; // string
    list_t *changelog; //nonprimitive container
    list_t *config_field_names; //primitive container
    list_t *config_fields; //nonprimitive container
    char *display_name; // string
    char *platform; // string
    struct plugin_pricing_t *pricing; //model
    list_t *supported_entities; //primitive container
    int *supports_export; //boolean
    int *supports_import; //boolean
    int *supports_oauth; //boolean
    char *version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} platform_info_t;

__attribute__((deprecated)) platform_info_t *platform_info_create(
    char *author,
    list_t *changelog,
    list_t *config_field_names,
    list_t *config_fields,
    char *display_name,
    char *platform,
    plugin_pricing_t *pricing,
    list_t *supported_entities,
    int *supports_export,
    int *supports_import,
    int *supports_oauth,
    char *version
);

void platform_info_free(platform_info_t *platform_info);

platform_info_t *platform_info_parseFromJSON(cJSON *platform_infoJSON);

cJSON *platform_info_convertToJSON(platform_info_t *platform_info);

#endif /* _platform_info_H_ */

