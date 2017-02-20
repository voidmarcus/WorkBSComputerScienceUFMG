`include "utils.vh"
`timescale 1ns/100ps // `timescale <unit>/<precision>

module alu_tb;
  reg [`CPU_WSIZE-1:0] a;
  reg [`CPU_WSIZE-1:0] b;
  reg [`ALU_OSIZE:0] op;

  wire zer, ovf;   
  wire[`CPU_WSIZE-1:0] r;
  
  integer i, j, k, ax, bx, rx, zerox, ovfz, er;
  reg[`ALU_OSIZE:0] op_arr [6:0];
  initial begin
    op_arr[0] = `ALU_AND_OP;
    op_arr[1] = `ALU_OR_OP;
    op_arr[2] = `ALU_ADD_OP;
    op_arr[3] = `ALU_SUB_OP;
    op_arr[4] = `ALU_SLT_OP;
    op_arr[5] = `ALU_LUI_OP;
    op_arr[6] = `ALU_NOR_OP;

    for(i = 0; i < (2<<`CPU_WSIZE); i = i + 1) begin
      a = i[`CPU_WSIZE-1:0];
      for(j = 0; j < (2<<`CPU_WSIZE); j = j + 1) begin
        b = j[`CPU_WSIZE-1:0];
        for(k = 0; k < 7; k = k + 1) begin
          op = op_arr[k];
          #5;
          case(op)
            `ALU_AND_OP: begin
              if(r != (a & b)) begin
                $display("alu error: 'and' operation: %h - operands: %h %h result: %h expected: %h", op, a, b, r, a & b);
                $finish;
              end
            end

            `ALU_OR_OP: begin
              if(r != (a | b)) begin
                $display("alu error: 'or' operation: %h - operands: %h %h result: %h expected: %h", op, a, b, r, a | b);
                $finish;
              end
            end

            `ALU_ADD_OP: begin
              if(r != (a + b)) begin
                $display("alu error: 'add' operation: %h - operands: %h %h result: %h expected: %h", op, a, b, r, a + b);
                $finish;
              end
            end

            `ALU_SUB_OP: begin
              if(r != (a - b)) begin
                $display("alu error: 'sub' operation: %h - operands: %h %h result: %h expected?: %h", op, a, b, r, a - b);
                $finish;
              end
            end

            `ALU_SLT_OP: begin
//              if(r[1:0] != ($signed(a) < $signed(b) ? 1 : 0)) begin
              if(r[1:0] != (a < b ? 1 : 0)) begin
                $display("alu error: 'slt' operation: %h - operands: %h %h result: %h expected: %h", op, a, b, r[1:0], a < b ? 1 : 0);
                $finish;
              end
            end

            `ALU_LUI_OP: begin
              if(r != (a << `CPU_HSIZE)) begin
                $display("alu error: 'lui' operation: %h - operands: %h %h result: %h expected: %h", op, a, b, r, a << `CPU_HSIZE);
                $finish;
              end
            end

            `ALU_NOR_OP: begin
              if(r != ~(a | b)) begin
                $display("alu error: 'nor' operation: %h - operands: %h %h result: %h expected: %h", op, a, b, r, ~(a | b));
                $finish;
              end
            end

            default : begin
              $display("alu error: operation: %h not mapped!", op);
              $finish;
            end
          endcase

        end
      end
    end
    $display("alu ok: all operations performed with success!");
    $finish; 
  end

  initial begin
    $dumpfile("alu_waves.vcd");
    $dumpvars;
  end 

  alu alu_dut(.r(r), .zero(zer), .ovf(ovf), .op(op), .a(a), .b(b));
endmodule
