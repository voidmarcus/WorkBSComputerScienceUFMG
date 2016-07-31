module fatorador_engine (
    input clk, reset,
    input start,
    input [15:0]in,
    output wire ready,
    output reg [15:0]out0,
    output reg [15:0]out1,
    output reg [15:0]out2,
    output reg [15:0]out3
  );

  // symbolic state declaration:
  localparam[2:0]
    idle = 2'b01,
    op   = 2'b10;

  // signal declaration:
  reg  [1:0]state_reg, state_next = idle;
  reg  [3:0]idx;
  reg [15:0]i, i_reg, i_next, i_mod, mod_next, primes_buff[3:0];
  // FSMD state and data registers:
  always @(posedge clk) begin
    if(reset) begin
      state_reg = idle;
      i_reg = 0;
    end else begin
      state_reg = state_next;
      i_reg = i_next;
      i_mod = mod_next;
    end
  end

  always @(i_reg or i) begin
    mod_next = i_reg % i;
  end

  // Next-state logic and data path functional unit:
  always @(in or i_reg or i_mod or state_reg) begin
    i_next = i_reg;
    state_next = state_reg;
    mod_next = i_mod;
    case(state_reg)
      idle: begin
        i = 2;
        i_next = in;
        state_next = op;
        for(idx = 0; idx < 4; idx = idx + 1) begin
          primes_buff[idx] = 88;
        end
        idx = 0;
      end

      op: begin
        if(i_next > 1) begin
          if(i_next%i == 0) begin
            i_next = i_next / i;
            if(idx > 0) begin
              if(primes_buff[idx - 1] !=  i) begin
                primes_buff[idx] = i;
                idx = idx + 1;  
              end
            end else begin
              primes_buff[idx] = i;
              idx = idx + 1;
            end
          end else begin
            i = i + 1;
          end
        end else begin
          out0 = primes_buff[0];
          out1 = primes_buff[1];
          out2 = primes_buff[2];
          out3 = primes_buff[3];
          state_next = idle;
        end
      end
    endcase
  end
endmodule
