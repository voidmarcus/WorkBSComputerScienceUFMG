`ifndef ALU_V
  `define ALU_V

  `include "utils.vh"

  module alu (
      output reg [`CPU_WSIZE-1:0] r,      // alu result
      output zero,                        // zero flag
      output ovf,                         // overflow flag
      input wire [`ALU_OSIZE:0] op,       // operation
      input wire [`CPU_WSIZE-1:0] a, b    // operands
    );

    wire [`CPU_WSIZE-1:0] add_ab, sub_ab;
    wire ovf_add, ovf_sub, slt;

    assign zero = (r == 0);               // if output is zero, set zero flag
    assign add_ab = a + b;                // perform add operation
    assign sub_ab = a - b;                // perform sub operation
    assign ovf_add = (a[`CPU_WSIZE-1] == b[`CPU_WSIZE-1] && add_ab[`CPU_WSIZE-1] != a[`CPU_WSIZE-1]) ? 1 : 0;
    assign ovf_sub = (a[`CPU_WSIZE-1] == b[`CPU_WSIZE-1] && sub_ab[`CPU_WSIZE-1] != a[`CPU_WSIZE-1]) ? 1 : 0;
    assign ovf = (op == `ALU_ADD_OP) ? ovf_add : ovf_sub;
    assign slt = ovf_sub ? ~(a[`CPU_WSIZE-1]) : a[`CPU_WSIZE-1];

    always @(*)  begin
      case(op)
        `ALU_AND_OP: r <= a & b;                          // logical and
        `ALU_ADD_OP: r <= add_ab;                         // add with overflow detection
        `ALU_SLT_OP: r <= {{(`CPU_WSIZE-1){1'b0}}, slt};  // slt: set on less than (compare less than: two's complement) 
        default: r <= 0;
      endcase
    end
  endmodule
`endif // ALU_V