#include <stdio.h>
#include <ruby.h>

static VALUE factorial(VALUE class, VALUE an_int_V) {

	int n = FIX2INT(an_int_V);

	// An int is too small, not safe, of course!
    int fact = 1;

    while (n > 1) {
      fact = fact * n;
       n = n - 1;
    }

	return INT2FIX(fact);
	
}

void Init_factorial_in_c() {
	
	// Create a Ruby module
	VALUE factorialModule = rb_define_module("FactorialModule");
	
	// Create a Ruby class in the module
	VALUE factorialClass = rb_define_class_under(factorialModule, "FactorialInC", rb_cObject);
	
	// Add a class method to the Ruby class
	int arg_count = 1;
	rb_define_module_function(factorialClass, "factorial", factorial, arg_count);

}