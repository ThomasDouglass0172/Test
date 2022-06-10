#include <string>
#include "VMTranslator.h"


using namespace std;
    static int count=0; 
/** Generate Hack Assembly code for a VM push operation assessed in Practical Assignment 6 */
string VMTranslator::vm_push(string segment, int offset){
    
    if (segment == "constant"){
    string res = ""; 

    res += "@"; 
    res += to_string(offset); 
    res +="\n"; 
    res += "D=A\n";
    res += "@SP\n";
    res += "A=M\n";
    res += "M=D\n";   //accesses memory of y
    res += "@SP\n";
    res += "M=M+1\n";
    return res;
    }
    else {
    string segmentLocation=""; 
    string res = "";

    if (segment == "local"){
        res +="@1\n";
        res += "D=M\n"; 
    }
    else if (segment == "argument"){
        res +="@2\n"; 
        res += "D=M\n";
    }
    else if (segment == "this"){
        res +="@3\n"; 
        res += "D=M\n";
    }
    else if (segment == "that"){
        res +="@4\n";
        res += "D=M\n"; 
    }
    else if (segment == "pointer"){
        if (offset>1){
            return res;
        }
        else {
            res +="@3\n"; 
            res += "D=A\n";
        }
    }
    else if (segment == "temp"){ 
        if (offset>7){
            return res; 
        }   
        res +="@5\n";  
        res += "D=A\n";   
    }
    else if (segment == "static"){
        res +="@16\n"; 
        res += "D=A\n";
    }

    res += "@"; 
    res += to_string(offset); 
    res +="\n"; 
    res += "A=D+A\n";
    res += "D=M\n";   //accesses memory of y
    res += "@SP\n"; 
    res += "A=M\n";
    res += "M=D\n";
    res += "@SP\n"; 
    res += "M=M+1\n";
    return res;  
    }
}

/** Generate Hack Assembly code for a VM pop operation assessed in Practical Assignment 6 */
string VMTranslator::vm_pop(string segment, int offset){ 
        string res = "";    
    if (segment == "constant"){
 

    res+="ERROR, cannot pop to constant"; 

    return res;
    }

    else {

    string segmentLocation=""; 

    if (segment == "local"){
        res +="@1\n";
        res += "D=M\n"; 
    }
    else if (segment == "argument"){
        res +="@2\n"; 
        res += "D=M\n";
    }
    else if (segment == "this"){
        res +="@3\n"; 
        res += "D=M\n";
    }
    else if (segment == "that"){
        res +="@4\n";
        res += "D=M\n"; 
    }
    else if (segment == "pointer"){
        if (offset>1){
            return res;
        }
        else {
            res +="@3\n"; 
            res += "D=A\n";
        }
    }
    else if (segment == "temp"){ 
        if (offset>7){
            return res; 
        }   
        res +="@5\n";  
        res += "D=A\n";   
    }
    else if (segment == "static"){
        res +="@16\n"; 
        res += "D=A\n";
    }
    res += "@"; 
    res += to_string(offset); 
    res +="\n";     
    res += "D=D+A\n";
    res += "@R13\n";   //accesses memory of y
    res += "M=D\n";
    res += "@SP\n"; 
    res += "AM=M-1\n";
    res += "D=M\n";
    res += "@R13\n";
    res += "A=M\n";
    res += "M=D\n";
    
    return res;  
    }
}

/** Generate Hack Assembly code for a VM add operation assessed in Practical Assignment 6 */
string VMTranslator::vm_add(){
    string res = ""; 

    res += "@SP\n"; 
    res += "AM=M-1\n";   
    res += "D=M\n";   //obtains x
    res += "A=A-1\n";   //accesses memory of y
    res += "M=M+D\n"; 

    return res;
}

/** Generate Hack Assembly code for a VM sub operation assessed in Practical Assignment 6 */
string VMTranslator::vm_sub(){
    string res = ""; 

    res += "@SP\n"; 
    res += "AM=M-1\n";   
    res += "D=M\n";   //obtains x
    res += "A=A-1\n";   //accesses memory of y
    res += "M=M-D\n"; 

    return res;
}

/** Generate Hack Assembly code for a VM neg operation assessed in Practical Assignment 6 */
string VMTranslator::vm_neg(){

    string res = ""; 

    res += "@SP\n"; 
    res += "A=M\n";
    res += "A=A-1\n";   //accesses memory of y
    res += "M=-M\n";

    return res;
}

/** Generate Hack Assembly code for a VM eq operation assessed in Practical Assignment 6 */
string VMTranslator::vm_eq(){
    string res = ""; 
    count++; 
    res += "@SP\n"; 
    res += "AM=M-1\n";   
    res += "D=M\n";   //obtains x
    res += "@SP\n"; 
    res += "AM=M-1\n";   //accesses memory of y
    res += "D=M-D\n";
    res += "@labelTrue";
    res += to_string(count);
    res += "\n";
    res += "D;JEQ\n"; 
    res += "D=0\n";
    res += "@labelFalse";
    res += to_string(count);
    res += "\n";
    res += "0;JMP\n";
    res += "(labelTrue";
    res += to_string(count);
    res += ")\n";
    res += "D=-1\n";
    res += "(labelFalse";
    res += to_string(count);
    res += ")\n";
    res += "@SP\n";
    res += "A=M\n";
    res += "M=D\n";
    res += "@SP\n";
    res += "M=M+1\n";

    return res;
}

/** Generate Hack Assembly code for a VM gt operation assessed in Practical Assignment 6 */
string VMTranslator::vm_gt(){
    string res = ""; 
    count++; 
    res += "@SP\n"; 
    res += "AM=M-1\n";   
    res += "D=M\n";   //obtains x
    res += "@SP\n"; 
    res += "AM=M-1\n";   //accesses memory of y
    res += "D=M-D\n";
    res += "@labelTrue";
    res += to_string(count);
    res += "\n";
    res += "D;JGT\n"; 
    res += "D=0\n";
    res += "@labelFalse";
    res += to_string(count);
    res += "\n";
    res += "0;JMP\n";
    res += "(labelTrue";
    res += to_string(count);
    res += ")\n";
    res += "D=-1\n";
    res += "(labelFalse";
    res += to_string(count);
    res += ")\n";
    res += "@SP\n";
    res += "A=M\n";
    res += "M=D\n";
    res += "@SP\n";
    res += "M=M+1\n";

    return res;
}

/** Generate Hack Assembly code for a VM lt operation assessed in Practical Assignment 6 */
string VMTranslator::vm_lt(){
    string res = ""; 
    count++; 
    res += "@SP\n"; 
    res += "AM=M-1\n";   
    res += "D=M\n";   //obtains x
    res += "@SP\n"; 
    res += "AM=M-1\n";   //accesses memory of y
    res += "D=M-D\n";
    res += "@labelTrue";
    res += to_string(count);
    res += "\n";
    res += "D;JLT\n"; 
    res += "D=0\n";
    res += "@labelFalse";
    res += to_string(count);
    res += "\n";
    res += "0;JMP\n";
    res += "(labelTrue";
    res += to_string(count);
    res += ")\n";
    res += "D=-1\n";
    res += "(labelFalse";
    res += to_string(count);
    res += ")\n";
    res += "@SP\n";
    res += "A=M\n";
    res += "M=D\n";
    res += "@SP\n";
    res += "M=M+1\n";

    return res;
}

/** Generate Hack Assembly code for a VM and operation assessed in Practical Assignment 6 */
string VMTranslator::vm_and(){
    string res = ""; 

    res += "@SP\n"; 
    res += "AM=M-1\n"; 
    res += "D=M\n"; 
    res += "A=A-1\n"; 
    res += "M=D&M\n"; 
    
    return res;


}

/** Generate Hack Assembly code for a VM or operation assessed in Practical Assignment 6 */
string VMTranslator::vm_or(){
    string res = ""; 

    res += "@SP\n";     
    res += "AM=M-1\n"; 
    res += "D=M\n"; 
    res += "A=A-1\n"; 
    res += "M=D|M\n";   

    return res;
}

/** Generate Hack Assembly code for a VM not operation assessed in Practical Assignment 6 */
string VMTranslator::vm_not(){
    string res = ""; 

    res += "@SP\n"; 
    res += "A=M\n"; 
    res += "A=A-1\n"; 
    res += "M=!M\n";

    return res;
}

/** Generate Hack Assembly code for a VM label operation assessed in Practical Assignment 7 */
string VMTranslator::vm_label(string label){
    return "";
}

/** Generate Hack Assembly code for a VM goto operation assessed in Practical Assignment 7 */
string VMTranslator::vm_goto(string label){
    return "";
}

/** Generate Hack Assembly code for a VM if-goto operation assessed in Practical Assignment 7 */
string VMTranslator::vm_if(string label){
    return "";
}

/** Generate Hack Assembly code for a VM function operation assessed in Practical Assignment 7 */
string VMTranslator::vm_function(string function_name, int n_vars){
    return "";
}

/** Generate Hack Assembly code for a VM call operation assessed in Practical Assignment 7 */
string VMTranslator::vm_call(string function_name, int n_args){
    return "";
}

/** Generate Hack Assembly code for a VM return operation assessed in Practical Assignment 7 */
string VMTranslator::vm_return(){
    return "";
}