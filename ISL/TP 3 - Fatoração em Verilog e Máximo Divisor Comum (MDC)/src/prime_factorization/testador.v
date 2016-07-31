`timescale 1ns/100ps

/* Module to test your module fatorador */
module testador();

  // clock signal
  reg clock; 
  // number value tu be factorize       
  reg [15:0] value;  

  wire[6:0] hex0, hex1, hex2, hex3, hex4, hex5, hex6, hex7;

  // temp. values to print output
  reg[6:0] ohex0, ohex1, ohex2, ohex3, ohex4, ohex5, ohex6, ohex7;

  // 
  always
  begin
   # 10 clock = ~clock; // clock frecuency 10
  end

  always @(hex0, hex1, hex2, hex3, hex4, hex5, hex6, hex7) begin
    // task display used to convert to digit
    display(hex0, ohex0);
    display(hex1, ohex1);
    display(hex2, ohex2);
    display(hex3, ohex3);
    display(hex4, ohex4);
    display(hex5, ohex5);
    display(hex6, ohex6);
    display(hex7, ohex7);
    /*
      $display:
      This command prints a message on the screen when executed. 
      You can add a list of variables.The message must be declared in quotation marks (""),
      followed by the list of variables to be printed and the format.
       At the end of the message a carriage return is entered.
      Ex :      if ohex1 =0,ohex0=5
               $display("fator 1:",ohex1,ohex0); 
      output:
                   factor 1 : 0 5
    */
    $display("fator 1:",ohex1,ohex0);  
    $display("fator 2:",ohex3,ohex2);
    $display("fator 3:",ohex5,ohex4);
    $display("fator 4:",ohex7,ohex6);
  end

// ---------------------------------    display
/*
 Task to convert temp_in to number in ten base (temp_out)
*/
  task display;
  input [7:0] temp_in;    // input 
  output [7:0] temp_out;  // output (digit)
  begin
	  case(temp_in)
		  7'b1000000: temp_out = 0;
		  7'b1111001: temp_out = 1;
		  7'b0100100: temp_out = 2;
		  7'b0110000: temp_out = 3;
		  7'b0011001: temp_out = 4;
		  7'b0010010: temp_out = 5;
		  7'b0000010: temp_out = 6;
		  7'b1111000: temp_out = 7;
		  7'b0000000: temp_out = 8;
		  7'b0010000: temp_out = 9;
		  default: temp_out = -1;	
	  endcase
  end

  endtask
//---------------------------------------------------- end task
  initial begin
    clock = 0;
    value = 350;    // number to factorize
    #1000;
    value = 210;    // number to factorize
    #1000;
    value =  11;    // number to factorize
    #1000;
    value =  85;    // number to factorize
    #1000
    value =  5;     // number to factorize
    #1000
    value =  125;     // number to factorize
    #1000
    value =  115;     // number to factorize
    #1000
    value =  3;     // number to factorize
    #1000

    $finish;    // number to finish simulation
  end
  // module test

  fatorador_top f(clock, value, hex0, hex1, hex2, hex3, hex4, hex5, hex6, hex7);

  initial begin
    $dumpfile("fatorador_wave.vcd");
    $dumpvars;
  end 

/*-------------------------------
value = 350  
350 = 2 * 5^2 * 7

VSIM 11 >run
# fator 1:  0  2
# fator 2:  0  5
# fator 3:  0  7
# fator 4:  8  8

OUTPUT EXAMPLES

value = 210
210 = 2 * 3* 5* 7

VSIM 11 >run
# fator 1:  0  2
# fator 2:  0  3
# fator 3:  0  5
# fator 4:  0  7

//--------------------------------
value = 85  
85 = 5 * 17

VSIM 11 >run
# fator 1:  0  5
# fator 2:  1  7
# fator 3:  8  8
# fator 4:  8  8
-------------------------------*/
endmodule
