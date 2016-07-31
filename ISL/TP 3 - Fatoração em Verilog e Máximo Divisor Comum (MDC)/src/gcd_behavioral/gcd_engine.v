module gcd_engine (
    input wire clk, reset,
    input wire start,
    input wire [6:0]a_in, b_in,
    output wire ready,
    output reg [6:0]r
  );

  // symbolic state declaration:
  localparam[1:0]
    idle = 2'b01,
    op   = 2'b10;

  // Signal declaration:
  reg [1:0]state_reg, state_next;
  reg [6:0]swap, a_reg, a_next, b_reg, b_next;

  // FSMD state and data registers:
  always @(posedge clk) begin
    if(reset) begin
      state_reg = idle;
      a_reg = 0;
      b_reg = 0;
    end else begin
      state_reg = state_next;
      a_reg = a_next;
      b_reg = b_next;
    end
  end

  // Next-state logic and data path functional unit:
  always @(a_reg or b_reg or state_reg) begin
    a_next = a_reg;
    b_next = b_reg;
    state_next = state_reg;
    case(state_reg)
      idle: begin
        if(start) begin
          a_next = a_in;
          b_next = b_in;
          state_next = op;
        end
      end
      op: begin
        if(a_next < b_next) begin
          swap   = a_next;
          a_next = b_next;
          b_next = swap;
        end else if(b_next != 0) begin
          a_next = a_next - b_next;
        end else begin
          r = a_next;
          state_next = idle;
        end
	   end
    endcase
  end
  
  assign ready = (state_reg == idle);
endmodule
