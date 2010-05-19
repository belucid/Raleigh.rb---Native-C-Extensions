#include <stdio.h>
#include <ruby.h>

static VALUE random_number(VALUE class, VALUE an_int_V) {
	int max = FIX2INT(an_int_V);
	return INT2FIX(rand() % max);
}

void Init_random_in_c() {
	
	// Create a Ruby module
	VALUE randomModule = rb_define_module("RandomModule");
	
	// Create a Ruby class in the module
	VALUE randomClass = rb_define_class_under(randomModule, "RandomInC", rb_cObject);
	
	// Add a class method to the Ruby class
	int arg_count = 1;
	rb_define_module_function(randomClass, "random_number", random_number, arg_count);

}