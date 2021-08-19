/*
	Sketcher to build a "c" source file from Glade file
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var code1 string = `
// program

//#include "myclib.h"
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <unistd.h>

// Create global vars for gtk widgets
`
var code2 string = `
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
/////////////////////////////////*/
int main(int argc, char *argv[]) {
    GtkBuilder      *builder;
    GtkWidget       *window1;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    //builder = gtk_builder_new_from_string (glade_xml, -1);
    gtk_builder_add_from_file (builder, "XXXXXX", NULL);

    window1 = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    gtk_builder_connect_signals(builder, NULL);

    // set GtkWidget Pointers to their builder objects
    // g_ = GTK_WIDGET(gtk_builder_get_object(builder, "WIDGET_ID"));
    // g_ = GTK_WIDGET(gtk_builder_get_object(builder, "WIDGET_ID"));
`

var code3 string = ""

var code4 string = `
    g_object_unref(builder);

    gtk_widget_show(window1);
    gtk_main();

    return 0;
}

`

type wobjs struct {
	class string
	id    string
}

var objs []wobjs  // a slice of widget objects to obs
var sigs []string // a slice of signal handlers to item

func main() {

	if len(os.Args) < 2 {
		fmt.Println("\nGolace - a sketcher for Glade to C")
		fmt.Println("uses standard output to console")
		fmt.Println("Specify Glade file as argument\n")
		os.Exit(1)
	}

	gladefile := os.Args[1]

	f, err := os.Open(gladefile) // open the glade xml file
	check(err)
	defer f.Close()
	scanner := bufio.NewScanner(f)
	o := wobjs{}         // create variable to the wobjs struct
	for scanner.Scan() { // process line by line
		line := scanner.Text()
		if strings.Contains(line, " id=") {
			pline := strings.Fields(line)
			class := strings.Split(pline[1], "\"")
			id := strings.Split(pline[2], "\"")
			o.class = class[1]
			o.id = id[1]
			objs = append(objs, o)
		}
		if strings.Contains(line, " handler=") {
			pline := strings.Fields(line)
			handl := strings.Split(pline[2], "\"")
			sigs = append(sigs, handl[1])
		}
	}
	check(scanner.Err())

	// Output begins here

	fmt.Println(code1)

	// Widget Globals
	for _, k := range objs {
		if !strings.Contains(k.class, "GtkButton") {
			fmt.Println("GtkWidget *g_obj_" + k.id + ";")
		}
	} // end for

	fmt.Println("\n\n//Signal Handler Functions \n")

	// Handler function bodies
	for _, k := range sigs {
		// handlers
		fmt.Println("void " + k + "() {\n\n}\n")
	}

	code2 = strings.Replace(code2, "XXXXXX", gladefile, 1)
	fmt.Println(code2)

	// Gather the Global type assertions
	for _, k := range objs {
		if !strings.Contains(k.class, "GtkButton") {
			if strings.Contains(k.class, "GtkWindow") {
				code3 += "    g_obj_window1 = window1;\n"
			} else {
				code3 += "    g_obj_" + k.id + " = GTK_WIDGET(gtk_builder_get_object(builder, \"" + k.id + "\"));\n"
			}
		}
	}

	fmt.Println(code3) // Global type assertions

	fmt.Println(code4) // End of main function

	// Put the glade xml into a "C" string
	// to (optionally) load from string instead of file
	xml2string(gladefile)
}

func check(e error) {
	if e != nil {
		// panic for any errors.
		panic(e)
	}
}

func xml2string(gladefile string) {

	var line string
	var out string
	s := make([]string, 0) // a slice of widget objects to obs
	dq := "\""
	ddq := "\\\""
	endline := "\\n\\"

	f, err := os.Open(gladefile)
	check(err)
	defer f.Close()
	scanner := bufio.NewScanner(f)
	for scanner.Scan() {
		line = scanner.Text()
		s = append(s, line)
	}

	fmt.Println("char* glade_xml = \"\\")

	for _, line = range s {
		out = strings.Trim(line, " \n")
		out = strings.Replace(out, dq, ddq, -1)
		out += endline
		fmt.Println(out)
	}
	fmt.Println("\\0\";\n")
	fmt.Println("// builder = gtk_builder_new_from_string (glade_xml, -1);\n")
}
