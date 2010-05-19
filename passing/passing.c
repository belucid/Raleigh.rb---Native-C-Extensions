#include <stdio.h>
#include <ruby.h>

static VALUE passString(VALUE class, VALUE a_string_V) {
	
	// Get the Ruby String into a C char array
	// 1.8
	//char* input = RSTRING(a_string_V)->ptr;
	
	//1.9
	char* input = RSTRING_PTR(a_string_V);
	printf("C sees: %s", input);
	
	// Reverse the string
	char temp;
	int i = 0;
	int j = strlen(input) - 1;
	for(; i<j; i++, j--) {
		temp = input[i];
		input[i] = input[j];
		input[j] = temp;
	}
	
	// Return a Ruby string from the C char array
	VALUE reverse = rb_str_new2(input);
	return reverse;
}

static VALUE passArray(VALUE class, VALUE an_array_V) {
	
	// Unpack the passed in array
	int i = 0;
	printf("C sees: ");
	for(; i < RARRAY_LEN(an_array_V); i++) {
		VALUE an_int_V = RARRAY_PTR(an_array_V)[i];
		int an_int = FIX2INT(an_int_V);
		printf("%i ", an_int);
	}
	printf("\n");

	// Build up an array of arrays to return
	VALUE return_array = rb_ary_new2(5);
	for (i=0;i<5;i++) {
		VALUE inner_array = rb_ary_new2(2);
		rb_ary_store(inner_array, 0, INT2FIX(i));
		rb_ary_store(inner_array, 1, INT2FIX(i+1));
		rb_ary_store(return_array, i, inner_array);
	}
	
	return return_array;

}

void Init_passing_in_c() {
	
	// Create a Ruby module
	VALUE passingModule = rb_define_module("PassingModule");
	
	// Create a Ruby class in the module
	VALUE passingClass = rb_define_class_under(passingModule, "PassingInC", rb_cObject);
	
	// Add a class method to the Ruby clas 
	int arg_count = 1;
	rb_define_module_function(passingClass, "pass_string", passString, arg_count);

	// Add a class method to the Ruby class
	arg_count = 1;
	rb_define_module_function(passingClass, "pass_array", passArray, arg_count);
	
}