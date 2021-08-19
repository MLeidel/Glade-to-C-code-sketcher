
// program

//#include "myclib.h"
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <unistd.h>

// Create global vars for gtk widgets

GtkWidget *g_obj_dialog_list;
GtkWidget *g_obj_dlg_listbox;
GtkWidget *g_obj_dlg_msgdlg;
GtkWidget *g_obj_window1;
GtkWidget *g_obj_searchtext;


//Signal Handler Functions 

void on_btn_dlg_close_clicked() {

}

void on_dlg_listbox_row_activated() {

}

void on_btn_dlg_msgdlg_close_clicked() {

}

void on_window1_destroy() {

}

void on_window1_key_press_event() {

}

void on_searchtext_activate() {

}

void on_btn_action_clicked() {

}


/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
/////////////////////////////////*/
int main(int argc, char *argv[]) {
    GtkBuilder      *builder;
    GtkWidget       *window1;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    //builder = gtk_builder_new_from_string (glade_xml, -1);
    gtk_builder_add_from_file (builder, "test.glade", NULL);

    window1 = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    gtk_builder_connect_signals(builder, NULL);

    // set GtkWidget Pointers to their builder objects
    // g_ = GTK_WIDGET(gtk_builder_get_object(builder, "WIDGET_ID"));
    // g_ = GTK_WIDGET(gtk_builder_get_object(builder, "WIDGET_ID"));

    g_obj_dialog_list = GTK_WIDGET(gtk_builder_get_object(builder, "dialog_list"));
    g_obj_dlg_listbox = GTK_WIDGET(gtk_builder_get_object(builder, "dlg_listbox"));
    g_obj_dlg_msgdlg = GTK_WIDGET(gtk_builder_get_object(builder, "dlg_msgdlg"));
    g_obj_window1 = window1;
    g_obj_searchtext = GTK_WIDGET(gtk_builder_get_object(builder, "searchtext"));


    g_object_unref(builder);

    gtk_widget_show(window1);
    gtk_main();

    return 0;
}


char* glade_xml = "\
<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\
<!-- Generated with glade 3.22.1 -->\n\
<interface>\n\
<requires lib=\"gtk+\" version=\"3.10\"/>\n\
<object class=\"GtkDialog\" id=\"dialog_list\">\n\
<property name=\"can_focus\">False</property>\n\
<property name=\"title\" translatable=\"yes\">...</property>\n\
<property name=\"default_width\">500</property>\n\
<property name=\"default_height\">400</property>\n\
<property name=\"type_hint\">dialog</property>\n\
<child>\n\
<placeholder/>\n\
</child>\n\
<child internal-child=\"vbox\">\n\
<object class=\"GtkBox\">\n\
<property name=\"can_focus\">False</property>\n\
<property name=\"orientation\">vertical</property>\n\
<property name=\"spacing\">2</property>\n\
<child internal-child=\"action_area\">\n\
<object class=\"GtkButtonBox\">\n\
<property name=\"can_focus\">False</property>\n\
<property name=\"layout_style\">end</property>\n\
<child>\n\
<placeholder/>\n\
</child>\n\
<child>\n\
<object class=\"GtkButton\" id=\"btn_dlg_close\">\n\
<property name=\"label\">gtk-close</property>\n\
<property name=\"visible\">True</property>\n\
<property name=\"can_focus\">True</property>\n\
<property name=\"receives_default\">True</property>\n\
<property name=\"use_stock\">True</property>\n\
<property name=\"always_show_image\">True</property>\n\
<signal name=\"clicked\" handler=\"on_btn_dlg_close_clicked\" swapped=\"no\"/>\n\
</object>\n\
<packing>\n\
<property name=\"expand\">True</property>\n\
<property name=\"fill\">True</property>\n\
<property name=\"position\">1</property>\n\
</packing>\n\
</child>\n\
</object>\n\
<packing>\n\
<property name=\"expand\">False</property>\n\
<property name=\"fill\">False</property>\n\
<property name=\"position\">0</property>\n\
</packing>\n\
</child>\n\
<child>\n\
<object class=\"GtkScrolledWindow\">\n\
<property name=\"visible\">True</property>\n\
<property name=\"can_focus\">True</property>\n\
<property name=\"shadow_type\">in</property>\n\
<child>\n\
<object class=\"GtkViewport\">\n\
<property name=\"visible\">True</property>\n\
<property name=\"can_focus\">False</property>\n\
<child>\n\
<object class=\"GtkListBox\" id=\"dlg_listbox\">\n\
<property name=\"visible\">True</property>\n\
<property name=\"can_focus\">False</property>\n\
<property name=\"hexpand\">True</property>\n\
<property name=\"vexpand\">True</property>\n\
<signal name=\"row-activated\" handler=\"on_dlg_listbox_row_activated\" swapped=\"no\"/>\n\
</object>\n\
</child>\n\
</object>\n\
</child>\n\
</object>\n\
<packing>\n\
<property name=\"expand\">False</property>\n\
<property name=\"fill\">True</property>\n\
<property name=\"position\">1</property>\n\
</packing>\n\
</child>\n\
</object>\n\
</child>\n\
</object>\n\
<object class=\"GtkMessageDialog\" id=\"dlg_msgdlg\">\n\
<property name=\"can_focus\">False</property>\n\
<property name=\"type_hint\">dialog</property>\n\
<property name=\"message_type\">other</property>\n\
<child>\n\
<placeholder/>\n\
</child>\n\
<child internal-child=\"vbox\">\n\
<object class=\"GtkBox\">\n\
<property name=\"can_focus\">False</property>\n\
<property name=\"orientation\">vertical</property>\n\
<property name=\"spacing\">2</property>\n\
<child internal-child=\"action_area\">\n\
<object class=\"GtkButtonBox\">\n\
<property name=\"can_focus\">False</property>\n\
<property name=\"homogeneous\">True</property>\n\
<property name=\"layout_style\">end</property>\n\
<child>\n\
<placeholder/>\n\
</child>\n\
<child>\n\
<object class=\"GtkButton\" id=\"btn_dlg_msgdlg_close\">\n\
<property name=\"label\">gtk-close</property>\n\
<property name=\"visible\">True</property>\n\
<property name=\"can_focus\">True</property>\n\
<property name=\"receives_default\">True</property>\n\
<property name=\"use_stock\">True</property>\n\
<property name=\"always_show_image\">True</property>\n\
<signal name=\"clicked\" handler=\"on_btn_dlg_msgdlg_close_clicked\" swapped=\"no\"/>\n\
</object>\n\
<packing>\n\
<property name=\"expand\">True</property>\n\
<property name=\"fill\">True</property>\n\
<property name=\"position\">1</property>\n\
</packing>\n\
</child>\n\
</object>\n\
<packing>\n\
<property name=\"expand\">False</property>\n\
<property name=\"fill\">False</property>\n\
<property name=\"position\">0</property>\n\
</packing>\n\
</child>\n\
</object>\n\
</child>\n\
</object>\n\
<object class=\"GtkWindow\" id=\"window1\">\n\
<property name=\"width_request\">100</property>\n\
<property name=\"can_focus\">False</property>\n\
<property name=\"title\" translatable=\"yes\">gsearch</property>\n\
<property name=\"skip_taskbar_hint\">True</property>\n\
<property name=\"decorated\">False</property>\n\
<property name=\"deletable\">False</property>\n\
<property name=\"has_resize_grip\">True</property>\n\
<signal name=\"destroy\" handler=\"on_window1_destroy\" swapped=\"no\"/>\n\
<signal name=\"key-press-event\" handler=\"on_window1_key_press_event\" swapped=\"no\"/>\n\
<child>\n\
<placeholder/>\n\
</child>\n\
<child>\n\
<object class=\"GtkBox\">\n\
<property name=\"visible\">True</property>\n\
<property name=\"can_focus\">False</property>\n\
<property name=\"margin_left\">2</property>\n\
<property name=\"margin_right\">2</property>\n\
<property name=\"margin_top\">1</property>\n\
<property name=\"margin_bottom\">1</property>\n\
<property name=\"hexpand\">True</property>\n\
<child>\n\
<object class=\"GtkEntry\" id=\"searchtext\">\n\
<property name=\"visible\">True</property>\n\
<property name=\"can_focus\">True</property>\n\
<property name=\"can_default\">True</property>\n\
<property name=\"opacity\">0.85098039215686272</property>\n\
<property name=\"hexpand\">True</property>\n\
<property name=\"has_frame\">False</property>\n\
<property name=\"placeholder_text\" translatable=\"yes\">help|list|hist|edit|sc|todo|&gt;http...</property>\n\
<signal name=\"activate\" handler=\"on_searchtext_activate\" swapped=\"no\"/>\n\
</object>\n\
<packing>\n\
<property name=\"expand\">False</property>\n\
<property name=\"fill\">True</property>\n\
<property name=\"position\">0</property>\n\
</packing>\n\
</child>\n\
<child>\n\
<object class=\"GtkButton\" id=\"btn_action\">\n\
<property name=\"label\" translatable=\"yes\">■</property>\n\
<property name=\"visible\">True</property>\n\
<property name=\"can_focus\">True</property>\n\
<property name=\"receives_default\">True</property>\n\
<property name=\"tooltip_text\" translatable=\"yes\">save clip or 'run'</property>\n\
<property name=\"always_show_image\">True</property>\n\
<signal name=\"clicked\" handler=\"on_btn_action_clicked\" swapped=\"no\"/>\n\
</object>\n\
<packing>\n\
<property name=\"expand\">False</property>\n\
<property name=\"fill\">True</property>\n\
<property name=\"padding\">1</property>\n\
<property name=\"position\">1</property>\n\
</packing>\n\
</child>\n\
</object>\n\
</child>\n\
</object>\n\
</interface>\n\
\0";

// builder = gtk_builder_new_from_string (glade_xml, -1);

