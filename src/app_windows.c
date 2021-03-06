#include "app_windows.h"
#include "app_widgets.h"

struct AppMainWindow 
create_main_window()
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Andy's Text Editor");
    gtk_window_set_position(GTK_WINDOW (window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW (window), 800, 600);

    GtkWidget *main_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    GtkWidget *notebook = gtk_notebook_new();

    GtkWidget *textarea = gtk_text_view_new();

    GtkWidget *scroll_window = gtk_scrolled_window_new(NULL, NULL);

    gtk_container_add(GTK_CONTAINER(scroll_window), textarea);
    
    GtkTextBuffer *buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (textarea));

    struct AppMainWindow mainWindow;
    mainWindow.window = window;
    mainWindow.editor_buffer = buffer;

    GtkWidget *menu_bar = create_menu_bar();

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook), GTK_POS_TOP);
    GtkWidget *label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(label), "<span foreground='red'>Page!</span>");
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), scroll_window, label);

    gtk_box_pack_start(GTK_BOX(main_vbox), menu_bar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(main_vbox), notebook, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(window), main_vbox);

    gtk_widget_show_all(window);

    return mainWindow;
}