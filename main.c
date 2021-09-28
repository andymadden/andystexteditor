#include <string.h>
#include <json-c/json_object.h>
#include <json-c/json_tokener.h>
#include "fileio.h"
#include "app_windows.h"

int
main(int argc,
     char *argv[])
{
    struct FileData json_file = read_file("test.json");

    gtk_init(&argc, &argv);

    struct AppMainWindow mainWindow = create_main_window();

    gtk_text_buffer_set_text(mainWindow.editor_buffer, json_file.buffer, strlen(json_file.buffer));

    gtk_main();

    return 0;
}