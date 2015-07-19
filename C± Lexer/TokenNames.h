#pragma once
#include <string>
using namespace std;

//program
const string * const TOKEN_PROGRAM = new string("program");
const string * const TOKEN_IMPORT_STATEMENT = new string("import_statement");
const string * const TOKEN_FUNCTION_STATEMENT = new string("function_statement");
const string * const TOKEN_CLASS_DEFINITION = new string("class_definition");
const string * const TOKEN_CLASS_STATEMENT = new string("class_statement");

//import statement
const string * const TOKEN_IMPORT = new string("import");
const string * const TOKEN_STRING_LITERAL = new string("string_literal");
const string * const TOKEN_SEMI_COLON = new string("semi_colon");

//function statement
const string * const TOKEN_VARIABLE_DECLARATION = new string("variable_declaration");
const string * const TOKEN_ASSIGNMENT_STATEMENT = new string("assignment_statement");
const string * const TOKEN_RETURN_STATEMENT = new string("return_statement");
const string * const TOKEN_EXPRESSION = new string("expression");
const string * const TOKEN_LOOP = new string("loop");
const string * const TOKEN_CONDITIONAL = new string("conditional");

//variable declaration
const string * const TOKEN_TYPE = new string("type");
const string * const TOKEN_ID = new string("id");

//type
const string * const TOKEN_PRIMITIVE_TYPE = new string("primitive_type");
const string * const TOKEN_ARRAY_TYPE = new string("array_type");

//primitive type
const string * const TOKEN_INT_TYPE = new string("int_type");
const string * const TOKEN_DOUBLE_TYPE = new string("double_type");
const string * const TOKEN_CHAR_TYPE = new string("char_type");
const string * const TOKEN_BOOLEAN_TYPE = new string("boolean_type");
const string * const TOKEN_VOID_TYPE = new string("void_type");

//array type
const string * const TOKEN_OPEN_BRACKET = new string("open_bracket");
const string * const TOKEN_CLOSE_BRACKET = new string("close_bracket");

//assignment statement
const string * const TOKEN_ASSIGNMENT_OPERATOR = new string("assignment_operator");

//expression
const string * const TOKEN_VALUE = new string("value");
const string * const TOKEN_INSTANTIATION = new string("instantiation");
const string * const TOKEN_OPEN_PARAN = new string("open_paran");
const string * const TOKEN_CLOSE_PARAN = new string("close_paran");
const string * const TOKEN_PREUNARY_OPERATOR = new string("preunary_operator");
const string * const TOKEN_POSTUNARY_OPERATOR = new string("postunary_operator");
const string * const TOKEN_BINARY_OPERATOR = new string("binary_operator");
const string * const TOKEN_QUESTION = new string("question_mark");
const string * const TOKEN_COLON = new string("colon");

//value
const string * const TOKEN_NULL = new string("null");
const string * const TOKEN_SUPER = new string("super");
const string * const TOKEN_THIS = new string("this");
const string * const TOKEN_PRIMITIVE_LITERAL = new string("primitive_literal");
const string * const TOKEN_FUNCTION_CALL = new string("function_call");

//primitive literal
const string * const TOKEN_INT_LITERAL = new string("int_literal");
const string * const TOKEN_DOUBLE_LITERAL = new string("double_literal");
const string * const TOKEN_CHAR_LITERAL = new string("char_literal");
const string * const TOKEN_BOOLEAN_LITERAL = new string("boolean_literal");

//function call
const string * const TOKEN_PARAMETER_LIST_OPT = new string("param_list_opt");

//parameter list opt
const string * const TOKEN_PARAMETER_LIST = new string("param_list");

//parameter list
const string * const TOKEN_PARAMETER = new string("param");
const string * const TOKEN_COMMA = new string("comma");

//instantiation
const string * const TOKEN_NEW = new string("new");

//PreUnary Operator
const string * const TOKEN_BANG = new string("!");

//PostUnary Operator
const string * const TOKEN_PLUSPLUS = new string("++");
const string * const TOKEN_MINUSMINUS = new string("--");

//Binary Operator
const string * const TOKEN_PLUS = new string("+");
const string * const TOKEN_MINUS = new string("-");
const string * const TOKEN_MULTIPLY = new string("*");
const string * const TOKEN_DIVIDE = new string("/");
const string * const TOKEN_MOD = new string("%");
const string * const TOKEN_POWER = new string("**");
const string * const TOKEN_IS_EQUALS = new string("==");
const string * const TOKEN_IS_GREATER_THAN_OR_EQUALS = new string(">=");
const string * const TOKEN_IS_GREATER_THAN = new string(">");
const string * const TOKEN_IS_LESS_THAN_OR_EQUALS = new string("<=");
const string * const TOKEN_IS_LESS_THAN = new string("<");
const string * const TOKEN_IS_NOT_EQUALS = new string("!=");
const string * const TOKEN_AND = new string("&&");
const string * const TOKEN_OR = new string("||");
const string * const TOKEN_INSTANCEOF = new string("instanceof");
const string * const TOKEN_XOR = new string("xor");
const string * const TOKEN_ACCESS_OPERATOR = new string(".");

//return statement
const string * const TOKEN_RETURN = new string("return");

//loop
const string * const TOKEN_FOR_LOOP = new string("for_loop");
const string * const TOKEN_WHILE_LOOP = new string("while_loop");

//for loop
const string * const TOKEN_FOR = new string("for");
const string * const TOKEN_ASSIGNMENT_STATEMENT_OPT = new string("assignment_statement_opt");
const string * const TOKEN_EXPRESSION_OPT = new string("expression_opt");
const string * const TOKEN_OPEN_BRACE = new string("open_brace");
const string * const TOKEN_FUNCTION_STATEMENTS = new string("function_statements");
const string * const TOKEN_CLOSE_BRACE = new string("close_brace");
const string * const TOKEN_IN = new string("in");

//while loop
const string * const TOKEN_WHILE = new string("while");

//conditional
const string * const TOKEN_IF = new string("if");
const string * const TOKEN_ELSE = new string("else");
	
//class definition
const string * const TOKEN_CLASS = new string("class");
const string * const TOKEN_CLASS_BLOCK = new string("class_block");
const string * const TOKEN_PARTIAL = new string("partial");

//class block
const string * const TOKEN_CLASS_STATEMENTS = new string("class_statements");

//class statements
const string * const TOKEN_CLASS_STATEMENT_OR_CONSTRUCTOR = new string("class_statement_or_constructor");

//class statement or constructor
const string * const TOKEN_CONSTRUCTOR = new string("constructor");

//class statement
const string * const TOKEN_FUNCTION_DEFINITION = new string("function_definition");
const string * const TOKEN_FUNCTION = new string("function");
const string * const TOKEN_PARAMETER_DEFINITION_LIST_OPT = new string("parameter_definition_list_opt");

//parameter definition list opt
const string * const TOKEN_PARAMETER_DEFINITION_LIST = new string("parameter_definition_list");

//parameter definition list
const string * const TOKEN_PARAMETER_DEFINITION = new string("parameter_definition");

//Constructor
const string * const TOKEN_FUNCTION_STATEMENTS_OPT = new string("function_statements_opt");