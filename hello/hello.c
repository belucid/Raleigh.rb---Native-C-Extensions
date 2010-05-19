#include <stdio.h>
#include <ruby.h>

static VALUE hello() {
	printf("raleigh.rb\n");
	return Qnil;
}

void Init_hello_in_c() {
	
	// Create a Ruby module
	VALUE helloModule = rb_define_module("HelloModule");
	
	// Create a Ruby class in the module
	VALUE helloClass = rb_define_class_under(helloModule, "HelloInC", rb_cObject);
	
	// Add a class method to the Ruby class
	int arg_count = 0;
	rb_define_module_function(helloClass, "hello", hello, arg_count);

}