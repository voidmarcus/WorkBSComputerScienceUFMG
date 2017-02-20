`include "utils.vh"
`timescale 10ns/100ps // `timescale <unit>/<precision>

`define WIDTH   (4)
`define NREG    (3)
`define NOPER   (3)
`define LENGTH  (4)
module writeback_tb;
  integer randval = 0, seed = 7;
  wire [`WIDTH-1:0] r_out;
  reg  [`WIDTH-1:0] data;
  reg  [`NREG-1:0]  reg_addr1, reg_addr2, reg_addr3;
  reg  [`NOPER-1:0] oper;
  reg  sel, write_en, clk;
  reg  [`WIDTH-1:0] regbank [0:`LENGTH-1];
  writeback_top writeback_dut(.r_out(r_out), .reg_addr1(reg_addr1), .reg_addr2(reg_addr2), 
                              .reg_addr3(reg_addr3), .data(data), .oper(oper), .sel(sel), 
                              .write_en(write_en), .clk(clk));

  integer i, j, k;
  initial begin
    $dumpfile("writeback_waves.vcd");
    $dumpvars(0, writeback_tb);
  end 

  initial begin
    clk       = 0;
    write_en  = 0;
    reg_addr1 = 0;
    reg_addr2 = 0;
    reg_addr3 = 0;
    data      = 0;
    sel       = 0;
    oper      = 0;

    i = 0;
    j = 0;
  end

  always begin
    randval = $urandom(seed);
    #1 clk  = ~clk;
  end

  initial begin
    for(i = 0; i < `NREG + 1; i = i + 1) begin
      regbank[i]   = randval[`WIDTH-1:0];
      reg_addr3   = i[`NREG-1:0];
      data        = randval;
      #2 write_en = 1;
      #2 write_en = 0;
    end
     #2 data = 0;
    sel       <= 0;
    data      <= 0;
    reg_addr1 <= 0;
    reg_addr2 <= 0;
    reg_addr3 <= 0;

  end

  always @(posedge clk) begin
    case(oper)
      0: begin // and
      end
    endcase

    if(i == `NREG + 1) begin
      if(j == `NREG + 1) begin

      end
    end
  end

endmodule
