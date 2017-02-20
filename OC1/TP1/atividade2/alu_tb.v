`include "utils.vh"
`timescale 1ns/100ps // `timescale <unit>/<precision>

module alu_tb;

  reg [`CPU_WSIZE-1:0] a;
  reg [`CPU_WSIZE-1:0] b;
  reg [`ALU_OSIZE-1:0] op;

  wire zero, ovf;   
  wire[`CPU_WSIZE-1:0] r;
  
  integer i, j, ax, bx, rx, zerox, ovfz, er;

  initial begin
    op = 2;
    for(i = 0; i < 256; i = i + 1) begin
      for(j = 0; j < 256; j = j + 1) begin
        a = i[`CPU_WSIZE-1:0];
        b = j[`CPU_WSIZE-1:0];
        #1 $display("op=%d a=%d b=%d r=%d zero:%d", op, a, b, r, zero); 
        //if(r != (i + j)) begin
        // #1 $display("deu merda!"); 
        //end       
      end
    end
    $finish; 
  end

  initial begin
    $dumpfile("alu_tb.vcd");
    $dumpvars;
  end 

  alu alu_dut(r, zero, ovf, op, a, b);
endmodule
