

/*******************************************************************************
* This file was generated by UI Builder.
* This file will be auto-generated each and everytime you save your project.
* Do not hand edit this file.
********************************************************************************/

#include "app_main.h"
#include "uib_util.h"
#include "uib_views.h"
#include "uib_views_inc.h"
#include "uib_app_manager.h"

#define RM_ANNOTATION_LOCALE "@locale/"
#define RM_ANNOTATION_RESOURCE "@resource/"
#define RM_ANNOTATION_LOCALE_LEN strlen(RM_ANNOTATION_LOCALE)
#define RM_ANNOTATION_RESOURCE_LEN strlen(RM_ANNOTATION_RESOURCE)

void uib_util_rotation_set(Evas_Object *win, rotation_e e_rotation_type) {
	if(elm_win_wm_rotation_supported_get(win)) {
		switch(e_rotation_type) {
		case e_rotation_onlyPortrait: {
			int rots[] = DEF_SENSOR_ARRAY_ONLY_PORT;
			elm_win_wm_rotation_available_rotations_set(win, (const int*) (&rots), sizeof(rots)/sizeof(int));
		}
			break;
		case e_rotation_onlyLandscape: {
			int rots[] = DEF_SENSOR_ARRAY_ONLY_LAND;
			elm_win_wm_rotation_available_rotations_set(win, (const int*) (&rots), sizeof(rots)/sizeof(int));
		}
			break;
		case e_rotation_fullSensor: {
			int rots[] = DEF_SENSOR_ARRAY_FULL;
			elm_win_wm_rotation_available_rotations_set(win, (const int*) (&rots), sizeof(rots)/sizeof(int));
		}
			break;
		case e_rotation_noSensor: {
			int rots[] = DEF_SENSOR_ARRAY_NO;
			elm_win_wm_rotation_available_rotations_set(win, (const int*) (&rots), sizeof(rots)/sizeof(int));
		}
		  break;			
		default:
			break;
		}
	}
}

resolution_e uib_util_get_resolution_type(int w, int h) {
	if((w==800 && h==480) || (w==480 && h==800))
		return e_resolution_WVGA;
	else if((w==960 && h==540) || (w==540 && h==960))
		return e_resolution_qHD;
	else if((w==1280 && h==720) || (w==720 && h==1280))
		return e_resolution_HD;
	else
		return e_resolution_unknown;
}

int uib_util_get_device_info(uib_device_info_st* uib_device_info ) {
	if(!uib_device_info){
		return -1;
	}
	
	strcpy(uib_device_info->profile_name, elm_config_profile_get());
	system_info_get_platform_int("tizen.org/feature/screen.width", &uib_device_info->w);
	system_info_get_platform_int("tizen.org/feature/screen.height", &uib_device_info->h);
	system_info_get_platform_int("tizen.org/feature/screen.dpi", &uib_device_info->dpi);

	double profile_factor = (!strcmp(uib_device_info->profile_name, "mobile"))? 0.7 : 0.4;
	uib_device_info->base_scale = uib_device_info->dpi / 90 * profile_factor;

	uib_device_info->resolution_type = uib_util_get_resolution_type(uib_device_info->w, uib_device_info->h);

	return 0;
}

Elm_Object_Item* uib_util_push_view(char *view_name) {
	Evas_Object* app_nf = uib_views_get_instance()->get_window_obj()->app_naviframe;
	uib_view_context* vc=NULL;
	
	if(!strcmp(view_name,"view1")) {
		vc = uib_view_view1_create(app_nf, NULL);
	}
	Elm_Object_Item* elm_obj_item = elm_naviframe_item_push(app_nf, "", NULL, NULL, vc->root_container, NULL);
	elm_naviframe_item_title_enabled_set (elm_obj_item, EINA_FALSE, EINA_FALSE);
	return elm_obj_item;
}

char* uib_util_get_current_config_name() {
	return uib_views_get_instance()->get_current_config_name();
}

void uib_util_widget_hide_on_grid(Evas_Object* grid_evas_obj, Evas_Object* evas_sub_obj) {
	elm_grid_pack(grid_evas_obj, evas_sub_obj, -100, -100, 0, 0);
}

char* uib_util_rm_get_locale_string(char* src_string) {
	char* locale_string=NULL;
	if((src_string==NULL) || (strlen(src_string)<1)) {
		return NULL;
	}
	if(!strncasecmp(RM_ANNOTATION_LOCALE, src_string, RM_ANNOTATION_LOCALE_LEN)) { // matching
		locale_string = _(src_string+RM_ANNOTATION_LOCALE_LEN); // i18n_get_text
	}
	else {
		locale_string = src_string;
	}
  
	return locale_string;
}

int uib_util_rm_get_resource_path(_APP_RESOURCE_E e_resource_type, const char* resource_path_in, char** resource_path_out) {
	int ret=0;
	if((resource_path_in==NULL) || (strlen(resource_path_in)<1)) {
		return 0;
	}

	if(!strncasecmp(RM_ANNOTATION_RESOURCE, resource_path_in, RM_ANNOTATION_RESOURCE_LEN)) { // matching
		ret = app_resource_manager_get(e_resource_type, resource_path_in+RM_ANNOTATION_RESOURCE_LEN, resource_path_out);
	}
	else {
		char *res_path = app_get_resource_path();
		int resource_path_out_size = strlen(resource_path_in)+strlen(res_path) + 1;
		*resource_path_out = (char*) malloc(resource_path_out_size);
		if (resource_path_out) {
			sprintf(*resource_path_out, "%s%s", res_path, resource_path_in);
			free(res_path);
		}
	}	
		
	return ret;
}