
/*******************************************************************************
* This file was generated by UI Builder.
* This file will be auto-generated each and everytime you save your project.
* Do not hand edit this file.
********************************************************************************/

#ifndef UIB_VIEWS_H_
#define UIB_VIEWS_H_

#include "g_inc_uib.h"

#define	KEY_VIEW_CONTEXT	"uib,view,context"
#define	KEY_VIEW_CREATE		"uib,view,create"
#define	KEY_VIEW_DESTROY	"uib,view,destroy"
#define	KEY_VIEW_VC_SAVE	"uib,view,vc_save" 
#define	KEY_WM_ROTATION_CHANGED	"wm,rotation,changed"

typedef struct
{
	Evas_Object * win;
	Evas_Object * bg;
	Evas_Object * conformant;
	Evas_Object * layout;
	Evas_Object * app_naviframe;
} window_obj;

typedef struct _uib_view_context
{
	Evas_Object* 	parent;
	Evas_Object* 	root_container;
	const char*  	view_name;
} uib_view_context;

typedef struct {
	bool is_init;

	void (*uib_view_target_config_portrait)();
	void (*uib_view_target_config_landscape)();

	uib_view_context* (*startup_view_create)(window_obj*);
	void (*set_targeted_view)(const char*);
	window_obj* (*create_window_obj)();
	window_obj* (*get_window_obj)();
	Evas_Object* (*get_window)();
	Evas_Object* (*get_conformant)();
	void (*destroy_window_obj)();
	void (*uib_views_current_view_redraw) ();
	char* (*get_current_config_name) ();
	void (*uib_views_orientation_handler)(int, Evas_Object*);

} uib_views_st;

/**
 * Set the member using strdup() or malloc() because it will be deleted by free().
 */
 typedef struct _uib_genlist_item
{
	char * label;
	char * sub_label;
	char * icon_path;
	char * icon_standard;
	char * end_icon_path;
	char * end_icon_standard;
} uib_genlist_item;

/**
 * Set the member using strdup() or malloc() because it will be deleted by free().
 */
typedef struct _uib_gengrid_item
{
	char * label;
	char * icon_path;
} uib_gengrid_item;


/**
 * @brief Call a callback on view creation
 * @param[in]   vc 			view context
 * @param[in]   obj			The root container widget of this view
 * @param[in]   event_info	pointer to an event specific struct or information to pass to the callback functions registered on this event
 */
void uib_views_create_callback(void* vc, Evas* e, Evas_Object* obj, void* event_info) ;


/**
 * @brief Call a callback on view termination
 * @param[in]   vc 			view context
 * @param[in]   obj			The root container widget of this view
 * @param[in]   event_info	pointer to an event specific struct or information to pass to the callback functions registered on this event
 */
void uib_views_destroy_callback(void* vc, Evas* e, Evas_Object* obj, void* event_info) ;

void win_destroy(window_obj *win_obj);

Evas_Object* get_window();
Evas_Object* get_conformant();

uib_views_st* uib_views_get_instance();

/**
 * @brief Item class for gengrid item
 */
extern Elm_Gengrid_Item_Class* Uib_Gengrid_Itc;

/**
 * @brief Item class for genlist item
 */
extern Elm_Gengrid_Item_Class* Uib_Genlist_Itc;

/**
 * @brief Initialize the gengrid item class
 */
void initialize_gengrid_class(const char*);

/**
 * @brief Initialize the genlist item class
 */
void initialize_genlist_class(const char*);

/**
 * @brief Create Item for multibuttonentry
 * @param[in]   multibuttonentry     item container
 * @param[in]   label    item label
 * @param[in]   func     callback function to be called when item is selected
 * @param[in]   data     data to be transferred to the callback function
 * @returns created item
 */
Elm_Object_Item* create_multibuttonentry_item(Evas_Object* multibuttonentry, const char* label, Evas_Smart_Cb func, void* data);

/**
 * @brief Create Item for gengrid
 * @param[in]   gengrid     item container
 * @param[in]   style    item style
 * @param[in]   label    item label
 * @param[in]   path     resource path such as location of the image
 * @param[in]   func     callback function to be called when item is selected
 * @param[in]   data     data to be transferred to the callback function
 * @returns created item
 */
Elm_Object_Item* create_gengrid_item(Evas_Object* gengrid, const char* style, const char* label, const char* path, Evas_Smart_Cb func, void* data);


/**
 * @brief Create Item for genlist
 * @param[in]   gengrid            item container
 * @param[in]   label              item label
 * @param[in]   sub_label          item sub label
 * @param[in]   icon_path          resource path such as location of the image
 * @param[in]   icon_standard      standard icon name
 * @param[in]   end_icon_path      resource path such as location of the image
 * @param[in]   end_icon_standard  standard icon name
 * @param[in]   parent             parent item used in tree item type
 * @param[in]   type               item type: tree, group, none
 * @param[in]   func               callback function to be called when item is selected
 * @param[in]   data               data to be transferred to the callback function
 * @returns created item
 */
Elm_Object_Item* create_genlist_item(Evas_Object* genlist, const char* label, const char* sub_label, const char* icon_path, const char* icon_standard, const char* end_icon_path, const char* end_icon_standard, Elm_Object_Item* parent, Elm_Genlist_Item_Type type, Evas_Smart_Cb func, void* data);


#endif /* UIB_VIEWS_H_ */


